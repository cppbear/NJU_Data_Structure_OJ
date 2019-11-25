/*
小蓝鲸班级里的座位格局，是和别处不同的，所有的座位被分成了2个小组。班级里一共有N个调皮蛋，编号分别为1~N。
并且某些调皮蛋彼此之间很合得来，如果两个玩得来的调皮蛋凑到了一起，他们会给班级秩序带来很大的破坏，
这里定义一个“破坏值”（正整数）来表示两个调皮蛋凑到一起搞事情造成的破坏力。
唯一能够制止这两个调皮蛋“共同作祟”的方法，就是把他们两人的座位安排在两个不同的小组。
每个星期结束的时候，作为班长的小蓝鲸都会统计一周之内班上发生的所有破坏性事件，并且基于破坏力从高到低排成一份报告。
事务繁忙的班主任只会去看报告中的第一个事件的破坏力，如果破坏力很大，班主任就会认为是小蓝鲸管理安排不当，考虑撤换班长。
小蓝鲸想要保住自己的班长职务，为此他只能向聪明的你求助，让你帮忙重新安排班级里N个调皮蛋的座位，
从而使得一周之内班级里发生的最高破坏力事件的破坏值最低。
假设只要两个合得来的调皮蛋座位分在了同一组，那么这一周之内他们一定会一起策划一场对应破坏值的事件，请你试着求出这一最低破坏值。

注意：本题允许使用sort库函数进行排序。 

输入
    第一行输入两个正整数N和M，分别表示调皮蛋的人数以及会凑到一起搞事情的调皮蛋对数。1≤N≤20000，0≤M≤100000。
    接下来的M行，每行三个正整数xi，yi，pi，表示xi号调皮蛋和yi号调皮蛋凑到一起会策划的破坏力事件的破坏值。
    1≤xi＜yi≤N，1≤pi≤10000，保证每一对调皮蛋组合只出现一次。 

输出
    仅一个整数，表示小蓝鲸最终让班主任看到的最高破坏力事件破坏值的最低值。

提示：关押罪犯 并查集
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Stu
{
    int x = 0, y = 0, val = 0;
};

bool cmp(Stu a, Stu b)
{
    return a.val > b.val;
}

int find(int x, int *a)
{
    if (a[x] == x)
        return x;
    a[x] = find(a[x], a);
    return a[x];
}

bool check(int x, int y, int *a)
{
    x = find(x, a);
    y = find(y, a);
    if (x == y)
        return true;
    return false;
}

void Union(int x, int y, int *a)
{
    x = find(a[x], a);
    y = find(a[y], a);
    a[x] = y;
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    int *a = new int[n + 1];
    int *b = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
        b[i] = 0;
    }
    Stu *stu = new Stu[m + 2];
    for (int i = 1; i <= m; i++)
    {
        cin >> stu[i].x >> stu[i].y >> stu[i].val;
    }
    sort(stu + 1, stu + m + 1, cmp);
    for (i = 1; i <= m + 1; i++)
    {
        if (check(stu[i].x, stu[i].y, a))
        {
            cout << stu[i].val;
            break;
        }
        else
        {
            if (!b[stu[i].x])
                b[stu[i].x] = stu[i].y;
            else
            {
                Union(b[stu[i].x], stu[i].y, a);
            }
            if (!b[stu[i].y])
                b[stu[i].y] = stu[i].x;
            else
            {
                Union(b[stu[i].y], stu[i].x, a);
            }
        }
    }
    system("pause");
    return 0;
}
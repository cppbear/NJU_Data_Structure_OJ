/*
五行中的金、木、水、火、土相生相克。他们的相克关系构成了一个环：金克木，木克土，土克水，水克火，火克金。
现在有N个物体，每个物体分别属于五行中的某一类，编号为0到N-1。
小蓝鲸想和你玩一个游戏：她说M句话，每句话的形式是`kind x y`，你需要再最后告诉她，有几句话是假话。
其中，`x`和`y`表示物体的编号。`kind`是`0`或者`1`，`0`表示`x`和`y`属于五行中的同一类，`1`表示`x`的五行属性克制`y`的五行属性。
如果某句话和前面的话相矛盾，那么这句话就是假话。在之后的判断中，你应该忽略之前已判断为假话的话。

输入
    第一行2个正整数N和M。满足1≤N≤5×104，1≤M≤105。
    接下来有M行，每行都是3个用空格隔开的非负整数，具体含义如上文所描述。

输出
    一行，一个正整数，表示答案。

提示：食物链 并查集
*/
#include <iostream>
using namespace std;

int par[50001];
int rel[50001];

int find(int x)
{
    int temp = x;
    if (x != par[x])
    {
        temp = find(par[x]);
        rel[x] = (rel[x] + rel[par[x]]) % 5;
        par[x] = temp;
    }
    return par[x];
}

void Union(int kind, int x, int y)
{
    int px = find(x);
    int py = find(y);
    par[py] = px;
    rel[py] = (5 + rel[x] - kind - rel[y]) % 5;
}

int main()
{
    int n;
    int m;
    int res = 0;
    int kind, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        rel[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> kind >> x >> y;
        if (x > n || y > n || (kind == 1 && x == y))
        {
            res++;
            continue;
        }
        int px = find(x);
        int py = find(y);
        if (px == py)
        {
            if (((rel[x] - rel[y] + 5) % 5) != kind)
                res++;
        }
        else
        {
            Union(kind, x, y);
        }
    }
    cout << res;
    system("pause");
    return 0;
}
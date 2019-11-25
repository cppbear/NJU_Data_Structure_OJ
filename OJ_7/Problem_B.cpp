/*
在叠罗汉表演中，若演员A的身高和体重都小于演员B的身高和体重，那么演员A就可以位于演员B的上方。现在有N名演员，小蓝鲸想知道叠罗汉的高度最高是多少？

输入
    第一行：N，表示演员的数量（1 ≤ N ≤ 10000）
    第二行~第N+1行：两个正整数，表示每个演员的身高和体重，用空格隔开。

输出
    一个整数，表示叠罗汉的最大高度。
*/
#include <iostream>
using namespace std;

struct Actor
{
    int height;
    int weight;
};

void sort(Actor *a, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j].height < a[min].height)
                min = j;
            else if (a[j].height == a[min].height && a[j].weight < a[min].weight)
                min = j;
        }
        if (min != i)
        {
            Actor temp;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int length(Actor *a, int *dp, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(a[j].weight < a[i].weight && a[j].height < a[i].height)
            {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
        res = res > dp[i] ? res : dp[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    Actor *a = new Actor[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 0; i < n; i++)
    {
        Actor temp;
        cin >> temp.height >> temp.weight;
        a[i] = temp;
    }
    sort(a, n);
    /*
    for (int i = 0; i < n; i++)
        cout << a[i].height << '\t';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i].weight << '\t';
    cout << endl;
    */
    cout << length(a, dp, n);
    system("pause");
    return 0;
}
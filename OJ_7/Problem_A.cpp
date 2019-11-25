/*
小蓝鲸所在的大学有四个食堂A、B、C、D，每个食堂吃饭的人数都有N种可能，聪明的小蓝鲸想知道有多少种组合情况，可以使得四个食堂的总人数刚好是10000。

输入
    第一行：N（0 ≤ N ≤ 500）
    第二行~第五行，每行有N个正整数，正整数之间用空格隔开。（正整数在int范围内）

输出
    一个整数，表示可能的组合个数。若没有情况满足，则输出0。
*/
#include <iostream>
using namespace std;

int x[100000] = {}, y[100000] = {};

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];
    int *d = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            x[a[i] + b[j]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            y[c[i] + d[j]]++;
    }
    int res = 0;
    for (int i = 0; i < 10001; i++)
    {
        res += x[i] * y[10000 - i];
    }
    cout << res;
    system("pause");
    return 0;
}
/*
设有两个整数类型的顺序表A(有m个元素）和B(有n个元素），其元素均以从小到大的升序排列。
试将这两个顺序表合并成一个顺序表C，要求C的元素也以从小到大的升序排列。（请尽量简化算法复杂度）（m和n不为0）
输入
输入多组数据，每组格式如下
m n
A
B
其中m,n 分别表示顺序表A和B的元素个数，A、B为顺序表元素
输出
顺序表C的从小到大的输出。（请注意输出，行末无空格）
*/
#include<iostream>
using namespace std;

void My_sort(int *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = p[i];
        for (int j = i + 1; j < n; j++)
        {
            if (p[j] < min)
            {
                int temp = p[j];
                p[j] = p[i];
                p[i] = temp;
                min = p[i];
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
        cout << p[i] << " ";
    cout << p[n - 1] << endl;
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        int *c = new int[m + n];
        for (int i = 0; i < m; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> c[i + m];
        My_sort(c, m + n);
    }
    return 0;
}
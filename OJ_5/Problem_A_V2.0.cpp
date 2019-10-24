/*
现有两个字符串S和W，要求在S中找到跟W匹配的子串，并依次输出匹配的子串的起始下标（从零开始）。如果没有匹配的子串，则输出false。

输入
    输入数据包括两行，第一行为字符串S，第二行为字符串W。字符串长度满足1≤len(W)≤len(S)≤100000。

输出
    输出仅一行，为所有匹配位置的起始坐标，若没有找到匹配的起始点，则输出false。

KMP算法
*/

#include <iostream>
#include <string>
using namespace std;

void GetNext(int *next, string p, int n)
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < n)
    {
        if (k == -1 || p[j] == p[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main()
{
    string target;
    string pattern;
    getline(cin, target);
    cin >> pattern;
    int res[100002] = {0};
    int m = target.length() - 1;
    //int m = target.length();
    int n = pattern.length();
    int *next = new int[n + 1];
    GetNext(next, pattern, n);

    int posp = 0;
    int post = 0;
    int k = 0;
    while (post < m)
    {
        while (posp != -1 && (posp == n || target[post] != pattern[posp]))
            posp = next[posp];
        post++;
        posp++;
        if (posp == n)
        {
            res[k] = post - n;
            k++;
        }
    }

    if (k == 0)
    {
        cout << "false";
    }
    else
    {
        for (int i = 0; i < k; i++)
            cout << res[i] << " ";
    }
    system("pause");
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

string multiply(string a, string b)
{
    string res;
    int origina[10000] = {}, originb[10000] = {}, temp[10000] = {};
    for (int i = 0; i < a.length(); i++)
        origina[a.length() - i] = a[i] - '0';
    for (int i = 0; i < b.length(); i++)
        originb[b.length() - i] = b[i] - '0';
    for (int i = 1; i <= a.length(); i++)
    {
        int x = 0;
        for (int j = 1; j <= b.length(); j++)
        {
            temp[i + j - 1] = origina[i] * originb[j] + x + temp[i + j - 1];
            x = temp[i + j - 1] / 10;
            temp[i + j - 1] %= 10;
        }
        temp[b.length() + i] = x;
    }
    int all = a.length() + b.length();
    while (all > 0)
    {
        if (temp[all] == 0)
            all--;
        else
            break;
    }
    for (int i = all; i > 0; i--)
        res += temp[i] + '0';
    return res;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string origin[10];
        for (int i = 0; i < n; i++)
            cin >> origin[i];
        string res = origin[0];
        for (int i = 1; i < n; i++)
            res = multiply(res, origin[i]);
        cout << res << endl;
    }
    return 0;
}

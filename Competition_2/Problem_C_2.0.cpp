#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        a.push_back(temp);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        a[n - 1][i] += a[n - 1][i + 1];
        a[i][n - 1] += a[i + 1][n - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        a[i][i] += a[i][i + 1] < a[i + 1][i] ? a[i][i + 1] : a[i + 1][i];
        for (int j = i - 1; j >= 0; j--)
        {
            a[i][j] += a[i][j + 1] < a[i + 1][j] ? a[i][j + 1] : a[i + 1][j];
            a[j][i] += a[j][i + 1] < a[j + 1][i] ? a[j][i + 1] : a[j + 1][i];
        }
    }
    cout << a[0][0];
    system("pause");
    return 0;
}
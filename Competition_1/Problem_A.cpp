#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

void round(vector<vector<int>> a, int m, int n)
{
    int count = 0;
    int flag = 0;
    int t = ceil((double)m / 2) > ceil((double)n / 2) ? ceil((double)m / 2) : ceil((double)n / 2);
    for (int j = 0; j < t; j++)
    {
        for (int i = 0 + j; i < n - j; i++)
            {
                cout << a[0 + j][i] << " ";
                count++;
                if (count>=m*n)
                    return;
            }
        for (int i = 1 + j; i < m - j; i++)
            {
                cout << a[i][n - 1 - j] << " ";
                count++;
                if (count >= m * n)
                    return;
            }
        for (int i = n - 2 - j; i >= 0 + j; i--)
            {
                cout << a[m - 1 - j][i] << " ";
                count++;
                if (count >= m * n)
                    return;
            }
        for (int i = m - 2 - j; i > 0 + j; i--)
            {
                cout << a[i][0 + j] << " ";
                count++;
                if (count >= m * n)
                    return;
            }
    }
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>> mat;
        for (int i = 0; i < m; i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                int a;
                cin >> a;
                temp.push_back(a);
            }
            mat.push_back(temp);
        }
        round(mat, m, n);
        cout << endl;
    }
    system("pause");
    return 0;
}
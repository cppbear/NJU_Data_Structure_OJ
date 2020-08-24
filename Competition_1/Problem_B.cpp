#include <iostream>
#include <vector>

using namespace std;

bool success(int *a, int *sort, vector<int> b, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m && sort[j] != -1; j++)
        {
            if (sort[j] != a[i])
            {
                b.push_back(j);
            }
            else
            {
                bool flag=false;
                int count = -1;
                for (int t = 0; t < b.size();t++)
                {
                    if (b[t]==a[i])
                    {
                        flag = true;
                        count = t;
                    }
                }
                if(flag && count!=0)
                    return false;
                else if (flag&&count==0)
                {
                    for (int s = 0; s < b.size() - 1;s++)
                    {
                        b[s] = b[s + 1];
                    }
                    b.pop_back();
                    for (int s = 0; s < n - 1;s++)
                        sort[s] = sort[s + 1];
                    sort[n - 1] = -1;
                }
                break;
            }
        }
        if (b.size() == m && a[i] > m)
            return false;
        else if (b.size() == m && a[i] == m)
        {
            for (int p = m; p < n - 1;p++)
                sort[p] = sort[p + 1];
            sort[n - 1] = -1;
        }
        
    }
    return true;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int *a = new int[n];
        int *sort = new int[n];
        for (int i = 0; i < n; i++)
            sort[i] = i;
        vector<int> b;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            a[i] = t;
        }
        if (success(a, sort, b, n, m))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
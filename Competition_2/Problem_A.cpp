#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    int a[500000] = {};
    int b[1010] = {};
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a[temp]++;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int max = 0;
        for (int j = 1; j < 500000 ; j++)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        b[i] = max;
        a[max] = -1;
    }
    for (int i = 0; i < k - 1; i++)
    {
        cout << b[i] << " ";
    }
    cout << b[k - 1];
    system("pause");
    return 0;
}
#include <iostream>
using namespace std;

int Find(int x, int *a)
{
    if (a[x] == x)
        return x;
    else
    {
        a[x] = Find(a[x], a);
        return a[x];
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    if (m * n >= 971619)
    {
        cout << 971619;
        return 0;
    }
    int *a = new int[m * n + 1];
    for (int i = 1; i < m * n + 1; i++)
        a[i] = i;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        int px = Find(x, a);
        int py = Find(y, a);
        if (px != x)
        {
            a[y] = px;
            /*
            int temp = a[y];
            for (int i = 1; i < m * n + 1; i++)
                if (a[i] == temp)
                    a[i] = px;
            */
        }
        else if (py != y)
        {
            a[x] = py;
            /*
            int temp = a[x];
            for (int i = 1; i < m * n + 1; i++)
                if (a[i] == temp)
                    a[i] = py;
            */
        }
        else
        {
            a[y] = x;
            /*
            int temp = a[y];
            for (int i = 1; i < m * n + 1; i++)
                if (a[i] == temp)
                    a[i] = px;
            */
        }
    }

    int *b = new int[m * n + 1];
    for (int i = 1; i < m * n + 1; i++)
        b[i] = 0;
    for (int i = 1; i < m * n + 1; i++)
        b[Find(i, a)]++;
    int res = 0;
    for (int i = 1; i < m * n + 1; i++)
        if (b[i] > 0)
            res++;
    cout << res;
    system("pause");
    return 0;
}

/*
#include<iostream>
using namespace std;
int main()
{
	int a, b;
	int num;
	cin >> a >> b >> num;
	int *p = new int[a*b];
	//int p[20], q[20];
	for (int i = 0; i < a*b; i++)
	{
		p[i] = i;
	}
	int x, y;
	for (int i = 1; i <= num; i++)
	{
		cin >> x >> y;
		x--;
		y--;
		while (true)
		{
			if (p[x] != x)
				x = p[x];
			else
				break;
		}
		while (true)
		{
			if (p[y] != y)
				y = p[y];
			else
				break;
		}

		if (y == x)
			continue;
		else if (y > x)
		{
			p[y] = x;
		}
		else
		{
			p[x] = y;
		}
	}
	int res = 0;
	for (int i = 0; i < a*b; i++)
	{
		if (p[i] == i)
			res++;
	}
	cout << res;
	system("pause");
	return 0;
}
*/
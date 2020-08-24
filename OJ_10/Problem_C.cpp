#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int length[26][5001];

struct edge
{
    int ter, next, len;
};

bool HaveCircle(int n, edge e[], vector<int> &topo, int *in, int h[]);
void AddEdge(int x, int y, edge e[], int &count, int in[], int *h);
int FindMax(edge e[], int n, int *gold, vector<int> topo, int *h);

int main()
{
    vector<int> topo;
    int count = 0;
    memset(length, 0, sizeof(length));
    int n, m;
    cin >> n >> m;
    int inde[1001];
    for (int i = 0; i < n + 3; i++)
        inde[i] = 0;
    int head[5001];
    memset(head, -1, sizeof(head));
    edge e[5001];
    int gold[5001];
    string x;
    cin >> x;
    for (int i = 1; i <= n; i++)
    {
        gold[i] = x[i - 1] - 'a' + 1;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        AddEdge(u, v, e, count, inde, head);
    }
    for (int i = 1; i <= n; i++)
    {
        AddEdge(i, n + 1, e, count, inde, head);
    }

    if (HaveCircle(n, e, topo, inde, head))
    {
        cout << "-1";
    }
    else
    {
        cout << FindMax(e, n, gold, topo, head);
    }
    system("pause");
    return 0;
}

bool HaveCircle(int n, edge e[], vector<int> &topo, int *in, int h[])
{
    vector<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push_back(i);
        }
    }
    for (int i = 0; i < q.size(); i++)
    {
        topo.push_back(q[i]);
        for (int j = h[q[i]]; j >= 0; j = e[j].next)
        {
            int v = e[j].ter;
            if (in[v] - 1 == 0)
            {
                q.push_back(v);
            }
            in[v] = in[v] - 1;
        }
    }

    if (q.size() == n + 1)
        return 0;
    else
        return 1;
}

void AddEdge(int x, int y, edge e[], int &count, int in[], int *h)
{
    in[y]++;
    e[count].ter = y;
    e[count].next = h[x];
    e[count].len = 0;
    h[x] = count++;
}

int FindMax(edge e[], int n, int *gold, vector<int> topo, int *h)
{
    int MaxNumber = -1;

    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < topo.size(); i++)
        {
            int sorti = topo[i];
            for (int j = h[sorti]; j >= 0; j = e[j].next)
            {
                int tmphead = e[j].ter;

                int tmp = length[k][sorti] + (int)(gold[sorti] == (k + 1));
                if (tmp > length[k][tmphead])
                    length[k][tmphead] = tmp;
            }
        }

        for (int i = 1; i <= n + 1; i++)
        {
            if (length[k][i] > MaxNumber)
                MaxNumber = length[k][i];
        }
    }
    return MaxNumber;
}
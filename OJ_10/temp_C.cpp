#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#define maxm 5005
#define maxn 1005
using namespace std;

class FindGold
{
private:
    int n, m;
    int Gold[maxm];
    vector<int> topo;
    int lenght[26][maxm];
    int countNow;
    int InDegree[maxn];
    int head[maxm];

    struct edge
    {
        int terminal, next, len;
    };
    edge e[maxm];

public:
    FindGold()
    {
        countNow = 0;
        for (int i = 0; i < maxn; i++)
            InDegree[i] = 0;
        memset(lenght, 0, sizeof(lenght));
        memset(head, -1, sizeof(head));
    }
    bool HaveCircle()
    {
        vector<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (InDegree[i] == 0)
            {
                q.push_back(i);
            }
        }
        for (int i = 0; i < q.size(); i++)
        {
            topo.push_back(q[i]);
            for (int j = head[q[i]]; j >= 0; j = e[j].next)
            {
                int v = e[j].terminal;
                if (--InDegree[v] == 0)
                    q.push_back(v);
            }
        }

        if (q.size() == n + 1)
            return 0;
        else
            return 1;
    }

    void AddEdge(int x, int y)
    {
        InDegree[y]++;
        e[countNow].terminal = y;
        e[countNow].next = head[x];
        e[countNow].len = 0;
        head[x] = countNow++;
    }

    int FindMax()
    {
        int MaxNumber = -1;

        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < topo.size(); i++)
            {
                int sorti = topo[i];
                for (int j = head[sorti]; j >= 0; j = e[j].next)
                {
                    int tmphead = e[j].terminal;

                    int tmp = lenght[k][sorti] + (int)(Gold[sorti] == (k + 1));
                    if (tmp > lenght[k][tmphead])
                        lenght[k][tmphead] = tmp;
                }
            }

            for (int i = 1; i <= n + 1; i++)
            {
                if (lenght[k][i] > MaxNumber)
                    MaxNumber = lenght[k][i];
            }
        }
        return MaxNumber;
    }

    void Run()
    {
        cin >> n >> m;
        string x;
        cin >> x;
        for (int i = 1; i <= n; i++)
        {
            Gold[i] = x[i - 1] - 'a' + 1;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            AddEdge(u, v);
        }
        for (int i = 1; i <= n; i++)
        {
            AddEdge(i, n + 1);
        }

        if (HaveCircle())
        {
            cout << "-1";
        }
        else
        {
            cout << FindMax();
        }
    }
};

int main()
{

    FindGold FD;
    FD.Run();
    system("pause");
    return 0;
}
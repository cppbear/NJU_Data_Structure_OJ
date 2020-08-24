#include <iostream>
#include <vector>
#include <queue>
//#define INT_MAX 2147483647
using namespace std;

inline int min(int x, int y)
{
    return (x < y) ? x : y;
}

struct edge
{
    int len;
    int ter;
    int color;
    int next;
};

struct SE
{
    int val;
    int v;
    int color;
};

struct cmp
{
    bool operator()(SE a, SE b)
    {
        return a.val > b.val;
    }
};
void AddEdge(edge e[], int u, int v, int w, int c, int *h, int &count);
void ShortestPath(edge e[], int n, int dis[2][1005], int *h, priority_queue<SE, vector<SE>, cmp> pri_queue);

int main()
{
    bool t = 0;
    bool f = 0;
    priority_queue<SE, vector<SE>, cmp> pri_queue;
    int n, m;
    cin >> n >> m;
    int head[m + 1];
    edge e[m + 1];
    for (int i = 0; i < m; i++)
    {
        e[i].next = -1;
        head[i] = -1;
    }
    int dis[2][1005];
    int CountNow = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        AddEdge(e, a, b, c, d, head, CountNow);
        if (a == 0 && d == 1)
            t = 1;
        if (a == 0 && d == 2)
            f = 1;
    }
    ShortestPath(e, n, dis, head, pri_queue);
    for (int i = 0; i < n; i++)
    {
        int m = min(dis[0][i], dis[1][i]);
        if (m == INT_MAX)
            cout << "-1";
        else
            cout << m;

        if (i + 1 < n)
            cout << " ";
    }
    system("pause");
    return 0;
}

void ShortestPath(edge e[], int n, int dis[2][1005], int *h, priority_queue<SE, vector<SE>, cmp> pri_queue)
{
    for (int i = 0; i < n; i++)
    {
        dis[0][i] = INT_MAX;
        dis[1][i] = INT_MAX;
    }
    dis[0][0] = 0;
    dis[1][0] = 0;

    SE temp;
    temp.val = temp.v = temp.color = 0;
    pri_queue.push(temp);

    temp.color = 1;
    pri_queue.push(temp);

    while (!pri_queue.empty())
    {
        SE Head = pri_queue.top();
        pri_queue.pop();
        int Nowlen = Head.val;
        int Nowv = Head.v;
        int Nowc = Head.color;
        if (dis[Nowc][Nowv] < Nowlen)
            continue;
        for (int i = h[Nowv]; i >= 0; i = e[i].next)
        {
            edge Nowedge = e[i];
            if ((Nowedge.color ^ Nowc) && dis[Nowedge.color][Nowedge.ter] > dis[Nowc][Nowv] + Nowedge.len)
            {
                dis[Nowedge.color][Nowedge.ter] = dis[Nowc][Nowv] + Nowedge.len;
                SE NewEdge;
                NewEdge.val = dis[Nowedge.color][Nowedge.ter];
                NewEdge.v = Nowedge.ter;
                NewEdge.color = Nowedge.color;
                pri_queue.push(NewEdge);
            }
        }
    }
}

void AddEdge(edge e[], int u, int v, int w, int c, int *h, int &count)
{
    e[count].ter = v;
    e[count].len = w;
    e[count].next = h[u];
    e[count].color = c - 1;
    h[u] = count++;
}

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
};

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Node *a = new Node[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = 0;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        b[y]++;
        Node *p = new Node;
        p->val = y;
        Node *q;
        for (q = &a[x]; q->next; q = q->next)
            ;
        q->next = p;
    }
    priority_queue<int, vector<int>, cmp> temp;
    for (int i = 0; i < n; i++)
        if (!b[i])
            temp.push(i);
    while (!temp.empty())
    {
        
        int k = temp.top();
        temp.pop();
        cout << k << " ";
        for (Node *p = a[k].next; p; p = p->next)
        {
            b[p->val]--;
            if (!b[p->val])
                temp.push(p->val);
        }
    }
    system("pause");
    return 0;
}
/*
现在有⼀组链表存储的数据，我们想对链表中的数据按照⼤小划分成两个部分。给定⼀个划分值x，所有⼤于或者等于x的节点都放到所有小于x的节点的后⾯。
同时保证每个节点的初始相对位置不变。输出重新排列之后的链表。
算法除去输入数据的额外空间复杂度应为O(1)，时间复杂度应为O(nodes)，nodes为节点总数。
输入
第⼀⾏为链表⻓度nodes，第⼆⾏为划分值x，第三⾏为链表中每个节点的数据，每两个数据之间⽤空格隔开。链表中的数据都为 int 类型。
输出
输出重新排列之后的链表，每两个数据之间⽤空格隔开(包括⾏尾的空格)。
*/
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

void division(Node *head, int threshold)
{
    Node *p = head;
    while (p->next != NULL && p->next->val < threshold)
        p = p->next;
    if (p->next == NULL || p->next->next == NULL)
        return;
    else
    {
        Node *q = p->next;
        while (q != NULL && q->next != NULL)
        {
            if (q->next->val < threshold)
            {
                Node *t = q->next;
                q->next = t->next;
                t->next = p->next;
                p->next = t;
                p = p->next;
            }
            else
            {
                q = q->next;
            }
        }
    }
}

int main()
{
    int n, threshold;
    while (cin >> n >> threshold)
    {
        Node *head = new Node;
        Node *tail = head;
        for (int i = 0; i < n; i++)
        {
            Node *p = new Node;
            int temp;
            cin >> temp;
            p->val = temp;
            p->next = NULL;
            tail->next = p;
            tail = tail->next;
        }
        division(head, threshold);
        for (Node *q = head->next; q != NULL; q = q->next)
        {
            cout << q->val << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
/*
班主任需要从班级⾥选举⼀位同学作为班⻓，并通过以下⽅式进⾏选择。将所有N位同学按照从1⾄N进⾏编号，并按照顺时针围成⼀个圈(N号在1号左侧)，
⼀位教师从1开始顺时针⽅向，清点⾄第K个同学；另⼀位教师从N开始逆时针⽅向，清点⾄第M个同学。若这两个同学是同⼀个学⽣，则此⼈为选定的班⻓；
若不是同⼀个学⽣，则将其从队列中去除，并从下⼀个同学开始继续清点，直到选出班⻓或者 队列中没有同学位置。请你利⽤循环双向链表编写程序，解决这⼀问题。
输入
⼀⾏，三个数字 N,K,M，以空格隔开。（0<K , M<N<100）
输出
⼀⾏，每⼀次清点选出的同学原始编号，以空格分开，⾏末⽆空格。
注意，若两个学⽣不同，每组先输出顺时针选择结果，后输出逆时针结果。
*/
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *pre;
    Node *next;
};

void findTheMonitor(Node *head, int k, int m)
{
    Node *p = head->next;
    Node *q = head->pre;
    while (head->next != head)
    {
        for (int i = 0; i < k - 1; i++)
        {
            if (p->next != head)
                p = p->next;
            else
            {
                p = p->next->next;
            }
        }
        for (int j = 0; j < m - 1; j++)
        {
            if (q->pre != head)
                q = q->pre;
            else
            {
                q = q->pre->pre;
            }
        }
        if (p == q)
        {
            cout << p->val << endl;
            return;
        }
        else
        {
            cout << p->val << " " << q->val << " ";
            if (p->next == q)
            {
                p = q->next;
                q = q->pre->pre;
                p->pre = q;
                q->next = p;
                if (p == head)
                {
                    p = p->next;
                }
                if (q == head)
                {
                    q = q->pre;
                }
            }
            else if (p->pre == q)
            {
                p = p->next;
                q = q->pre;
                p->pre = q;
                q->next = p;
                if (p == head)
                {
                    p = p->next;
                }
                if (q == head)
                {
                    q = q->pre;
                }
            }
            else
            {
                p = p->next;
                q = q->pre;
                p->pre = p->pre->pre;
                p->pre->next = p;
                q->next = q->next->next;
                q->next->pre = q;
                if (p == head)
                {
                    p = p->next;
                }
                if (q == head)
                {
                    q = q->pre;
                }
            }
        }
        
    }
}

int main()
{
    int n, k, m;
    while (cin >> n >> k >> m)
    {
        Node *head = new Node;
        Node *tail = head;
        for (int i = 0; i < n; i++)
        {
            Node *p = new Node;
            p->val = i + 1;
            p->pre = tail;
            tail->next = p;
            tail = tail->next;
        }
        head->pre = tail;
        tail->next = head;
        findTheMonitor(head, k, m);
    }
    return 0;
}
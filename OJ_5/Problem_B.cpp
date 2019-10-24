/*
在二叉树家族中，定义“堂兄弟”如下：如果两个节点的深度相同，但是父节点不同，则它们是一对堂兄弟。现有一个二叉树家族，其中每一个节点的值都不同。
输入小蓝鲸的节点值x和一位家族成员的节点值y，判断这位家族成员是否为小蓝鲸的堂兄弟。

注意：本题需要使用二叉树数据结构完成。

输入
    第一行：二叉树节点值的顺序表示，用空格隔开。若为空节点，则为‘#’。1≤节点数≤100
    第二行：小蓝鲸的节点值。
    第三行：家族成员的节点值。

输出
    true或false。true表示该家族成员是小蓝鲸的堂兄弟，false表示该家族成员不是小蓝鲸的堂兄弟。行末无多余空格换行符。
*/

#include <iostream>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *LeftChild = NULL;
    TreeNode *RightChild = NULL;
    TreeNode *parent = NULL;
};

struct Number
{
    int num;
    Number *next = NULL;
};

void IsCousin(TreeNode *me, TreeNode *cousin, TreeNode *root)
{
    
    if (!me || !cousin || me->parent == cousin->parent)
        cout << "false";
    else
    {
        int MyDepth = 0, CousinDepth = 0;
        for (TreeNode *p = me; p; p = p->parent)
            MyDepth++;
        for (TreeNode *p = cousin; p; p = p->parent)
            CousinDepth++;
        if (MyDepth == CousinDepth)
            cout << "true";
        else
        {
            cout << "false";
        }
    }
}

int main()
{
    string node;
    int m, n;
    getline(cin, node);
    //cout << node << endl;
    cin >> m >> n;
    //cout << m << endl << n << endl;
    TreeNode *queue[200];
    int front = 0, rear = 0;
    Number *head = new Number;
    Number *tail = head;
    for (int i = 0; i < node.length(); i++)
    {
        if (node[i] == ' ')
            continue;
        else if (node[i] == '#')
        {
            Number *p = new Number;
            p->num = -1;
            tail->next = p;
            tail = tail->next;
        }
        else
        {
            int j = 1;
            while (i + j < node.length() && node[i + j] != ' ')
                j++;
            string t = node.substr(i, j);
            int temp = atoi(t.c_str());
            Number *p = new Number;
            p->num = temp;
            tail->next = p;
            tail = tail->next;
            i += j - 1;
        }
    }
    //for (Number *p = head->next; p; p = p->next)
    //    cout << p->num << ' ';
    TreeNode *root = new TreeNode;
    root->val = head->next->num;
    queue[front] = root;
    rear++;
    TreeNode *me = new TreeNode, *cousin = new TreeNode;
    if (root->val == m)
        me = root;
    if (root->val == n)
        cousin = root;
    for (Number *p = head->next->next; p; p = p->next->next)
    {
            TreeNode *q = new TreeNode;
            q->val = p->num;
            queue[front]->LeftChild = q;
            q->parent = queue[front];
            queue[rear] = q;
            rear++;
            if (q->val == m)
                me = q;
            if (q->val == n)
                cousin = q;

        if (p->next)
        {
            TreeNode *q = new TreeNode;
            q->val = p->next->num;
            queue[front]->RightChild = q;
            q->parent = queue[front];
            queue[rear] = q;
            rear++;
            if (q->val == m)
                me = q;
            if (q->val == n)
                cousin = q;
        }
        front++;
        if (!p->next)
            break;
    }
    IsCousin(me, cousin, root);
    system("pause");
    return 0;
}
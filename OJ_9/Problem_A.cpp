#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    int bf = 0;
    TreeNode *LeftChild = NULL;
    TreeNode *RightChild = NULL;
};

void RotateL(TreeNode *&node)
{
    TreeNode *subL = node;
    node = subL->RightChild;
    subL->RightChild = node->LeftChild;
    node->LeftChild = subL;
    node->bf = subL->bf = 0;
}

void RotateR(TreeNode *&node)
{
    TreeNode *subR = node;
    node = subR->LeftChild;
    subR->LeftChild = node->RightChild;
    node->RightChild = subR;
    node->bf = subR->bf = 0;
}

void RotateLR(TreeNode *&node)
{
    TreeNode *subR = node, *subL = subR->LeftChild;
    node = subL->RightChild;
    subL->RightChild = node->LeftChild;
    node->LeftChild = subL;
    if (node->bf <= 0)
        subL->bf = 0;
    else
    {
        subL->bf = -1;
    }
    subR->LeftChild = node->RightChild;
    node->RightChild = subR;
    if (node->bf == -1)
        subR->bf = 1;
    else
    {
        subR->bf = 0;
    }
    node->bf = 0;
}

void RotateRL(TreeNode *&node)
{
    TreeNode *subL = node, *subR = subL->RightChild;
    node = subR->LeftChild;
    subR->LeftChild = node->RightChild;
    node->RightChild = subR;
    if (node->bf >= 0)
        subR->bf = 0;
    else
    {
        subR->bf = 1;
    }
    subL->RightChild = node->LeftChild;
    node->LeftChild = subL;
    if (node->bf == 1)
        subL->bf = -1;
    else
    {
        subL->bf = 0;
    }
    node->bf = 0;
}

void OutPut(TreeNode *node)
{
    if (!node)
        return;
    cout << node->val << ' ';
    OutPut(node->LeftChild);
    OutPut(node->RightChild);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    TreeNode *root = new TreeNode;
    root->val = a[0];
    for (int i = 1; i < n; i++)
    {
        stack<TreeNode *> parent;
        TreeNode *p = new TreeNode;
        p->val = a[i];
        TreeNode *q = root;
        TreeNode *pr = NULL;
        while (q)
        {
            parent.push(q);
            pr = q;
            if (p->val < q->val)
                q = q->LeftChild;
            else
            {
                q = q->RightChild;
            }
        }
        if (p->val < pr->val)
            pr->LeftChild = p;
        else
        {
            pr->RightChild = p;
        }
        while (!parent.empty())
        {
            pr = parent.top();
            parent.pop();
            if (p == pr->LeftChild)
                pr->bf--;
            else
            {
                pr->bf++;
            }
            if (pr->bf == 0)
                break;
            if (pr->bf == 1 || pr->bf == -1)
            {
                p = pr;
            }
            else
            {
                int d = (pr->bf < 0) ? -1 : 1;
                if (p->bf == d)
                {
                    if (d == -1)
                        RotateR(pr);
                    else
                    {
                        RotateL(pr);
                    }
                }
                else
                {
                    if (d == -1)
                        RotateLR(pr);
                    else
                    {
                        RotateRL(pr);
                    }
                }
                break;
            }
        }
        if (parent.empty())
            root = pr;
        else
        {
            q = parent.top();
            if (q->val > pr->val)
                q->LeftChild = pr;
            else
            {
                q->RightChild = pr;
            }
        }
    }
    OutPut(root);
    system("pause");
    return 0;
}
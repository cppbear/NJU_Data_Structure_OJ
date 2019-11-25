/*
小蓝鲸在学习二叉搜索树，他完成作业时根据题目要求构建出了二叉搜索树，但小蓝鲸室友趁小蓝鲸不注意修改了小蓝鲸的搜索树：
将其中的两个节点交换了位置，小蓝鲸想请你帮助他找出这两个交换的节点，并恢复二叉搜索树。

输入
    第一行输入数字N ，表示二叉搜索树的节点个数（不包含空节点，总结点数为 2N+1）。（1≤N≤1.5×105）
    第二行输入 2N+1个数字，二叉搜索树的前序表示，空节点用 -1 表示，没有相同节点。

输出
    交换的两个节点数值，从小到大排列
*/
#include <iostream>
using namespace std;

struct TreeNode
{
    int val = 0;
    TreeNode *LeftChild = NULL;
    TreeNode *RightChild = NULL;
};

TreeNode *build()
{
    int temp;
    cin >> temp;
    if (temp == -1)
        return NULL;
    else
    {
        TreeNode *p = new TreeNode;
        p->val = temp;
        p->LeftChild = build();
        p->RightChild = build();
        return p;
    }
}

void find(int *a, int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            continue;
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (min != i)
        {
            cout << a[min] << ' ' << a[i];
            return;
        }
    }
}

void Output(TreeNode *node, int *a, int &i)
{
    if (!node)
        return;
    else
    {
        Output(node->LeftChild, a, i);
        a[i] = node->val;
        i++;
        Output(node->RightChild, a, i);
    }
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode;
    root = build();
    int *orign = new int[n];
    int k = 0;
    Output(root, orign, k);
    find(orign, n);
    system("pause");
    return 0;
}
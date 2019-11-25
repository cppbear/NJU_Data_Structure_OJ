/*
小蓝鲸们被派遣去守卫宝藏。宝藏分布呈一个二叉树，二叉树的每个节点都是一个藏宝的地点。
一位小蓝鲸站在一个节点可以同时守卫这个节点和与这个节点直接相邻的所有节点。现在想知道至少要派遣多少位小蓝鲸才能守卫所有的宝藏。

输入
    第一行，表示二叉树的前序遍历序列。
    输入中的 0 表示有节点，输入中的 -1 表示空节点。（0≤二叉树中非空节点个数≤500 ） 

输出
    一行一个整数，表示至少需要的小蓝鲸的人数。
*/
#include <iostream>
using namespace std;

int res = 0;

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
        p->LeftChild = build();
        p->RightChild = build();
        return p;
    }
}

int Guard(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int left = Guard(node->LeftChild);
    int right = Guard(node->RightChild);

    if (left + right == 0)
        return 1;
    else if (left == 1 || right == 1)
    {
        res++;
        return 2;
    }
    else
        return 0;
}

int main()
{
    TreeNode *root = new TreeNode;
    TreeNode *fake = new TreeNode;
    root = build();
    fake->LeftChild = root;
    Guard(fake);
    cout << res;
    system("pause");
    return 0;
}
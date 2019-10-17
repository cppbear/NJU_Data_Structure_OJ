/*
对于一个完全二叉树，每个节点用来存储节点权重。我们定义，其中任意子树的重量为该子树内所有节点的权重和（包含该子树根节点的权重）。
小蓝鲸麻烦你帮忙对该二叉树进行调整，对于任意节点，若左子树根节点的重量大于右子树根节点的重量（空子树的重量为0），则调换左右子树。
输入
    第一行有一个数字 N， 表示完全二叉树的节点个数。
    第二行为 N 个正整数 ai > 0，表示完全二叉树的数组存储表示。（N≤100000）
输出
    输出调整后的二叉树中序遍历结果，以空格分隔。
*/
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode
{
    int value;
    int weig;
    TreeNode *leftChild = NULL;
    TreeNode *rightChild = NULL;
};

void GetWeight(int *wei, int h, int n)
{
    for (int i = h - 2; i >= 0; i--)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            int left = pow(2, i + 1) - 1 + 2 * j;
            int right = pow(2, i + 1) + 2 * j;
            if (left < n)
                wei[(int)pow(2, i) - 1 + j] += wei[left];
            if (right < n)
                wei[(int)pow(2, i) - 1 + j] += wei[right];
        }
    }
}

void Reverse(TreeNode *node)
{
    if (node->leftChild == NULL && node->rightChild == NULL)
        return;
    else if (node->leftChild != NULL && node->rightChild == NULL)
    {
        node->rightChild = node->leftChild;
        node->leftChild = NULL;
        Reverse(node->rightChild);
    }
    else if (node->leftChild == NULL && node->rightChild != NULL)
        Reverse(node->rightChild);
    else if (node->leftChild->weig > node->rightChild->weig)
    {
        TreeNode *temp = new TreeNode;
        temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;
        Reverse(node->leftChild);
        Reverse(node->rightChild);
    }
    else
    {
        Reverse(node->leftChild);
        Reverse(node->rightChild);
    }
}

void OutPut(TreeNode *node)
{
    if (node != NULL)
    {
        OutPut(node->leftChild);
        cout << node->value << " ";
        OutPut(node->rightChild);
    }
}

int main()
{
    int n;
    cin >> n;
    int height = ceil(log2(n + 1));
    int *val = new int[n];
    int *weight = new int[n];
    for (int i = 0; i < n; i++)
        val[i] = 0;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        weight[i] = val[i];
    GetWeight(weight, height, n);
    TreeNode *root = new TreeNode;
    root->value = val[0];
    root->weig = weight[0];
    queue<TreeNode *> temp;
    temp.push(root);
    for (int i = 1; i < n; i += 2)
    {
        TreeNode *p = new TreeNode;
        p->value = val[i];
        p->weig = weight[i];
        temp.front()->leftChild = p;
        temp.push(p);
        if (i + 1 < n)
        {
            TreeNode *q = new TreeNode;
            q->value = val[i + 1];
            q->weig = weight[i + 1];
            temp.front()->rightChild = q;
            temp.push(q);
        }
        temp.pop();
    }
    Reverse(root);
    OutPut(root);
    cout << endl;
    system("pause");
    return 0;
}
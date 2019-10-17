/*
小蓝鲸想放松一下，于是打算去著名的二叉树公园散步。 
二叉树公园有n个景点，某些景点之间由一条小路连接。没错，和你想的一样，这个公园之所以叫“二叉树”公园，就是因为这些小路将景点连成了一个二叉树。
所有景点的编号是0到n-1。0号景点是二叉树公园的根节点。所有小路的长度为1。 
小蓝鲸打算从某一个景点进入公园散步，散步完成后再从某一个景点离开公园。她觉得二叉树非常优美，因此对二叉树公园很好奇，想每个景点都能散步到。
但是，她也不想太累，所以散步的总路程要最短。 
她希望聪明的你能告诉她最短的路程是多少。 
输入
    第1行一个正整数n，表示二叉树公园景点的个数。 
    第2到第n+1行，每行有两个整数l和r，用空格隔开。第i+2行的l表示景点l是景点i的左儿子，r表示景点r是景点i的右儿子。
    当l或者r为-1时，表示这个儿子不存在。（1≤n≤105）
输出
    一行，一个正整数，表示小蓝鲸最短所需要走的路程。

求出二叉树的最长通路（直径）
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int order;
    TreeNode *leftChild = NULL;
    TreeNode *rightChild = NULL;
};

int Depth(TreeNode *node, int &res)
{
    if (node == NULL)
        return 0;
    int left = Depth(node->leftChild, res);
    int right = Depth(node->rightChild, res);
    res = max(res, left + right);
    return max(left, right) + 1;
}

int main()
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode;
    root->order = 0;
    vector<TreeNode*> temp;
    temp.push_back(root);
    for (int i = 0; i < n; i++)
    {
        int left, right;
        cin >> left >> right;
        if (left != -1)
        {
            TreeNode *p = new TreeNode;
            p->order = left;
            temp.front()->leftChild = p;
            temp.push_back(p);
        }
        if (right != -1)
        {
            TreeNode *p = new TreeNode;
            p->order = right;
            temp.front()->rightChild = p;
            temp.push_back(p);
        }
        temp.erase(temp.begin());
    }
    int res = 0;
    Depth(root, res);
    cout << res + (n - res - 1) * 2 << endl;
    system("pause");
    return 0;
}
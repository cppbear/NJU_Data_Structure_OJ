/*
小蓝鲸学习了⼆叉搜索树后，去OJ上找到了⼀个相关的题⽬练⼿。题⽬如下：

    输⼊N个数字，你需要把这 N个数字依次按照⼆叉搜索树的插⼊⽅法插⼊到⼀个初始为空树的⼆叉搜索树中。
    你需要依次输出输⼊中的后 N-1个数字在⼆叉搜索树中的⽗节点中保存的数字。
    小蓝鲸觉得这个题⽬很简单，按照题意写了⼀发课上教的⼆叉搜索树，OJ却提⽰ Time Limit Exceeded 。
    机智的她⻢上想到：如果输⼊的数据是单调的，那么⼆叉搜索树就会退化成⼀条链，这样光插⼊所有输⼊数据就是 O(N2)的复杂度了，肯定会超时呀。
    这让她很奇怪。于是，她向乐于助⼈的你寻求帮助。
    
    注意：本题可以使⽤STL，例如： vector 、 queue 、 set 和 map 等。

输入
    第⼀⾏⼀个正整数N 。（2≤N≤5×104）
    第⼆⾏ N个以空格分隔的两两不同的正整数 ai。（1≤ai≤2×109） 
输出
    一行N-1个以空格分隔的数字，代表输⼊中的后N-1个数字在⼆叉搜索树中的⽗节点中保存的数字。
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *parent = NULL;
    TreeNode *LeftChild = NULL;
    TreeNode *RightChild = NULL;
};

int main()
{
    int n;
    //cin >> n;
    scanf("%d", &n);
    int a;
    //cin >> a;
    scanf("%d", &a);
    vector<TreeNode *> res;
    TreeNode *root = new TreeNode;
    root->val = a;
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        //cin >> temp;
        scanf("%d", &temp);
        TreeNode *node = new TreeNode;
        node->val = temp;
        TreeNode *p = root;
        while (p)
        {
            if (temp < p->val)
            {
                if (p->LeftChild)
                    p = p->LeftChild;
                else
                {
                    p->LeftChild = node;
                    node->parent = p;
                    res.push_back(p);
                    break;
                }
            }
            else if (temp > p->val)
            {
                if (p->RightChild)
                    p = p->RightChild;
                else
                {
                    p->RightChild = node;
                    node->parent = p;
                    res.push_back(p);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        //cout << res[i]->val << ' ';
        printf("%d ", res[i]->val);
    }
    system("pause");
    return 0;
}
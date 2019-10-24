/*
圣诞节前夕，小蓝鲸和室友们决定给寝室的二叉圣诞树挂上灯烛和装饰品，由于繁重的课业压力导致小蓝鲸没有足够的时间精力对圣诞树进行修剪，
树的枝杈略显杂乱。以一种n=13个节点的圣诞树结构为例，节点从1开始按层编号。
小蓝鲸和室友们决定，只把树的边缘的节点挂上装饰品，小蓝鲸所认为的边缘是指：从圣诞树的左侧或右侧向另一侧望去，所能看到的所有未被挡住的节点。
对于图1的圣诞树，需要装饰的边缘节点即为1、2、3、4、6、7、10、11、13。小蓝鲸希望你能帮助他找出这些需要挂上装饰品的节点编号。

输入
    第1行一个正整数n，表示圣诞树的节点总数。满足1≤n≤30。
    第2到n+1行，每行有两个整数。第i+1(1≤i≤n)行的整数表示第i个节点的左右子节点编号，-1代表该节点没有左节点或右节点。

输出
    输出仅一行整数，按照节点编号从小到大的顺序，输出需要装饰的节点编号。行末无多余空格换行符。
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *LeftChild = NULL;
    TreeNode *RightChild = NULL;
};


int main()
{
    int n;
    cin >> n;
    TreeNode *root = new TreeNode;
    root->val = 1;
    queue<TreeNode *> temp;
    temp.push(root);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != -1)
        {
            TreeNode *p = new TreeNode;
            p->val = a;
            temp.front()->LeftChild = p;
            temp.push(p);
        }
        if (b != -1)
        {
            TreeNode *p = new TreeNode;
            p->val = b;
            temp.front()->RightChild = p;
            temp.push(p);
        }
        temp.pop();
    }
    queue<TreeNode *> x, y;
    x.push(root);
    while (!x.empty())
    {
        if (x.size() == 1)
            cout << x.front()->val << ' ';
        else
        {
            cout << x.front()->val << ' ' << x.back()->val << ' ';
        }
        y = x;
        while (!x.empty())
            x.pop();
        while (!y.empty())
        {
            if (y.front()->LeftChild)
                x.push(y.front()->LeftChild);
            if (y.front()->RightChild)
                x.push(y.front()->RightChild);
            y.pop();
        }
    }
    system("pause");
    return 0;
}
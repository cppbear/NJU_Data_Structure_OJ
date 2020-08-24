#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *LeftChild;
    TreeNode *RightChild;
};

void GetNum(string str, vector<int> &num)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
            continue;
        else
        {
            int j = 0;
            while (str[i + j] != ' ' && i + j < n)
                j++;
            string temp = str.substr(i, j);
            num.push_back(atoi(temp.c_str()));
            i += j;
        }
    }
}

TreeNode *CreateTree(vector<int> num, int &i)
{
    TreeNode *p = new TreeNode;
    if (num[i] == -1)
    {
        i++;
        return NULL;
    }
    else
    {
        p->val = num[i];
        i++;
        p->LeftChild = CreateTree(num, i);
        p->RightChild = CreateTree(num, i);
    }
    return p;
}

void OutPut(TreeNode *node, vector<int> &reverse)
{
    if (node == NULL)
    {
        reverse.push_back(-1);
        return;
    }
    else
    {
        reverse.push_back(node->val);
        OutPut(node->RightChild, reverse);
        OutPut(node->LeftChild, reverse);
    }
}

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    vector<int> numa, numb;
    GetNum(a, numa);
    GetNum(b, numb);
    TreeNode *roota, *rootb;
    int t = 0;
    //roota = CreateTree(numa, t);
    t = 0;
    rootb = CreateTree(numb, t);
    vector<int> rev_b;
    OutPut(rootb, rev_b);
    for (int i = 0; i < rev_b.size(); i++)
    {
        cout << rev_b[i] << " ";
    }
    cout << endl;
    if (numa == rev_b)
        cout << "YES";
    else
    {
        cout << "NO";
    }
    system("pause");
    return 0;
}
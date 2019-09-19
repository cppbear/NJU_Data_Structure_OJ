/*
小蓝鲸在构思作⽂时⽂思如泉涌，但是她怕写着写着⼿酸，于是她决定只写压缩后的版本。怎么压缩呢？她决定把重复的⼀段⽂字压缩成重复次数[最小重复单元] 的形式。例如， agkdgkd 会被压缩成 a2[gkd] 。但是⽼师在批阅的时候看不懂压缩后的作⽂，于是向你（小蓝鲸的好友）求助，希望你能帮她把小蓝鲸的作⽂还原。
注意，小蓝鲸未压缩的作⽂都是⽤小写的英⽂字⺟写的。
请不要使⽤递归⽅法来解题。
输入
⼀⾏字符串，压缩后的小蓝鲸的作⽂，只含有数字、小写字⺟、[ 和 ] 4种符号。（0≤小蓝鲸压缩后的作⽂⻓度≤200）
输出
⼀⾏字符串，小蓝鲸原始的作⽂。
*/
#include <iostream>
using namespace std;

struct Node
{
    char a;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL) {}
    ~Stack() { makeEmpty(); };
    void Push(const char &x);
    bool Pop(char &x);
    bool getTop(char &x) const;
    bool IsEmpty() const { return (top == NULL) ? true : false; }
    void makeEmpty();
};

void Stack::makeEmpty()
{
    Node *p;
    while (top != NULL)
    {
        p = top;
        top = top->next;
        delete p;
    }
};
void Stack::Push(const char &x)
{
    Node *p = new Node;
    p->a = x;
    p->next = top;
    top = p;
    //assert(top != NULL);
}
bool Stack::Pop(char &x)
{
    if (IsEmpty() == true)
        return false;
    Node *p = top;
    top = top->next;
    x = p->a;
    delete p;
    return true;
};
bool Stack::getTop(char &x) const
{
    if (IsEmpty() == true)
        return false;
    x = top->a;
    return true;
};

int main()
{
    char str[201] = {};
    while (cin.getline(str, 201))
    {
        Stack a;
        int b[100] = {};
        int m = 0;
        for (int i = 0; str[i] != 0; i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '[')
                a.Push(str[i]);
            else if (str[i] >= '0' && str[i] <= '9')
            {
                int j;
                char num[10] = {};
                int t;
                for (j = i, t = 0; str[j] >= '0' && str[j] <= '9'; j++, t++)
                {
                    num[t] = str[j];
                }
                b[m] = atoi(num);
                m++;
                i = j - 1;
            }
            else if (str[i] == ']')
            {
                char temp[40000] = {};
                char rubish;
                int p = 0;
                char topchar;
                a.getTop(topchar);
                for (int j = i - 1; topchar != '['; j--)
                {
                    a.Pop(temp[p]);
                    p++;
                    a.getTop(topchar);
                }
                a.Pop(rubish);
                int q;
                for (q = 0; b[q] > 0; q++)
                    ;
                for (int j = 0; j < b[q - 1]; j++)
                {
                    for (int s = 39999; s >= 0; s--)
                    {
                        if (temp[s] != 0)
                            a.Push(temp[s]);
                    }
                }
                b[q - 1] = 0;
                m = q - 1;
            }
        }
        Stack c;
        while (!a.IsEmpty())
        {
            char origin;
            a.Pop(origin);
            c.Push(origin);
        }
        while (!c.IsEmpty())
        {
            char origin;
            c.Pop(origin);
            cout << origin;
        }
        cout << endl;
    }
    return 0;
}

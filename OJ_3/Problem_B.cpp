/*
给定一个英文句子，要求翻转句中单词的顺序，单词本身不变，其中，句子没有标点，单词之间以空格隔开。
要求：用链表实现，每个链表结点的数据域为一个字符（char型）。本题不允许使用C++标准库提供额外帮助。 
输入
    一个英文句子，仅由 'a'~'z'和‘A’~‘Z’和空格‘ ’构成，字符串长度len满足，0≤len≤100000
输出
    翻转后的英文句子，行末无多余空格换行符。

注意：句子中若有多个空格，则保留。
*/
#include <iostream>
using namespace std;

struct Node
{
    Node *pre;
    char word;
    Node *next;
};

void Reverse(Node *head, Node *tail)
{
    if (head->next == NULL)
        return;
    Node *p = tail;
    while (tail)
    {
        if (tail->word == ' ')
        {
            cout << ' ';
            tail = tail->pre;
        }
        else
        {
            p = tail;
            while (p->word != ' ' && p->word != '#')
                p = p->pre;
            p = p->next;
            Node *q = p;
            if (!p)
                break;
            while (p != tail)
            {
                cout << p->word;
                p = p->next;
            }
            cout << tail->word;
            tail = q->pre;
            if (tail->word == '#')
            {
                break;
            }
        }
    }
}

int main()
{
    char str[100001];
    cin.getline(str, 100001);
    Node *head = new Node;
    head->pre = NULL;
    head->next = NULL;
    head->word = '#';
    Node *tail = head;
    int count;
    while (str[count] == ' ')
        count++;
    for (int i = count; str[i] != 0; i++)
    {
        Node *p = new Node;
        p->word = str[i];
        p->next = NULL;
        tail->next = p;
        p->pre = tail;
        tail = tail->next;
    }
    Reverse(head, tail);

    return 0;
}
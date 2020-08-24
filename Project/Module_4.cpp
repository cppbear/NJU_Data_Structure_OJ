#include <iostream>
#include <string>
using namespace std;

// 定义哈希表，并初始化为0
bool table[8000000] = {};

//BKDRHash
unsigned int
CreateHash(string str)
{
    unsigned int hash = 0;
    unsigned int seed = 7;  //哈希种子
    // 计算哈希值
    for (int i = 0; i < str.length(); i++)
    {
        hash = hash * seed + str[i];
    }
    // 截取结果的后22位，避免超出哈希表的大小
    return (hash & 0x3fffff);
}

int main()
{
    int n;
    cin >> n;
    unsigned *res = new unsigned[n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        // 求出字符串对应的哈希值
        unsigned data = CreateHash(temp);
        // 将对应位置上的值置为true
        table[data] = true;
    }
    // 获取目标身份证
    string target;
    cin >> target;
    unsigned val = CreateHash(target);
    // 进行匹配
    if (table[val])
        cout << "true";
    else
    {
        cout << "false";
    }
    
    system("pause");
    return 0;
}
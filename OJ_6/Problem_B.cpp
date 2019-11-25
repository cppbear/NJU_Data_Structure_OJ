/*
开学初，蓝鲸大学的新生来自不同的城市，每个同学都只知道和自己来自同一个城市的同学人数。
现在假设我们可以询问一个同学和他来自同一个城市的同学人数（不包括他自己），在询问了部分同学之后（不会重复询问同一位同学），
我们想推断蓝鲸大学的新生的最少数目。

输入
    一行整数，空格隔开。每个整数代表一次询问结果。询问的人数M满足1≤M≤1000，每次的询问结果N满足0≤N≤999。

输出
    输出一个整数，代表蓝鲸大学最少的新生数目。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stu
{
    int val;
    int num = 1;
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

int main()
{
    string str;
    getline(cin, str);
    vector<int> a;
    GetNum(str, a);
    vector<stu> res;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int m = res.size();
        bool flag = false;
        for (int j = 0; j < m; j++)
        {
            if (a[i] == res[j].val && res[j].num < res[j].val + 1)
            {
                res[j].num++;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            stu temp;
            temp.val = a[i];
            res.push_back(temp);
        }
    }
    int sum = 0;
    int k = res.size();
    for (int i = 0; i < k; i++)
        sum += res[i].val + 1;
    cout << sum;
    system("pause");
    return 0;
}
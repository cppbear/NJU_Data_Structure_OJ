/*
编写一个算法，顺序输出hash表内容。设散列函数为 hash(x) = x 中 的第一个数字，采用线性探查法来解决冲突。(hash表的size请设置大于30)

输入
    多组输入，每组输入有两行
    第一行为数字n，表示有n个整数（多位），n不大于20
    第二行为n个以空格相隔的整数

输出
    顺序输出hash表的内容
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int hash_table[50] = {0};
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            string a = to_string(temp);
            char b = a[0];
            int c = b - 48;
            for (int j = c; j < 50; j++)
            {
                if (hash_table[j] == 0)
                {
                    hash_table[j] = temp;
                    break;
                }
            }
        }
        int max;
        for (max = 49; max > 0; max--)
        {
            if (hash_table[max] != 0)
                break;
        }
        for (int i = 0; i < max; i++)
        {
            if (hash_table[i] != 0)
                cout << hash_table[i] << ',';
        }
        cout << hash_table[max] << endl;
    }
    return 0;
}

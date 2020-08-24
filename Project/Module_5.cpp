#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

struct Bucket
{
    int max = -1;           // 桶中数据的最大值
    int min = INT_MAX;      // 桶中数据的最小值
    bool empty_n = false;   // 判断桶是否为空，true非空，false为空
};


int main()
{
    int n;
    cin >> n;
    int *wage = new int[n];
    // 读取收入，并求出最大值与最小值
    cin >> wage[0];
    int max = wage[0], min = wage[0];
    for (int i = 1; i < n; i++)
    {
        cin >> wage[i];
        max = wage[i] > max ? wage[i] : max;
        min = wage[i] < min ? wage[i] : min;
    }
    // 设置桶
    int BucketNum = n + 1;
    int len = ceil((double)(max - min) / (double)BucketNum);
    // 用数组存储每个桶的信息
    Bucket *data = new Bucket[BucketNum]();
    // 分析每个收入所对应的桶区间，并记录桶中的最大值、最小值
    for (int i = 0; i < n; i++)
    {
        int index = (wage[i] - min) / len;
        data[index].empty_n = true;
        data[index].max = wage[i] > data[index].max ? wage[i] : data[index].max;
        data[index].min = wage[i] < data[index].min ? wage[i] : data[index].min;
    }
    int maxgap = 0;
    int pre = 0;
    // 求出后一个桶（非空）的最小值与前一个桶（非空）的最大值之间的差值，并记录其中的最大值
    for (int i = 1; i < BucketNum; i++)
    {
        if (data[i].empty_n)
        {
            maxgap = (data[i].min - data[pre].max) > maxgap ? (data[i].min - data[pre].max) : maxgap;
            pre = i;
        }
    }
    cout << maxgap;
    system("pause");
    return 0;
}
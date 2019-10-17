/*
为了敦促自己在新的一学期认真学习，小蓝鲸决定记录自己每天的学习时长。在小蓝鲸看来，一天学习时间大于8小时的时候，就可以认为这是「劳累的一天」。
而所谓「认真学习的时间段」，意味在这段时间内，小蓝鲸「劳累的天数」是严格大于「不劳累的天数」。  
为了更好地检点反省自己的学习状况，小蓝鲸希望你能帮他算出「认真学习的时间段」所持续的最长天数。  
下面以一个例子更好地说明，假设小蓝鲸记录了连续7天自己的学习时长，分别为[9,9,6,0,6,6,9]，可以得出最长的「认真学习的时间段」是[9,9,6]，长度为3天。 
输入
    输入数据包括两行，第一行为一个整数n，满足1≤n≤100000，表示小蓝鲸记录自己学习时长的天数。
    第二行为n个非负整数，用空格隔开，第i个数ai表示小蓝鲸在第i天的学习时长，满足0≤ai≤16。
输出
    输出数据仅一行，包含一个整数，表示最长的「认真学习的时间段」所持续的天数，行末无空格换行符。

前缀和+单调栈
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int max_len = 0;
    cin >> n;
    int *hours = new int[n];
    for (int i = 0; i < n; i++)
        cin >> hours[i];
    for (int i = 0; i < n; i++)
        hours[i] = (hours[i] > 8) ? 1 : -1;
    int *pre_sum = new int[n + 1];
    pre_sum[0] = 0;
    for (int i = 0; i < n; i++)
        pre_sum[i + 1] = pre_sum[i] + hours[i];
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i < n + 1; i++)
    {
        if (pre_sum[i] < pre_sum[a.back()])
            a.push_back(i);
    }
    for (int i = n; i > 0; i--)
    {
        while (a.size() != 0 && pre_sum[i] > pre_sum[a.back()])
        {
                int temp = a.back();
                a.pop_back();
                if (i - temp > max_len)
                    max_len = i - temp;
        }
    }
    cout << max_len;
    return 0;
}
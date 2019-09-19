/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。注意时间复杂度。说明：你不能倾斜容器，且 n 的值至少为 2。
输入
输入包括两行，第一行为非负整数的个数n(0<n<=1000000);
第二行依次输入n个整数x，中间用空格隔开。（0<x<100000） 
输出
输出容纳水的最大值(使用long long 数据类型存储)。图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
*/
#include<iostream>
using namespace std;

long long Volume(long long *p, long long n)
{
    long long left = 0;
    long long right = n - 1;
    long long max_volume = 0;
    long long temp;
    while (left < right)
    {
        if (p[left] < p[right])
            temp = (right - left) * p[left];
        else
            temp = (right - left) * p[right];
        if (temp > max_volume)
            max_volume = temp;
        if (p[left] < p[right])
            left++;
        else
            right--;
    }
    return max_volume;
}

int main()
{
    long long n;
    while(cin >> n)
    {
        long long *a = new long long[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << Volume(a, n) << endl;
    }
    return 0;
}
/*
小蓝鲸喜欢看漫画，但小蓝鲸的寝室长禁止宿舍内看漫画。小蓝鲸刚借到 N 本漫画，第i本漫画中有 page[i] 页。
寝室长有事外出一段时间，并在 T 小时后回来，小蓝鲸希望在这段时间看完这些漫画书。
小蓝鲸可以决定看漫画的速度 S 页/小时。每个小时，她会选择一本漫画，阅读 S 页，若这本漫画少于 S 页，她将看完这本漫画书，
然后在这一小时内不会再看其他的漫画书。
因为小蓝鲸习惯慢慢看书，但希望能够在寝室长回来之前看完，所以希望你告诉她在 T 小时内看完所有 N 本书的最小阅读速度 S (S为整数）。

输入
    第一行给出两个整数 N(1≤N≤104)，表示漫画书的数量，以及 T(N ≤T≤109)，表示寝室长离开的时间。
    第二行给出N个整数，整数之间用空格分开，表示第i本漫画的页数 page[i](1≤page[i]≤109)。

输出
    输出一个数字 S，表示在寝室长回来之前小蓝鲸阅读完 N 本漫画书的最慢速度。
*/
#include <iostream>
#include <cmath>
using namespace std;

void LeastSpeed(int n, int min, int max, int time, int *page)
{
    int mid = (min + max) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ceil((double)page[i] / (double)mid);
    if (sum > time)
    {
        if (max == mid + 1)
            cout << max;
        else
        {
            LeastSpeed(n, mid, max, time, page);
        }
    }
    else if (sum <= time)
    {
        if (mid == 1)
            cout << 1;
        else
            LeastSpeed(n, min, mid, time, page);
    }
}

int main()
{
    int n, time;
    cin >> n >> time;
    int *page = new int[n];
    for (int i = 0; i < n; i++)
        cin >> page[i];
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        if (page[i] > page[temp])
            temp = i;
    }
    int MaxSpeed = page[temp];
    LeastSpeed(n, 1, MaxSpeed, time, page);
    system("pause");
    return 0;
}
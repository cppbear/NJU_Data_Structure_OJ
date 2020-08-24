#include <iostream>
#include <string>
using namespace std;

// 合并数组，排好序，然后在拷贝到原来的数组array
void MergeArray(int array[], int start, int end, int mid, int temp[])
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = array[i++];
    }
    while (j <= end)
    {
        temp[k++] = array[j++];
    }
    for (int i = 0; i < k; i++)
    {
        array[start + i] = temp[i];
    }
}

// 归并排序，将数组前半部分后半部分分成最小单元，然后再合并
void MergeSort(int array[], int start, int end, int temp[])
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(array, start, mid, temp);
        MergeSort(array, mid + 1, end, temp);
        MergeArray(array, start, end, mid, temp);
    }
}

// 二分查找统计区间
// 查找第一个大于等于key的值的位置
int lower(int *array, int size, int key)
{
    int first = 0, mid;
    int half, len;
    len = size;

    while (len > 0)
    {
        half = len >> 1;
        mid = first + half;
        if (array[mid] < key)
        {
            first = mid + 1;
            len = len - half - 1; //在右边子序列中查找
        }
        else
            len = half; //在左边子序列（包含mid）中查找
    }
    return first;
}
// 查找第一个大于key的值的位置
int upper(int *array, int size, int key)
{
    int first = 0, len = size - 1;
    int half, mid;

    if (key >= array[len])  // 如果key大于等于最大数，返回size
        return size;

    while (len > 0)
    {
        half = len >> 1;
        mid = first + half;
        if (array[mid] > key) //中位数大于key,在包含last的左半边序列中查找。
            len = half;
        else
        {
            first = mid + 1; //中位数小于等于key,在右半边序列中查找。
            len = len - half - 1;
        }
    }
    return first;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int *wage = new int[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wage[i]);
    }
    int start = 0;
    int end = n - 1;
    int *temp = new int[n];
    // 归并排序
    MergeSort(wage, start, end, temp);
    // 求前缀和
    long long *PreSum = new long long[n + 1];
    PreSum[0] = 0;
    for (int i = 0; i < n; i++)
        PreSum[i + 1] = wage[i] + PreSum[i];

    int *res = new int[m];

    for (int i = 0; i < m; i++)
    {
        int left, right;
        scanf("%d%d", &left, &right);
        int l, r;
        // 查找上下界的位置
        l = lower(wage, n, left);
        r = upper(wage, n, right);
        // 求平均值
        if (r <= l) // 处理“除以0”的情况
            res[i] = 0;
        else
        {
            res[i] = (PreSum[r] - PreSum[l]) / (r - l);
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", res[i]);
    }
    system("pause");
    return 0;
}
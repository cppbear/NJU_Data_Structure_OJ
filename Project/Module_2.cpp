#include <iostream>
#include <string>
#define MinHeap 0
#define MaxHeap 1
using namespace std;

struct Heap
{
    int *val;   // 用数组存储堆，堆顶元素存储在val[1]
    int type;   // 确定堆的类型
    int cur;    // 新元素插入的位置
};
// 左孩子的下标
int LeftChild(Heap heap, int i)
{
    if (2 * i < heap.cur)
        return 2 * i;
    else
        return -1;
}
// 右孩子的下标
int RightChild(Heap heap, int i)
{
    if (2 * i + 1 < heap.cur)
        return 2 * i + 1;
    else
        return -1;
}
// 左孩子的值
int LeftChildValue(Heap heap, int i)
{
    if (2 * i < heap.cur)
        return heap.val[2 * i];
    else
        return -1;
}
// 右孩子的值
int RightChildValue(Heap heap, int i)
{
    if (2 * i + 1 < heap.cur)
        return heap.val[2 * i + 1];
    else
        return -1;
}
// 返回堆顶元素的值
int Top(Heap heap)
{
    if (heap.cur == 1)
        return -1;
    else
        return heap.val[1];
}
// 向堆中插入元素并调整
bool Insert(Heap &heap, int data)
{
    if (heap.cur > 10010)
        return false;
    heap.val[heap.cur++] = data;
    int ptr = heap.cur - 1;
    int pre = ptr / 2;
    // 自下而上的上滑调整
    while (ptr > 1 && heap.val[ptr] > heap.val[pre] == heap.type)
    {
        int temp = heap.val[ptr];
        heap.val[ptr] = heap.val[pre];
        heap.val[pre] = temp;
        ptr = pre;
        pre /= 2;
    }
    return true;
}
// 删除堆顶元素并调整
int Delete(Heap &heap)
{
    if (heap.cur == 1)
        return -1;
    int rst = heap.val[1];
    heap.val[1] = heap.val[--heap.cur];
    heap.val[heap.cur] = 0;
    int ptr = 1;
    // 自上而下的下滑调整
    if (heap.type == MaxHeap)
    {
        while (LeftChild(heap, ptr) != -1)
        {
            if (heap.val[ptr] >= LeftChildValue(heap, ptr) && heap.val[ptr] >= RightChildValue(heap, ptr))
                return rst;

            int toSwap = LeftChildValue(heap, ptr) > RightChildValue(heap, ptr) ? LeftChild(heap, ptr) : RightChild(heap, ptr);

            int temp = heap.val[ptr];
            heap.val[ptr] = heap.val[toSwap];
            heap.val[toSwap] = temp;
            ptr = toSwap;
        }
        return rst;
    }
    else
    {
        while (LeftChild(heap, ptr) != -1)
        {
            if (heap.val[ptr] <= LeftChildValue(heap, ptr) && (heap.val[ptr] <= RightChildValue(heap, ptr) || RightChild(heap, ptr) == -1))
                return rst;

            int toSwap = LeftChild(heap, ptr);
            if (RightChild(heap, ptr) != -1 && RightChildValue(heap, ptr) < LeftChildValue(heap, ptr))
                toSwap = RightChild(heap, ptr);

            int temp = heap.val[ptr];
            heap.val[ptr] = heap.val[toSwap];
            heap.val[toSwap] = temp;
            ptr = toSwap;
        }
        return rst;
    }
}

int main()
{
    int n;
    cin >> n;
    int *res = new int[n];
    // 建立一个最小堆和最大堆并初始化
    Heap Min, Max;
    Min.type = MinHeap;
    Max.type = MaxHeap;
    Min.val = new int[10010]();
    Max.val = new int[10010]();
    Min.cur = Max.cur = 1;
    for (int i = 0; i < n; i++)
    {
        int wage;
        cin >> wage;
        Insert(Max, wage);          // 将其插入到最大堆中，并进行调整
        Insert(Min, Delete(Max));   // 将最大堆的堆顶元素删除并插入到最小堆中，并进行调整
        if (Min.cur > Max.cur)      // 若最小堆元素多，则将最小堆的堆顶元素删除并插入到最大堆中
            Insert(Max, Delete(Min));
        res[i] = (Max.cur == Min.cur) ? (Top(Max) + Top(Min)) / 2 : Top(Max);   // 根据两堆的元素个数求出中位数
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}
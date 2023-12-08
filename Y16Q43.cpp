/*题目
已知由n(n>=2)个正整数构成的集合A={ak|0<=k<n}，将其划分为两个不相交的子集A1和A2，元素个数分别为n1,n2。
A1和A2中元素之和分别为S1和S2。设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大*/
/*要求：
1.给出算法的基本设计思想：基于快排的思想
2.C/C++描述算法：代码如下
3.时间复杂度：O(nlogn)
空间复杂度：O(logn)*/

#include <iostream>
using namespace std;

int setPartition(int A[], int low, int high)
{
    int low0 = low, high0 = high;
    int flag = 1;
    int mid = (low + high) / 2;
    int pivot;
    int s1 = 0, s2 = 0;
    while (flag)
    {
        while (low < high)
        {
            pivot = A[low];
            while (low < high && A[high] >= pivot)
                --high;
            A[low] = A[high];
            while (low < high && A[low] <= pivot)
                ++low;
            A[high] = A[low];
        }
        A[low] = pivot;
        if (low == mid)
            flag = 0;
        else if (low < mid)
        {
            low0 = ++low;
            high = high0; // 重新归位
        }
        else
        {
            high0 = --high;
            low = low0; // 重新归位
        }
    }
    for (int i = 0; i < mid; i++)
        s1 += A[i];
    for (int i = mid; i <= high; i++)
        s2 += A[i];
    return s2 - s1;
}

/**/
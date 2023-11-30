/*一个长度为L的升序序列S，处在第L/2个位置的数成为S的中位数。例如，S1=(11,13,15,17,19)的中位数是15。
两个序列的中位数是含他们所有元素的升序序列的中位数。现在有两个等长升序序列A,B，
试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。
要求：
1.给出算法的基本设计思想
2.根据设计思想，采用c,c++,Java描述算法，关键之处给出注释
3.说明算法的时间复杂度和空间复杂度
*/

/*最优解：
题目分析：分别求两个序列的中位数a,b做比
        若a==b，则中位数就是a
        若a<b则中位数在（a，b）之间
        若a>b则中位数在（b，a）之间
1.基本设计思想：若a==b，则中位数就是a
        若a<b，舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求舍弃的长度相等
        若a>b，舍弃序列A中较大的一半，同时舍弃序列B中较小的一半，要求舍弃的长度相等
        在保留的两个序列中重复前三步，直到两个序列中只含一个元素为止，较小者即为中位数
2.算法实现：如下
3.时间复杂度：O(n)
空间复杂度：O(1)
*/

#include <iostream>
using namespace std;

int M_Search(int A[], int B[], int n)
{
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
    // 分别表示两个序列的首位 末位 中位
    while (s1 < d1)
    {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (A[m1] == B[m2])
            return A[m1];
        if (A[m1] < B[m2])
        {
            s1 = m1;
            d2 = m2;
            if (d1 - s1 != d2 - s2)
                s1++;
        }
        if (A[m1] > B[m2])
        {
            d1 = m1;
            s2 = m2;
            if (d1 - s1 != d2 - s2)
                s2++;
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

/*
暴力解法：放入新数组中，然后快排，输出新数组的第n-1个
*/

void Qsort(int A[], int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    // 把a数组中随机一个元素和A[l]交换    //快排优化
    int key = A[l];
    while (i < j)
    {
        while (i < j && A[j] >= key)
            j--;
        A[i] = A[j];
        while (i < j && A[i] <= key)
            i++;
        A[j] = A[i];
    }
    A[i] = key;
    // cout << l << ' ' << i - 1 << ' ' << i + 1 << ' ' << r << endl;
    Qsort(A, l, i - 1);
    Qsort(A, i + 1, r);
}

void ans(int A[], int B[], int n)
{
    int C[100];
    for (int i = 0; i < n; i++)
    {
        C[i] = A[i];
        C[n + i] = B[i];
    }

    Qsort(C, 0, 2 * n - 1);
    cout << C[n - 1];
}

// test
int main()
{
    int A[6] = {1, 3, 5, 7, 9, 12};
    int B[6] = {0, 2, 4, 6, 8, 11};
    cout << "暴力解";
    ans(A, B, 6);
    int mid_premium = M_Search(A, B, 6);
    cout << "最优解" << mid_premium;
}
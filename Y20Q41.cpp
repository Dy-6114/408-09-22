/*题目：
定义三元组(a,b,c)(其中abc均为整数)的距离D=|a-b|+|b-c|+|c-a|。给定三个非空整数集合S1,S2和S3，按升序分别存储在3个数组中。
设计一个尽可能高效的算法，计算并输出所有可能的三元组(a,b,c)(a属于S1，b属于S2,c属于S3)中的最小距离。*/
/*要求
1.给出算法的基本设计思想：因为三个非空集合升序排列，所以存储集合的数组是有序的，那针对每一个三元组，可以每次计算D之后，
令三元组中数值最小的数所在的数组下标+1，如此遍历可以保证三个数组都毫无遗漏的完成遍历。每次遍历时，如果当前三元组的D小于之前记录的D，则更新D，
否则进入下一次遍历。
2.用C/C++描述算法：代码如下
3.时间复杂度：
空间复杂度：
*/

#include <iostream>
using namespace std;

int abs(int x)
{
    return x < 0 ? -x : x;
}

int getMinD(int A[], int B[], int C[], int Alen, int Blen, int Clen)
{
    int i, j, k;
    i = j = k = 0;
    int D;
    D = abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]);
    while (i < Alen && j < Blen && k < Clen && D >= 0)
    {
        int tmp = abs(A[i] - B[j]) + abs(A[i] - C[k]) + abs(B[j] - C[k]);
        if (tmp < D)
            D = tmp;
        if (A[i] <= B[j] && A[i] <= C[k])
            i++;
        else if (A[i] >= B[j] && B[j] <= C[k])
            j++;
        else
            k++;
    }
    return D;
}
/**/
/*
设将n(n>1)个整数存放到一堆数组R中。试设计一个在时间和空间两方面都尽可能高效的算法。
将R中保存的序列循环左移p（0<p<n）个位置。要求：
1.给出算法的基本设计思想
2.根据设计思想，采用c,c++,Java描述算法，关键之处给出注释
3.说明算法的时间复杂度和空间复杂度
*/

/*
解答：
1.基本设计思想：
    reverse（0，p-1）
    reverse（p，n-1）
    reverse（0，n-1）
2.算法实现：如下
3.时间复杂度：O(n)
空间复杂度：O(1)
*/

#include<iostream>
using namespace std;

void Reverse(int R[], int from, int to)
{
    int temp;
    for(int i = 0; i < (to - from + 1)/2; i++)
    {
        temp = R[from + i];
        R[from + i] = R[to-i];
        R[to - i] = temp;
    }
}

void Converse(int R[], int n, int p)
{
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}

int main()
{
    int R[10] = {0,1,2,3,4,5,6,7,8,9};
    Converse(R,10,4);
    for (int i = 0; i < 10; i++)
    {
        cout<<R[i]<<" ";
    }
    return 0;
}
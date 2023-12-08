/*题目:
给定一个含n（n>=1）个整数的数组，设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。
例如{-5,3,2,3}最小未出现的正整数为1，{1,2,3}最小未出现整数为4*/
/*要求：
1.给出算法的基本设计思想：设置辅助数组B，初值为全0。首先遍历数组A，将B[A[i]-1]的值设为1，代表B数组下标对应的正整数值存在。
然后遍历B，找到第一个B数组值为0的下标，返回下标+1，即为所求。
2.C/C++描述算法：代码如下
3.时间复杂度：O(n)
空间复杂度：O(n)
*/

#include <iostream>
using namespace std;

int findMissMinPositiveInteger(int A[], int len)
{
    int flag = 0;
    int B[10000] = {0}; // 取A中元素最大值
    for (int i = 0; i < len; i++)
    {
        if (A[i] > 0)
            B[A[i] - 1] = 1;
    }
    int j;
    for (j = 0; j < len + 1; j++)
    {
        if (B[j] == 0)
            break;
    }
    return j + 1;
}
/**/
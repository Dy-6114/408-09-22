/*题目：
已知一个整数序列A=(a0,a1,...,an-1)，其中0<=ai<n(0<i<n)。若存在ap1=ap2=...=apm=x且m>n/2，则称x为A的主元素。例如A=(0,5,5,3,5,7,5,5)，则5为主元素；
又如A=(0,5,5,3,5,1,5,7),则A中没有主元素。假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。若存在主元素，则输出该元素；
否则输出-1。要求：
1.给出算法的基本设计思想
2.根据设计思想，采用c,c++,Java描述算法，关键之处给出注释
3.说明算法的时间复杂度和空间复杂度
*/
/*分析：
1.设计思想：（1）创建一个辅助数组
（2）使得辅助数组的下标代表元素值，辅助数组的值代表元素出现的个数
（3）记录出现次数最多的元素
（4）判断该元素出现的次数是否大于n/2，大于则返回该元素，否则返回-1；
2.算法实现如下：
3.时间复杂度：O(n)
空间复杂度:O(n)
*/

#include <iostream>
using namespace std;

int GetMajority(int A[], int n)
{
    int max = 0, *temp;
    temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    } // 辅助数组清零
    for (int k = 0; k < n; k++)
    {
        temp[A[k]]++; // 记录A序列中每个元素出现的次数
        if (temp[A[k]] > temp[max])
        {
            max = A[k]; // max为出现次数做多的元素
        }
    }
    if (temp[max] > (n / 2))
        return max;
    return -1;
}
/*更优解：
1.设计思想：策略是从前向后扫描数组元素，标记出一个可能成为主元素的元素Num。然后重新计数，确认num是否是主元素
（1）选取候选的主元素：依次扫描所给数组中的每个整数，将第一个遇到的整数Num保存到c中，记录Num的出现次数为1；
若遇到的下一个整数仍等于Num，则计数+1，否则计数-1；当计数减到0时，将遇到的下一个整数保存到c中，计数重新记为1，开始新一轮计数，
即从当前位置开始重复上述过程，直到扫描完全部数组元素。
（2）判断c元素是否是真正的主元素：再次扫描该数组，统计c中元素出现的次数，若大于n/2，则为主元素；否则序列中不存在主元素。
2.算法实现如下：
3.时间复杂度：O(n)
空间复杂度:O(1)
*/

int GetMajority_pro(int A[], int n)
{
    int c, count = 1;
    c = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] == c)
            count++;
        else if (count > 0)
            count--;
        else
        {
            count = 1;
            c = A[i];
        }
    }
    if (count > 0)
        for (int i = count = 0; i < n; i++)
        {
            if (A[i] == c)
                count++;
        }
    if (count > n / 2)
        return c;
    return -1;
}

int main()
{
    int B[] = {0, 5, 5, 3, 5, 1, 5, 7};
    int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
    cout << "一般解法" << endl;
    cout << "A序列中的主元素为:" << GetMajority(A, 8) << endl;
    cout << "B序列中的主元素为:" << GetMajority(B, 8) << endl;
    cout << "更优解法" << endl;
    cout << "A序列中的主元素为:" << GetMajority_pro(A, 8) << endl;
    cout << "B序列中的主元素为:" << GetMajority_pro(B, 8);
    return 0;
}
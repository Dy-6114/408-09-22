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
    }//辅助数组清零
    for (int k = 0; k < n; k++)
    {
        temp[A[k]]++; //记录A序列中每个元素出现的次数
        if (temp[A[k]] > temp[max])
        {
            max = A[k]; //max为出现次数做多的元素
        }
    }
    if (temp[max] > (n / 2))
        return max;
    return -1;
}
/**/



int main(){
    int B[] = {0,5,5,3,5,1,5,7};
    int A[] = {0,5,5,3,5,7,5,5};
    cout<<"A序列中的主元素为:"<<GetMajority(A,8)<<endl;
    cout<<"B序列中的主元素为:"<<GetMajority(B,8);
    return 0;
}
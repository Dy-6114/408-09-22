/*
�轫n(n>1)��������ŵ�һ������R�С������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨��
��R�б��������ѭ������p��0<p<n����λ�á�Ҫ��
1.�����㷨�Ļ������˼��
2.�������˼�룬����c,c++,Java�����㷨���ؼ�֮������ע��
3.˵���㷨��ʱ�临�ӶȺͿռ临�Ӷ�
*/

/*
���
1.�������˼�룺
    reverse��0��p-1��
    reverse��p��n-1��
    reverse��0��n-1��
2.�㷨ʵ�֣�����
3.ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(1)
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
/*��Ŀ����֪һ������ͷ���ĵ��������ṹΪ data|link��
���裺������ֻ������ͷָ��list���ڲ��ı������ǰ���£������һ�������ܸ�Ч���㷨��
���������е�����k��λ���ϵĽ�㣨kΪ���������������ҳɹ����㷨����ý���data���ֵ��������1������ֻ����0��
Ҫ��
1�������㷨�Ļ������˼�롣
2�������㷨����ϸ����ʵ�֡�
3���������˼���ʵ�ֲ��裬���ó���������������㷨��ʹ��C/C++��Java�����ؼ�֮��������Ҫע�͡�
*/
/*
1.�������˼�룺����ָ��p,q��ͨ������һ��������ʼʱ��ָ��ͷ������һ����㡣
pָ���������ƶ������ƶ�����k��ʱ��qָ����pָ��ͬ����ʼ�ƶ�����pָ���ƶ������һ�����ʱ��qΪ����
2.���裺��1��count=0��p��qָ��ͷ������һ�����
        ��2����pΪ�գ�ת��5��
        ��3����count=k����qָ����һ����㣬����count+=1
        ��4��pָ����һ����㣬ת��2��
        ��5����count=k������ҳɹ������data���ֵ������1���������ʧ�ܣ�����0
*/
// 3.����ʵ��

#include <iostream>
#include <stdio.h>

using namespace std;

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *link;
} LNode, *LinkList;

int search_k(LinkList list, int k)
{
    LinkList p = list->link;
    LinkList q = list->link; //ָ��ͷ����Ľ��
    int count = 0;
    while (p != NULL) //����ֱ�����һ�����
    {
        if (count < k)
            count++; //��������countС��k, ֻ�ƶ�p
        else
            q = q->link; // p��qһ���ƶ�
        p = p->link;
    }
    if (count = k)
    {
        cout << q->data; //���ҳɹ������dataֵ������1
        return 1;
    }
    else
        return 0; //����ʧ�ܣ�����0
}

/*
����عˣ�
��408-DS�е�chapter2

*/
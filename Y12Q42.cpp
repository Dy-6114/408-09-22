/*��Ŀ���ٶ����ô�ͷ���ĵ������浥�ʣ���������������ͬ�ĺ�׺ʱ����ɹ�����ͬ�ĺ�׺�洢�ռ䣬����loding��being�Ĵ洢ӳ��
�ս��->l->o->a->d--
                   |--->i->n->g
�ս��->b->e--------
��str1��str2�ֱ�ָ�������������ڵ������ͷ��㣬������ṹΪdata|next�������һ��ʱ���Ͼ����ܸ�Ч���㷨���ҳ���str1��str2
��ָ����������ͬ��׺����ʼλ�ã�������ʾ�ַ�i���ڽ���λ�ã���Ҫ��
1.�����㷨�Ļ������˼��
2.�������˼�룬����c,c++,Java�����㷨���ؼ�֮������ע��
3.˵���㷨��ʱ�临�Ӷ�
*/
/*
1.�������˼�룺��1���ֱ������������ĳ���m��n
��2�������������Ա�β���룺��ָ��p��q�ֱ�ָ��str1��str2��ͷ��㣬��m>=n,��ʹpָ������ĵ�m-n+1����㣻��m<n,��qָ��n-m+1�����
��3��������ָ��p��qͬ������ƶ������ж������Ƿ�ָ��ͬһ����㡣���ǣ���õ㼴Ϊ����Ĺ�ͬ��׺����ʼλ�á�
2.�㷨ʵ�֣�����
3.ʱ�临�Ӷȣ�O(max(m,n))
*/

#include <iostream>
using namespace std;

typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, *LinkList; //ÿ���������ݽṹ

Lnode *Find_first_common(LinkList str1, LinkList str2)
{
    Lnode *p = str1, *q = str2;
    int len1 = 0, len2 = 0;
    while (p != NULL)
    {
        p = p->next;
        len1++;
    } //��str1�ĳ���
    while (q != NULL)
    {
        q = q->next;
        len2++;
    } //��str1�ĳ���
    for (p = str1; len1 > len2; len1--)
        p = p->next;
    for (q = str2; len1 < len2; len2--)
        q = q->next;
    //��str1��str2����
    while (p->next != NULL && p->next != q->next)
    {
        p = p->next;
        q = q->next;
    } //�ҵ�q,qָ�빲ָͬ��ĵ�һ�����
    return p->next;
}
/**/
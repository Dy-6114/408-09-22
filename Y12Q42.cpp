/*题目：假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间，例如loding和being的存储映像
空结点->l->o->a->d--
                   |--->i->n->g
空结点->b->e--------
设str1和str2分别指向两个单词所在单链表的头结点，链表结点结构为data|next，请设计一个时间上尽可能高效的算法，找出由str1和str2
所指向两个链表共同后缀的起始位置（如上所示字符i所在结点的位置）。要求：
1.给出算法的基本设计思想
2.根据设计思想，采用c,c++,Java描述算法，关键之处给出注释
3.说明算法的时间复杂度
*/
/*
1.基本设计思想：（1）分别求出两个链表的长度m和n
（2）将两个链表以表尾对齐：令指针p，q分别指向str1和str2的头结点，若m>=n,则使p指向链表的第m-n+1个结点；若m<n,则q指向n-m+1个结点
（3）反复将指针p和q同步向后移动，并判断他们是否指向同一个结点。若是，则该点即为所求的共同后缀的起始位置。
2.算法实现：如下
3.时间复杂度：O(max(m,n))
*/

#include <iostream>
using namespace std;

typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, *LinkList; //每个结点的数据结构

Lnode *Find_first_common(LinkList str1, LinkList str2)
{
    Lnode *p = str1, *q = str2;
    int len1 = 0, len2 = 0;
    while (p != NULL)
    {
        p = p->next;
        len1++;
    } //求str1的长度
    while (q != NULL)
    {
        q = q->next;
        len2++;
    } //求str1的长度
    for (p = str1; len1 > len2; len1--)
        p = p->next;
    for (q = str2; len1 < len2; len2--)
        q = q->next;
    //将str1和str2对齐
    while (p->next != NULL && p->next != q->next)
    {
        p = p->next;
        q = q->next;
    } //找到q,q指针共同指向的第一个结点
    return p->next;
}
/**/
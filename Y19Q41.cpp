/*题目：
设线性表L=(a1,a2,a3,...,an-2,.,an)采用带头结点的单链表保存，链表中的结点定义如下：
typedef struct node{
    int data;
    struct node* next;
}NODE;
请设计一个空间复杂度为O(1)且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表L'=(a1,an,a2,an-1,a3,an-2,...)。
*/
/*要求：
1.给出算法的基本设计思想：设置指针h,m,r。开始都指向头结点，之后使指针m走一步，r走两步，当r指向最后一个结点时，m指向链表的中间结点。
将后半段链表逆置。逆置完成后，将后半段依次插入前半段中。
2.C/C++描述算法：代码如下。
3.算法的时间复杂度：O(n)
*/

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void reSort(NODE *L)
{
    NODE *m, *r;
    m = r = L;              // m指向中结点的指针
    NODE *p, *q, *s;        // 配合完成插入和逆置的辅助指针
    while (r->next != NULL) // 找到中结点m
    {
        m = m->next;
        r = r->next;
        if (r->next != NULL)
            r = r->next;
    }
    p = m->next; // p指向后半段的第一个结点
    m->next = NULL;
    while (p != NULL)
    { // 逆置后半段链表,头插法
        q = p->next;
        p->next = m->next;
        m->next = p;
        p = q;
    }
    s = L->next; // 前半段第一个数据结点
    p = m->next; // 后半段第一个结点
    m->next = NULL;
    while (p != NULL)
    { // 将完成逆置的后半段插入前半段中
        q = p->next;
        p->next = s->next;
        s->next = p;
        s = p->next;
        p = q;
    }
}
/**/
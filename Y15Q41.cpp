/*题目
用单链表保存m个整数，结点的结构为data|link，且|data|<n。设计一个尽可能高效的算法，对于链表中绝对值相同的结点，
仅保留第一次出现的结点，删除其余绝对值相同的结点。。*/
/*要求
1.给出算法的基本思想：使用辅助数组A，记录出现结点值的绝对值为数组下标，数组值设为1，若之后遍历，
发现A[|data|] == 1,则删除该data所在的结点。
2.算法实现：代码如下
3.时间复杂度：O(m)
空间复杂度：O(n)*/

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *link;
} NODE;

int abs(int a)
{
    return a < 0 ? -a : a;
}

void deleteSameAbsValue(NODE *head, int n)
{
    int *a, x;
    NODE *p = head, *q;
    a = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = 0; // 设置数组a全0
    }
    while (p->link != NULL)
    {
        x = abs(p->link->data);
        if (*(a + x) == 0)
        {
            *(a + x) = 1;
            p = p->link;
        }
        else
        {
            q = p->link;
            p->link = q->link;
            free(q);
        }
    }
    free(a); // 释放辅助数组；
}
/**/
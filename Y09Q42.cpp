/*题目：已知一个带有头结点的单链表，结点结构为 data|link。
假设：该链表只给出了头指针list。在不改变链表的前提下，请设计一个尽可能高效的算法，
查找链表中倒数第k个位置上的结点（k为正整数）。若查找成功，算法输出该结点的data域的值，并返回1；否则，只返回0。
要求：
1、描述算法的基本设计思想。
2、描述算法的详细步骤实现。
3、根据设计思想和实现步骤，采用程序设计语言描述算法（使用C/C++或Java），关键之处给出简要注释。
*/
/*
1.基本设计思想：两个指针p,q，通过遍历一次链表，初始时均指向头结点的下一个结点。
p指针沿链表移动，当移动到第k个时，q指针与p指针同步开始移动，当p指针移动到最后一个结点时，q为所求
2.步骤：（1）count=0，p，q指向头结点的下一个结点
        （2）若p为空，转（5）
        （3）若count=k，则q指向下一个结点，否则count+=1
        （4）p指向下一个结点，转（2）
        （5）若count=k，则查找成功，输出data域的值，返回1；否则查找失败，返回0
*/
// 3.代码实现

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
    LinkList q = list->link; //指向头结点后的结点
    int count = 0;
    while (p != NULL) //遍历直到最后一个结点
    {
        if (count < k)
            count++; //计数，若count小于k, 只移动p
        else
            q = q->link; // p，q一起移动
        p = p->link;
    }
    if (count = k)
    {
        cout << q->data; //查找成功，输出data值，返回1
        return 1;
    }
    else
        return 0; //查找失败，返回0
}

/*
链表回顾：
见408-DS中的chapter2

*/
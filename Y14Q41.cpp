/*题目
二叉树的带权路径长度（WPL）是二叉树中所有叶结点的带权路径长度之和。
给定一棵二叉树T，采用二叉链表存储，结点结构为left|weight|right。
其中叶结点的weight域保存该节点的非负权值。设root为指向T的根结点的指针，
请设计求T的WPL的算法，要求：
1.给出算法的基本设计思想
2.给出二叉树结点的数据类型定义
3.根据设计思想，采用c,c++,Java描述算法，关键之处给出注释
*/
/*解答：
1.算法设计：采用递归形式的先序遍历，先将叶结点的权值与其深度乘积，再将叶结点之间求和。
2.结构如下
3.算法实现如下
*/

#include<iostream>
using namespace std;

typedef struct BiTNode
{
    int weight;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

int wpl_PreOrder(BiTree root, int deep){
    static int wpl = 0;
    if(root->lchild!=NULL)
        wpl_PreOrder(root->lchild,deep+1);
    if(root->rchild!=NULL)
        wpl_PreOrder(root->rchild,deep+1);
    if(root->lchild==NULL && root->rchild == NULL)
        wpl += root->weight * deep;
    return wpl;
}

int WPL(BiTree root){
    return wpl_PreOrder(root, 0);
}
/*解答2：
1.算法设计：采用层次遍历。
（1）当遍历到叶子结点时，累计wpl
（2）当遍历到非叶子结点时，把该节点的子树加入队列
（3）当某结点为该层的最后一个结点时，层数自增1
（4）队列空时遍历结束，返回wpl。
*/

#define Maxsize 100
int wpl_levelOrder(BiTree root){
    BiTree q[Maxsize];          //声明队列，end1为队头指针，end2为队尾指针
    int end1, end2;             //队列最多容纳Maxsize-1个元素
    end1 = end2 = 0;            //头指针指向队头元素，尾指针指向队尾的后一个元素
    int wpl = 0,deep = 0;       //初始化
    BiTree lastNode,newlastNode;    //设置本层最后一个结点和下一层最后一个结点
    lastNode = root;            //初始化，本层最后一个结点为根结点
    newlastNode = NULL;         //初始化
    q[end2++] = root;           //根结点入队
    while(end1 != end2){        //队列不空
        BiTree t = q[end1++];       //队列中第一个元素出队
        if(t->lchild == NULL && t->rchild == NULL)      //如果是叶结点，计算wpl
            wpl +=deep * t->weight;
        if(t->lchild != NULL){              //若为非叶结点，结点入队，更新下一层结点的最后一个结点为当前左结点
            q[end2++] = t->lchild;
            newlastNode = t->lchild;
        }
        if(t->rchild != NULL){              //若为非叶结点，结点入队，更新下一层结点的最后一个结点为当前右结点
            q[end2++] = t->rchild;
            newlastNode = t->rchild;
        }
        if(t == lastNode){                  //如果当前结点时本层的最后一个结点，更新lastnode，深度+1
            lastNode = newlastNode;
            deep +=1;
        }
    }
    return wpl;
}
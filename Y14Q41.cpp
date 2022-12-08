/*��Ŀ
�������Ĵ�Ȩ·�����ȣ�WPL���Ƕ�����������Ҷ���Ĵ�Ȩ·������֮�͡�
����һ�ö�����T�����ö�������洢�����ṹΪleft|weight|right��
����Ҷ����weight�򱣴�ýڵ�ķǸ�Ȩֵ����rootΪָ��T�ĸ�����ָ�룬
�������T��WPL���㷨��Ҫ��
1.�����㷨�Ļ������˼��
2.���������������������Ͷ���
3.�������˼�룬����c,c++,Java�����㷨���ؼ�֮������ע��
*/
/*���
1.�㷨��ƣ����õݹ���ʽ������������Ƚ�Ҷ����Ȩֵ������ȳ˻����ٽ�Ҷ���֮����͡�
2.�ṹ����
3.�㷨ʵ������
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
/*���2��
1.�㷨��ƣ����ò�α�����
��1����������Ҷ�ӽ��ʱ���ۼ�wpl
��2������������Ҷ�ӽ��ʱ���Ѹýڵ�������������
��3����ĳ���Ϊ�ò�����һ�����ʱ����������1
��4�����п�ʱ��������������wpl��
*/

#define Maxsize 100
int wpl_levelOrder(BiTree root){
    BiTree q[Maxsize];          //�������У�end1Ϊ��ͷָ�룬end2Ϊ��βָ��
    int end1, end2;             //�����������Maxsize-1��Ԫ��
    end1 = end2 = 0;            //ͷָ��ָ���ͷԪ�أ�βָ��ָ���β�ĺ�һ��Ԫ��
    int wpl = 0,deep = 0;       //��ʼ��
    BiTree lastNode,newlastNode;    //���ñ������һ��������һ�����һ�����
    lastNode = root;            //��ʼ�����������һ�����Ϊ�����
    newlastNode = NULL;         //��ʼ��
    q[end2++] = root;           //��������
    while(end1 != end2){        //���в���
        BiTree t = q[end1++];       //�����е�һ��Ԫ�س���
        if(t->lchild == NULL && t->rchild == NULL)      //�����Ҷ��㣬����wpl
            wpl +=deep * t->weight;
        if(t->lchild != NULL){              //��Ϊ��Ҷ��㣬�����ӣ�������һ��������һ�����Ϊ��ǰ����
            q[end2++] = t->lchild;
            newlastNode = t->lchild;
        }
        if(t->rchild != NULL){              //��Ϊ��Ҷ��㣬�����ӣ�������һ��������һ�����Ϊ��ǰ�ҽ��
            q[end2++] = t->rchild;
            newlastNode = t->rchild;
        }
        if(t == lastNode){                  //�����ǰ���ʱ��������һ����㣬����lastnode�����+1
            lastNode = newlastNode;
            deep +=1;
        }
    }
    return wpl;
}
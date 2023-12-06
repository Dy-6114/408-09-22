/*题目：已知非空二叉树T的结点值均为正整数，采用顺序存储方式，数据结构定义如下：
typedef struct{
    int SqBiTNode[MAX_SIZE]; //保存结点值的数组
    int ELemNum;//实际占用的数据元素个数
}SqBiTree;
T中不存在的结点在数据SqBiTNode中用-1表示。
请设计一个尽可能高效的算法，判定一棵采用这种方式存储的二叉树是否为二叉搜索树，若是，则放回True，否则返回False。
*/
/*要求：
1.给出算法的基本设计思想：如果一个二叉树是二叉排序树，那么它的中序遍历序列是升序的，
也就是说若左子树不是升序的，或中间结点值<前驱结点值，或右子树不是升序的则不是二叉排序树，
所以可以采用递归的方法中序遍历二叉树，设置一个前驱变量pre，若当前访问结点的值<pre,则返回false。否则pre=当前结点的值。
遍历结束则返回true。
2.C/C++描述
*/

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

typedef struct
{
    int SqBiTNode[MAX_SIZE]; // 保存结点值的数组
    int ELemNum;             // 实际占用的数据元素个数
} SqBiTree;

int pre = -1;
bool judge(SqBiTree *bt, int i)
{
    if (i < bt->ELemNum && bt->SqBiTNode[i] != -1)
    {
        if (judge(bt, 2 * i + 1) == false)
            return false;
        if (pre > bt->SqBiTNode[i])
            return false;
        else
            pre = bt->SqBiTNode[i];
        if (judge(bt, 2 * i + 2) == false)
            return false;
    }
    return true;
}
/**/
/*题目
请设计一个算法，将给定的表达式树(二叉树)转换为等价的中缀表达式（通过括号反映操作符的计算次序）并输出。二叉树结点定义如下：
typedef struct node{
    char data[10];
    struct node *left, *right;
}BTree;
*/
/*要求：
1.给出算法的基本设计思想：中序遍历是核心。
2，C/C++语言描述算法：代码如下。*/

#include <iostream>
using namespace std;

typedef struct node
{
    char data[10];
    struct node *left, *right;
} BTree;

void treeToE(BTree *bt)
{
    treeToExp(bt, 1);
}
void treeToExp(BTree *bt, int deep)
{
    if (bt == NULL) // 空结点返回
        return;
    else if (bt->left == NULL && bt->right == NULL) // 若为叶结点
        cout << bt->data;                           // 输出操作数
    else
    {
        if (deep > 1)
            cout << "(";
        treeToExp(bt->left, deep + 1);
        cout << bt->data;
        treeToExp(bt->right, deep + 1);
        if (deep > 1)
            cout << ")";
    }
}
/**/
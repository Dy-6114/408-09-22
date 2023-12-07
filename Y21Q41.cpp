/*题目：
已知无向连通图G由顶点集V和边集E组成，|E|>0,当G中度为奇数的顶点个数为不大于2的偶数时，
G存在包含所有边且长度为|E|的路径(称为EL路径)。设图G采用邻接矩阵存储。
typedef struct{
    int numVertices, numEdges; //实际的顶点数和边数
    char VerticesList[MAXV];   //顶点表
    int Edge[MAXV][MAXV];  //邻接矩阵
}MGragh;
设计算法int IsExistEL(MGragh G),存在返回1，否则返回0
*/
/*1.算法设计思路：
2.算法描述：如下代码
3.时间复杂度：O(n^2)
空间复杂度：O(1)
*/

#include <iostream>
using namespace std;
const int MAXV = 100;

typedef struct
{
    int numVertices, numEdges; // 实际的顶点数和边数
    char VerticesList[MAXV];   // 顶点表
    int Edge[MAXV][MAXV];      // 邻接矩阵
} MGragh;

int IsExistEL(MGragh G)
{
    int degree;
    int count = 0;
    for (int i = 0; i < G.numVertices; i++)
    {
        degree = 0;
        for (int j = 0; j < G.numVertices; j++)
        {
            if (G.Edge[i][j] > 0)
            {
                degree++;
            }
        }
        if (degree % 2 == 1)
            count++;
    }
    if (count == 0 || count == 2)
        return 1;
    return 0;
}
/**/
/*题目：已知有向图G采用邻接矩阵存储，类型定义如下：
typedef struct{ / 图的类型定义
    int numVertices, numEdges;  //图的顶点数和有向边数
    char VerticesList[ MAXV ]; //顶点表，MAXV 为已定义常量
    int Edge[ MAXV ][ MAXV ]; //邻接矩阵
}MGraph;
将图中出度大于入度的顶点称为K顶点。
请设计算法：int printVertices（MGraph G），对给定的任意非空有向图G，输出G中所有的K顶点，并返回K顶点的个数。要求：
1）给出算法的基本设计思想。
2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
*/
/*解答：
1.基本设计思想：二重遍历循环，分别计算顶点的入度和出度，出度为该顶点行矩阵的和，入度为该顶点列矩阵的和；
若出度大于入度，则输出该顶点，并计数器+1。
*/

#include <iostream>
using namespace std;
const int MAXV = 100;
typedef struct MGraph
{
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;

int printVertices(MGraph G)
{
    int indegree, outdegree;
    int count = 0;
    for (int i = 0; i < G.numVertices; i++)
    {
        indegree = outdegree = 0;
        for (int j = 0; j < G.numVertices; j++)
        {
            if (G.Edge[i][j] > 0)
                outdegree++;
            if (G.Edge[j][i] > 0)
                indegree++;
        }
        if (outdegree > indegree)
        {
            printf("%c", G.VerticesList[i]);
            count++;
        }
    }
    return count;
}

/**/
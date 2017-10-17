/*******************************************************************************************
【普里姆算法】
本算法以无向图为例，图的存储方式采用邻接矩阵
1)以第一个顶点开始本算法，将第一个顶点(i = 0)加入最小生成树集low_cost[i] = 0，0代表已经加入生成树集;
2)遍历第i行邻接矩阵，更新与顶点i有边的顶点的权值(该权值集的初始化值为与第一个顶点有边连接的顶点的权值)
3)遍历这个low_cost权值集合，找到最小权值并输出
为了找到与当前顶点有边的前一个顶点，算法用Vertex_Information[]进行了记录
Author:tmw
date:2017-10-17
********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100
#define inf 65535  //用65535代表无穷大
/*************************建立无向图邻接矩阵**************************/
typedef struct Matrix_Graph
{
    char vertex[MAX_VERTEX];//存储顶点信息
    int edge[MAX_VERTEX][MAX_VERTEX];//存储边信息
    int vertex_number,edge_number;//存储图中的顶点数和边数
}Matrix_Graph;
void create_non_direction_matrix_Graph( Matrix_Graph *G )
{
    int i,j,w,k;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&G->vertex_number,&G->edge_number);

    printf("请输入无向图顶点信息(如ABCD...)：\n");
    char ch;
    while( ( ch = getchar() ) != '\n' );
    for( i = 0 ; i < G->vertex_number ; i++ )
        scanf("%c",&G->vertex[i]);

    //初始化边信息
    for( i = 0 ; i < G->vertex_number ; i++ )
        for( j = 0 ; j < G->vertex_number ; j++ )
        {
            if( i == j )
                G->edge[i][j] = 0;
            else
                G->edge[i][j] = inf;
        }

    printf("请输入无向图中相连的两个顶点下标值(Vi,Vj)，以及权值---即边信息\n");
    for( k = 0 ; k < G->edge_number ; k++ )
    {
        scanf("%d %d %d",&i,&j,&w);
        G->edge[i][j] = w;
        G->edge[j][i] = G->edge[i][j];//由于是无向图，故是对称阵
    }
    //打印邻接矩阵
    for( i = 0 ; i < G->vertex_number ; i++ )
    {
        for( j = 0 ; j < G->vertex_number ; j++ )
            printf("%d\t",G->edge[i][j]);
        printf("\n");
    }
}
void Min_Create_Tree_Prim( Matrix_Graph *G )
{
    int i,j,min;
    int mark = 0;
    int low_cost[MAX_VERTEX];
    int Vertex_Information[MAX_VERTEX];//便于找到权值最小边的前一个顶点

    low_cost[0] = 0;     //low_cost记录已经用于生成最小生成树的顶点，若为0，则标记为用过
                        //这里从第一个顶点开始生成最小生成树，因此首先标记它为0
    for( i = 1 ; i < G->vertex_number ; i++ )//因为第一个顶点已经纳入生成树，因此从第二个顶点开始遍历
    {
        low_cost[i] = G->edge[0][i];//将与第一个顶点有边相连的顶点权值放入low_cost数组
        Vertex_Information[i] = 0; //初始化相关顶点的下标都从第一个顶点开始
    }
    for( i = 1 ; i < G->vertex_number ; i++ )
    {
        min = inf;
        j = 1;
        while( j < G->vertex_number )//找出与当前顶点权值最小的顶点
        {
            if( low_cost[j]!=0 && low_cost[j] < min )
            {
                min = low_cost[j];
                mark = j;//将最小权值顶点做个标记
            }
            j++;
        }
        low_cost[mark] = 0;//标记新加入顶点已经被加入生成树
        printf("[%d %d] ---",Vertex_Information[mark],mark);//打印顶点下标号
        printf("%c %c\n",G->vertex[Vertex_Information[mark]],G->vertex[mark]);//打印找到的当前顶点的最小权值边

        //找 与当前顶点和新加入顶点中 还相连的其他顶点
        for( j = 1 ; j < G->vertex_number ; j++ )
        {
            if( low_cost[j] != 0 && low_cost[j] > G->edge[mark][j] )//更新 与当前顶点和新加入顶点间 其他与之相连顶点的权值
            {
                low_cost[j] = G->edge[mark][j];
                Vertex_Information[j] = mark;//标记边的第一个顶点
            }
        }
    }
}
int main()
{
    Matrix_Graph *G;
    G = (Matrix_Graph*)malloc(sizeof(Matrix_Graph));
    create_non_direction_matrix_Graph(G);
    Min_Create_Tree_Prim(G);
    return 0;
}

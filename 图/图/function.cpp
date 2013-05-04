#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>

int visited[MAXV];	/*遍历图所要维持的一个数据结构*/

/*从文件读出邻接矩阵 建造邻接矩阵表示的图 ！！！调试特用非通用！！！*/
MGraph * createMGraph( char * filename )
{
	FILE * file;
	MGraph * graph;
	int i = 0, j = 0;

	file = fopen( filename, "r" );
	if( file == NULL )
		return NULL;
	
	graph = ( MGraph * )malloc( sizeof( MGraph ) );
	graph->e = 5;	/*五条边*/
	graph->n = 5;	/*5个顶点*/

	for( i = 0; i < 5; i ++ )
		for( j = 0; j < 5; j ++ )
			fscanf( file, "%d", &graph->edges[i][j] );

	fclose( file );

	return graph;
}


/*邻接矩阵转换为邻接表*/
void MatToList( MGraph * g, ALGraph * &G )
{
	int i, j, n = g->n;	/*n为顶点数*/
	ArcNode * p;

	G = ( ALGraph * )malloc( sizeof( ALGraph ) );
	
	for( i = 0; i < 5; i ++ )
		G->adjlist[i].firstarc = NULL;	/*表头结点的指针初始化为空*/

	for( i = 0; i< n; i ++ )
	{
		G->adjlist[i].data = i;
		for( j = 0; j < n; j ++ )
		{
			if( g->edges[i][j] == 1 && i != j )
			{
				p = ( ArcNode * )malloc( sizeof( ArcNode ) );
				p->adjvex = j;
				/*尾插*/
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}

	G->n = n;
	G->e =g->e;
}
/*从某一个结点开始深度优先遍历 递归*/
void DFS( ALGraph * g, int v )
{
	ArcNode * p = g->adjlist[v].firstarc;

	printf( "%d ", g->adjlist[v].data );
	visited[v] = 1;	/*已访问*/

	while( p != NULL )
	{
		if( visited[p->adjvex] != 1 )
			BFS( g, p->adjvex );
		p = p->nextarc;
	}

}

/*从某一个结点开始广度优先遍历 递归*/
void BFS( ALGraph * g, int v )
{
	int queue[MAXV];	/*循环队列*/
	int rear = 0, front = 0;
	int i;
	ArcNode * p = NULL;
	rear = ( rear + 1 ) % MAXV;
	queue[rear] = v;
	visited[v] = 1;	/*进过栈*/

	while( rear != front )
	{
		/*取元素*/
		front = ( front + 1 ) % MAXV;
		i = queue[front];
		/*访问*/
		printf( "%d ", g->adjlist[i].data);

		p = g->adjlist[i].firstarc;
		while( p != NULL )	/*不空*/
		{
			if( visited[p->adjvex] != 1 )	/*未进过栈*/
			{
				visited[p->adjvex] = 1;
				rear = ( rear + 1 ) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
			
	}
}

/*弗洛伊德算法求最短路径*/
 void Floyd( MGraph * mg )
 {
	 int i, j, k;
	 int A[MAXV][MAXV], path[MAXV][MAXV];
	 for( i = 0; i < mg->n; i ++ )	/*初始化*/
		 for( j = 0; j < mg->n; j ++ )
		 {
			 A[i][j] = mg->edges[i][j];
			 path[i][j] = -1;
		 }

	 for( k = 0; k < mg->n; k ++ )
		 for( i = 0; i < mg->n; i ++ )
			 for( j = 0; j < mg->n; j ++ )
				 if( A[i][j] > A[i][k] + A[k][j] )
				 {
					 A[i][j] = A[i][k] + A[k][j];
					 path[i][j] = k;
				 }
	

	Dispath( A, path, mg->n );
 }

 /*输出最短路径*/
 void Ppath( int path[][MAXV], int i, int j )
 {
	 int k = path[i][j];
	 if( k == -1 )
		return;
	 Ppath( path, i, k );
	 printf( "%d ", k );
	 Ppath( path, k, j );
 }

 void Dispath( int A[][MAXV], int path[][MAXV], int n )
 {
	 int i, j;
	 for( i = 0; i < n; i ++ )
		 for( j = 0; j < n; j ++ )
		 {
			 if( A[i][j] == INF )
			 {
				 if( i != j )
					 printf( "从%d到%d之间没有路径\n", i, j );
			 }
			 printf( "从%d到%d的最短路径为:", i, j );
			 printf( "%d ", i );
			 Ppath( path, i, j );
			 printf( "%d	", j );
			 printf( "路径最短长度为%d\n", A[i][j] );

		 }
 }

/*求无向图的连通分量个数*/
int ConnNum( ALGraph * alg )
{
	int i, cnt = 0;
	for( i = 0; i < alg->n; i ++ )
		visited[i] = 0;

	for( i = 0; i < alg->n; i ++ )
		if( visited[i] == 0 )	/*i没有访问过*/
		{
			BFS( alg, i );	/*从i开始访问*/
			cnt ++;
		}
	return cnt;
} 
/*普里姆算法求带权无向图的最小生成树*/
void Prim( MGraph mg, int v )
{
	int lowcost[MAXV];		/*候选边表*/
	int min;
	int closest[MAXV], i, j, k;
	for( i = 0; i < mg.n; i ++ )	/*给lowcost和closest置初值*/
	{
		lowcost[i] = mg.edges[v][i];
		closest[i] = v;
	}
	for( i = 1; i < mg.n; i ++ )	/*找出其余n-1个顶点加入closest集合*/
	{
		min = INF;
		for( j = 0; j < mg.n; j ++ )	/*在(V-U)中找出离U最近的顶点k*/
			if( lowcost[j] != 0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;
			}
			printf( "边(%d, %d)权为:%d\n", closest[k], k, min );
			lowcost[k] = 0;	/*标记k已经加入U*/
			for( j = 0; j < mg.n; j ++ )
				if( mg.edges[k][j] != 0 && mg.edges[k][j] < lowcost[j] )
				{
					lowcost[j] = mg.edges[k][j];
					closest[j] = k;
				}
	}
}
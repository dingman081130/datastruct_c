#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>

int visited[MAXV];	/*����ͼ��Ҫά�ֵ�һ�����ݽṹ*/

/*���ļ������ڽӾ��� �����ڽӾ����ʾ��ͼ �������������÷�ͨ�ã�����*/
MGraph * createMGraph( char * filename )
{
	FILE * file;
	MGraph * graph;
	int i = 0, j = 0;

	file = fopen( filename, "r" );
	if( file == NULL )
		return NULL;
	
	graph = ( MGraph * )malloc( sizeof( MGraph ) );
	graph->e = 5;	/*������*/
	graph->n = 5;	/*5������*/

	for( i = 0; i < 5; i ++ )
		for( j = 0; j < 5; j ++ )
			fscanf( file, "%d", &graph->edges[i][j] );

	fclose( file );

	return graph;
}


/*�ڽӾ���ת��Ϊ�ڽӱ�*/
void MatToList( MGraph * g, ALGraph * &G )
{
	int i, j, n = g->n;	/*nΪ������*/
	ArcNode * p;

	G = ( ALGraph * )malloc( sizeof( ALGraph ) );
	
	for( i = 0; i < 5; i ++ )
		G->adjlist[i].firstarc = NULL;	/*��ͷ����ָ���ʼ��Ϊ��*/

	for( i = 0; i< n; i ++ )
	{
		G->adjlist[i].data = i;
		for( j = 0; j < n; j ++ )
		{
			if( g->edges[i][j] == 1 && i != j )
			{
				p = ( ArcNode * )malloc( sizeof( ArcNode ) );
				p->adjvex = j;
				/*β��*/
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}

	G->n = n;
	G->e =g->e;
}
/*��ĳһ����㿪ʼ������ȱ��� �ݹ�*/
void DFS( ALGraph * g, int v )
{
	ArcNode * p = g->adjlist[v].firstarc;

	printf( "%d ", g->adjlist[v].data );
	visited[v] = 1;	/*�ѷ���*/

	while( p != NULL )
	{
		if( visited[p->adjvex] != 1 )
			BFS( g, p->adjvex );
		p = p->nextarc;
	}

}

/*��ĳһ����㿪ʼ������ȱ��� �ݹ�*/
void BFS( ALGraph * g, int v )
{
	int queue[MAXV];	/*ѭ������*/
	int rear = 0, front = 0;
	int i;
	ArcNode * p = NULL;
	rear = ( rear + 1 ) % MAXV;
	queue[rear] = v;
	visited[v] = 1;	/*����ջ*/

	while( rear != front )
	{
		/*ȡԪ��*/
		front = ( front + 1 ) % MAXV;
		i = queue[front];
		/*����*/
		printf( "%d ", g->adjlist[i].data);

		p = g->adjlist[i].firstarc;
		while( p != NULL )	/*����*/
		{
			if( visited[p->adjvex] != 1 )	/*δ����ջ*/
			{
				visited[p->adjvex] = 1;
				rear = ( rear + 1 ) % MAXV;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
			
	}
}

/*���������㷨�����·��*/
 void Floyd( MGraph * mg )
 {
	 int i, j, k;
	 int A[MAXV][MAXV], path[MAXV][MAXV];
	 for( i = 0; i < mg->n; i ++ )	/*��ʼ��*/
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

 /*������·��*/
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
					 printf( "��%d��%d֮��û��·��\n", i, j );
			 }
			 printf( "��%d��%d�����·��Ϊ:", i, j );
			 printf( "%d ", i );
			 Ppath( path, i, j );
			 printf( "%d	", j );
			 printf( "·����̳���Ϊ%d\n", A[i][j] );

		 }
 }

/*������ͼ����ͨ��������*/
int ConnNum( ALGraph * alg )
{
	int i, cnt = 0;
	for( i = 0; i < alg->n; i ++ )
		visited[i] = 0;

	for( i = 0; i < alg->n; i ++ )
		if( visited[i] == 0 )	/*iû�з��ʹ�*/
		{
			BFS( alg, i );	/*��i��ʼ����*/
			cnt ++;
		}
	return cnt;
} 
/*����ķ�㷨���Ȩ����ͼ����С������*/
void Prim( MGraph mg, int v )
{
	int lowcost[MAXV];		/*��ѡ�߱�*/
	int min;
	int closest[MAXV], i, j, k;
	for( i = 0; i < mg.n; i ++ )	/*��lowcost��closest�ó�ֵ*/
	{
		lowcost[i] = mg.edges[v][i];
		closest[i] = v;
	}
	for( i = 1; i < mg.n; i ++ )	/*�ҳ�����n-1���������closest����*/
	{
		min = INF;
		for( j = 0; j < mg.n; j ++ )	/*��(V-U)���ҳ���U����Ķ���k*/
			if( lowcost[j] != 0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;
			}
			printf( "��(%d, %d)ȨΪ:%d\n", closest[k], k, min );
			lowcost[k] = 0;	/*���k�Ѿ�����U*/
			for( j = 0; j < mg.n; j ++ )
				if( mg.edges[k][j] != 0 && mg.edges[k][j] < lowcost[j] )
				{
					lowcost[j] = mg.edges[k][j];
					closest[j] = k;
				}
	}
}
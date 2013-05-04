#define MAXV 8
#define INF 32767

typedef int InfoType;
typedef int Vertex;

typedef struct
{
	int no;			/*顶点编号*/
	InfoType info;	/*顶点其他信息*/
}VertexType;		/*顶点类型*/

typedef struct
{
	int edges[MAXV][MAXV];	/*邻接矩阵*/
	int n, e;				/*顶点数 弧数*/
	VertexType vex[MAXV];	/*存放顶点信息*/
}MGraph;					/*图的邻接矩阵表示类型*/

typedef struct ANode
{
	int adjvex;				/*该弧的终点位置*/
	struct ANode * nextarc;	/*指向下一条弧的指针*/
	InfoType info;			/*该弧的相关信息*/
}ArcNode;					/*弧的节点结构类型*/

typedef struct VNode
{
	Vertex data;			/*顶点信息*/
	ArcNode * firstarc;		/*指向第一条弧*/
}VNode;						/*邻接表头结点的类型*/

typedef VNode AdjList[MAXV];	/*AdjList是邻接表类型*/

typedef struct
{
	AdjList adjlist;	/*邻接表*/
	int n, e;			/*图中的顶点数与边数*/
}ALGraph;				/*图的邻接表表示类型*/

/*从文件读出邻接矩阵 建造邻接矩阵表示的图*/
MGraph * createMGraph( char * filename );
/*邻接矩阵转换为邻接表*/
void MatToList( MGraph * g, ALGraph * &G );
/*从某一个结点开始广度优先遍历 递归*/
void DFS( ALGraph * g, int v );
/*从某一个结点开始深度优先遍历 递归*/
void BFS( ALGraph * g, int v );
/*弗洛伊德算法求最短路径*/
void Floyd( MGraph * mg );
/*输出最短路径*/
void Ppath( int path[][MAXV], int i, int j );
void Dispath( int A[][MAXV], int path[][MAXV], int n );
/*求无向图的连通分量个数*/
int ConnNum( ALGraph * alg );
/*普里姆算法求带权无向图的最小生成树*/
void Prim( MGraph mg, int v );
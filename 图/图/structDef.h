#define MAXV 8
#define INF 32767

typedef int InfoType;
typedef int Vertex;

typedef struct
{
	int no;			/*������*/
	InfoType info;	/*����������Ϣ*/
}VertexType;		/*��������*/

typedef struct
{
	int edges[MAXV][MAXV];	/*�ڽӾ���*/
	int n, e;				/*������ ����*/
	VertexType vex[MAXV];	/*��Ŷ�����Ϣ*/
}MGraph;					/*ͼ���ڽӾ����ʾ����*/

typedef struct ANode
{
	int adjvex;				/*�û����յ�λ��*/
	struct ANode * nextarc;	/*ָ����һ������ָ��*/
	InfoType info;			/*�û��������Ϣ*/
}ArcNode;					/*���Ľڵ�ṹ����*/

typedef struct VNode
{
	Vertex data;			/*������Ϣ*/
	ArcNode * firstarc;		/*ָ���һ����*/
}VNode;						/*�ڽӱ�ͷ��������*/

typedef VNode AdjList[MAXV];	/*AdjList���ڽӱ�����*/

typedef struct
{
	AdjList adjlist;	/*�ڽӱ�*/
	int n, e;			/*ͼ�еĶ����������*/
}ALGraph;				/*ͼ���ڽӱ��ʾ����*/

/*���ļ������ڽӾ��� �����ڽӾ����ʾ��ͼ*/
MGraph * createMGraph( char * filename );
/*�ڽӾ���ת��Ϊ�ڽӱ�*/
void MatToList( MGraph * g, ALGraph * &G );
/*��ĳһ����㿪ʼ������ȱ��� �ݹ�*/
void DFS( ALGraph * g, int v );
/*��ĳһ����㿪ʼ������ȱ��� �ݹ�*/
void BFS( ALGraph * g, int v );
/*���������㷨�����·��*/
void Floyd( MGraph * mg );
/*������·��*/
void Ppath( int path[][MAXV], int i, int j );
void Dispath( int A[][MAXV], int path[][MAXV], int n );
/*������ͼ����ͨ��������*/
int ConnNum( ALGraph * alg );
/*����ķ�㷨���Ȩ����ͼ����С������*/
void Prim( MGraph mg, int v );
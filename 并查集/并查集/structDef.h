#define MaxSize 10
typedef struct node
{
	int data;	/*结点对应人的编号*/
	int rank;	/*节点对应秩*/
	int parent;	/*节点对应双亲下标*/
}UFSTree;	/*并查集树的结点类型*/

/*初始化并查集树*/
void MakeSet( UFSTree t[], int n );
/*查找一个元素所属的集合*/
int FindSet( UFSTree t[], int x );
/*两个元素各自所属的集合合并*/
void Union( UFSTree t[], int x, int y );
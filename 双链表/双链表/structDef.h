typedef char ElemType;

typedef struct DNode
{
	ElemType data;
	int freq;	/*访问频度*/
	struct DNode * prior;
	struct DNode * next;
}DLinkList;

/*头插法建立带头结点的双向链表*/
void CreateListF( DLinkList * & L, ElemType a[], int n );
/*访问值为x的结点 频度加1 频度递减调整*/
int LocalNode( DLinkList * h, ElemType x );
/*输出链表*/
void DispList( DLinkList * h );
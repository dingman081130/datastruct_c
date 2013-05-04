/*数据元素类型的定义*/
typedef char ElemType;

/*单链表节点的定义*/
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkList;

/*单聊表操作函数的声明*/
void CreateListF( LinkList * &L, ElemType a[], int n );
void CreateListR( LinkList * &L, ElemType a[], int n );
void DestroyList( LinkList * L );
int ListLength( LinkList * L );
void DispList( LinkList * L );
int GetElem( LinkList * L, int i, ElemType & e );
void FindKRev( LinkList * L, int k, int & i );
void Reverse( LinkList * L );	/*将带表头结点的单链表倒置*/
int SubMatch( LinkList * L1, LinkList * L2 );	/*带头结点的链串的子串匹配*/
/*将一个不带头结点的字符单链表分割成带头结点的字母字符循环单链表数字字符循环单链表和其他字符循环单链表*/
void oneToThree( LinkList * l, LinkList * & l1, LinkList * & l2, LinkList * & l3 );
/*将带头结点的链表转换为不带头结点的链表*/
LinkList * putOffHead( LinkList * &l );
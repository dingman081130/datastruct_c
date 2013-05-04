/*����Ԫ�����͵Ķ���*/
typedef char ElemType;

/*������ڵ�Ķ���*/
typedef struct LNode
{
	ElemType data;
	struct LNode * next;
}LinkList;

/*���ı��������������*/
void CreateListF( LinkList * &L, ElemType a[], int n );
void CreateListR( LinkList * &L, ElemType a[], int n );
void DestroyList( LinkList * L );
int ListLength( LinkList * L );
void DispList( LinkList * L );
int GetElem( LinkList * L, int i, ElemType & e );
void FindKRev( LinkList * L, int k, int & i );
void Reverse( LinkList * L );	/*������ͷ���ĵ�������*/
int SubMatch( LinkList * L1, LinkList * L2 );	/*��ͷ�����������Ӵ�ƥ��*/
/*��һ������ͷ�����ַ�������ָ�ɴ�ͷ������ĸ�ַ�ѭ�������������ַ�ѭ��������������ַ�ѭ��������*/
void oneToThree( LinkList * l, LinkList * & l1, LinkList * & l2, LinkList * & l3 );
/*����ͷ��������ת��Ϊ����ͷ��������*/
LinkList * putOffHead( LinkList * &l );
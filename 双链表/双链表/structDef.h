typedef char ElemType;

typedef struct DNode
{
	ElemType data;
	int freq;	/*����Ƶ��*/
	struct DNode * prior;
	struct DNode * next;
}DLinkList;

/*ͷ�巨������ͷ����˫������*/
void CreateListF( DLinkList * & L, ElemType a[], int n );
/*����ֵΪx�Ľ�� Ƶ�ȼ�1 Ƶ�ȵݼ�����*/
int LocalNode( DLinkList * h, ElemType x );
/*�������*/
void DispList( DLinkList * h );
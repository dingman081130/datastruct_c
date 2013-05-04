#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>

/*ͷ�巨������ͷ����˫������*/
void CreateListF( DLinkList * & L, ElemType a[], int n )
{
	DLinkList * s;
	int i = 0;
	L = ( DLinkList * )malloc( sizeof( DLinkList ) );
	L->next = L->prior = NULL;

	while( i < n )
	{
		s = ( DLinkList * )malloc( sizeof( DLinkList ) );
		s->data = a[i];
		s->freq = 0;
		s->next = L->next;
		s->prior = L;
		if( L->next != NULL )
		{
			L->next->prior = s;
		}
		L->next = s;
		i ++;
	}
}
/*����ֵΪx�Ľ�� Ƶ�ȼ�1 Ƶ�ȵݼ�����*/
int LocalNode( DLinkList * h, ElemType x )
{
	DLinkList * p = h->next, * q;
	while( p != NULL && p->data != x )	/*����ֵΪx�Ľ��*/
		p = p->next;
	if( p == NULL )	/*����ʧ��*/
		return 0;
	p->freq ++;
	if( p != h->next )	/*���Ϊ��һ�����ݽ�� ������*/
	{
		q = p->prior;
		while( q != h && q->freq < p->freq )
		{
			q->prior->next = p;
			if( p->next != NULL )
				p->next->prior = q;
			q->next = p->next;
			p->next = q;
			p->prior = q->prior;
			q->prior = p;

			q = p->prior;
		}
	}
	return 1;
}
/*�������*/
void DispList( DLinkList * h )
{
	DLinkList * p = h->next;
	while( p != NULL )
	{
		printf( "%c ", p->data );
		p = p->next;
	}
	printf( "\n" );
}
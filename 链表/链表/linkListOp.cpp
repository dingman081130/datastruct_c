#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>
/***********************
***   �������������
***********************/

/*ͷ�巨����������*/
void CreateListF( LinkList * &L, ElemType a[], int n )
{
	LinkList * s;
	int i;
	L = ( LinkList * )malloc( sizeof( LinkList ) );	/*����ͷ���*/
	L->next = NULL;
	for( i = 0; i < n; i ++ )
	{
			s = ( LinkList * )malloc( sizeof( LinkList ) );	/*�����½��*/
			s->data = a[i];
			s->next = L->next;
			L->next = s;
	}
}

/*β�巨����������*/
void CreateListR( LinkList * &L, ElemType a[], int n )
{
	LinkList * s, * r;	/*�ڽ���������ά��һ��βָ��*/
	int i;
	L = ( LinkList * )malloc( sizeof( LinkList ) );	/*����ͷ���*/
	r = L;
	for( i = 0; i < n; i ++ )
	{
		s = ( LinkList * )malloc( sizeof( LinkList ) );
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

/*�������ͱ�*/
void DestroyList( LinkList * L )
{
	LinkList * p = L, * q = p->next;
	while( q != NULL )
	{
		free( p );
		p = q;
		q = p->next;
	}
	free( p );
}

/*������ĳ���*/
int ListLength( LinkList * L )
{
	LinkList * p = L;
	int cnt = 0;
	while( p->next != NULL )
	{
		cnt ++;
		p = p->next;
	}
	return cnt;
}

/*��ʾ����*/
void DispList( LinkList * L )
{
	LinkList * p = L->next;
	while( p != NULL )
	{
		printf( "%c --> ", p->data );
		p = p->next;
	}
	printf( "NULL\n" );
}

/*�����Ա��е�i��Ԫ��*/
int GetElem( LinkList * L, int i, ElemType & e )
{
	int j = 0;
	LinkList * p = L;
	while( j < i && p != NULL )
	{
		j ++;
		p = p->next;
	}
	if( p == NULL )
		return 0;
	else
	{
		e = p->data;
		return 1;
	}
}

/*�ݹ���ҵ�����k��Ԫ��*/
void FindKRev( LinkList * L, int k, int & i )
{
	if( L != NULL )
	{
		FindKRev( L->next, k, i );
		i ++;
		if( i == k )
			printf( "%c\n", L->data );
	}
}

/*����ͷ���ĵ�������*/
void Reverse( LinkList * L )
{
	LinkList * p, * q;
	if( L->next == NULL )
		printf( "������\n" );
	else
	{
		p = L->next;
		L->next = NULL;
		while( p != NULL )
		{
			q = p->next;
			p->next = L->next;
			L->next = p;
			p = q;
		}
	}
}

/*��ͷ�����������Ӵ�ƥ��*/
int SubMatch( LinkList * L1, LinkList * L2 )
{
	LinkList * p = L1->next, * q = L2->next, * s;
	while( p != NULL )
	{
		s = p;
		while( q != NULL && s != NULL )
		{
			if( q->data == s->data )
			{
				q = q->next;
				s = s->next;
			}
			else
				break;
		}
		if( q == NULL )
			return 1;	/*ƥ��ɹ�*/
		else
		{
			p = p->next;
			q = L2->next;
		}
	}
	return 0;	/*ƥ��ʧ��*/
}

/*��һ������ͷ�����ַ�������ָ�ɴ�ͷ������ĸ�ַ�ѭ�������������ַ�ѭ��������������ַ�ѭ��������*/
void oneToThree( LinkList * l, LinkList * & l1, LinkList * & l2, LinkList * & l3 )
{
	LinkList * tmp;
	l1 = ( LinkList * )malloc( sizeof( LinkList ) );
	l2 = ( LinkList * )malloc( sizeof( LinkList ) );
	l3 = ( LinkList * )malloc( sizeof( LinkList ) );

	l1->next = l1; l2->next = l2; l3->next = l3;	/*ѭ��������ͷ���*/

	while( l != NULL )
	{
		tmp = l->next;
		if( ( l->data >= 'A' && l->data <= 'Z' )	/*��ĸ�ַ�*/
			|| ( l->data >= 'a' && l->data <= 'z' ) )
		{
			l->next = l1->next;
			l1->next = l;
		}
		else if( l->data >= '0' && l->data <= '9' )	/*�����ַ�*/
		{
			l->next = l2->next;
			l2->next = l;
		}
		else	/*�����ַ�*/
		{
			l->next = l3->next;
			l3->next = l;
		}
		l = tmp;
	}
}

/*����ͷ��������ת��Ϊ����ͷ��������*/
LinkList * putOffHead( LinkList * &l )
{
	LinkList * tmp;
	tmp = l->next;
	free( l );	/*�ͷ�ͷ���*/
	l = tmp;
	return l;
}
#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>
/***********************
***   单链表操作函数
***********************/

/*头插法建立单链表*/
void CreateListF( LinkList * &L, ElemType a[], int n )
{
	LinkList * s;
	int i;
	L = ( LinkList * )malloc( sizeof( LinkList ) );	/*创建头结点*/
	L->next = NULL;
	for( i = 0; i < n; i ++ )
	{
			s = ( LinkList * )malloc( sizeof( LinkList ) );	/*创建新结点*/
			s->data = a[i];
			s->next = L->next;
			L->next = s;
	}
}

/*尾插法建立单链表*/
void CreateListR( LinkList * &L, ElemType a[], int n )
{
	LinkList * s, * r;	/*在建立过程中维持一个尾指针*/
	int i;
	L = ( LinkList * )malloc( sizeof( LinkList ) );	/*创建头结点*/
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

/*销毁线型表*/
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

/*求链表的长度*/
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

/*显示链表*/
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

/*求线性表中第i个元素*/
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

/*递归查找倒数第k个元素*/
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

/*将带头结点的单链表倒置*/
void Reverse( LinkList * L )
{
	LinkList * p, * q;
	if( L->next == NULL )
		printf( "空链表\n" );
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

/*带头结点的链串的子串匹配*/
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
			return 1;	/*匹配成功*/
		else
		{
			p = p->next;
			q = L2->next;
		}
	}
	return 0;	/*匹配失败*/
}

/*将一个不带头结点的字符单链表分割成带头结点的字母字符循环单链表数字字符循环单链表和其他字符循环单链表*/
void oneToThree( LinkList * l, LinkList * & l1, LinkList * & l2, LinkList * & l3 )
{
	LinkList * tmp;
	l1 = ( LinkList * )malloc( sizeof( LinkList ) );
	l2 = ( LinkList * )malloc( sizeof( LinkList ) );
	l3 = ( LinkList * )malloc( sizeof( LinkList ) );

	l1->next = l1; l2->next = l2; l3->next = l3;	/*循环单链表头结点*/

	while( l != NULL )
	{
		tmp = l->next;
		if( ( l->data >= 'A' && l->data <= 'Z' )	/*字母字符*/
			|| ( l->data >= 'a' && l->data <= 'z' ) )
		{
			l->next = l1->next;
			l1->next = l;
		}
		else if( l->data >= '0' && l->data <= '9' )	/*数字字符*/
		{
			l->next = l2->next;
			l2->next = l;
		}
		else	/*其他字符*/
		{
			l->next = l3->next;
			l3->next = l;
		}
		l = tmp;
	}
}

/*将带头结点的链表转换为不带头结点的链表*/
LinkList * putOffHead( LinkList * &l )
{
	LinkList * tmp;
	tmp = l->next;
	free( l );	/*释放头结点*/
	l = tmp;
	return l;
}
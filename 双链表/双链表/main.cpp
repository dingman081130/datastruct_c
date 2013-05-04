#include"structDef.h"
#include<stdio.h>

void main()
{
	DLinkList * L;
	ElemType a[] = { 'a', 'b', 'c', 'd' };
	CreateListF( L, a, 4 );
	LocalNode( L, 'b' );
	DispList( L );
	LocalNode( L, 'a' );
	DispList( L );
	LocalNode( L, 'a' );
	DispList( L );
	printf( "" );
}
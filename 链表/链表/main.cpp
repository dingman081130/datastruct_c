#include"structDef.h"
#include<stdlib.h>

void main()
{
	LinkList * l, * l1, * l2, * l3;
	ElemType a[] = { 'a', 'b', '1', '$', '8', '-', '5', 'a' };
	CreateListR( l, a, 8 );
	DispList( l );
	l = putOffHead( l );
	DispList( l );
	oneToThree( l, l1, l2, l3 );
	DispList( l1 );
	DispList( l3 );
	SubMatch( l1, l2 );
}
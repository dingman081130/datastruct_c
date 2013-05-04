#include"structDef.h"
#include<stdio.h>

void main()
{
	BTNode * bTree1 = NULL, * p;
	ElemType path[MaxSize];
	int pathLen = 0;
	int h;

	ElemType * str = "a(b(d(,e(f(,g(,h(i)))))),c)";

	CreateBTNode( bTree1, str );
	h = height( bTree1 );
	p = PostFirst( bTree1 );
	printf( "hello" );
}
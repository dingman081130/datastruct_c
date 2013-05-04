#include<stdio.h>
#include"structDef.h"

void main()
{
	RecType a[10];
	int i;
	for( i = 0; i < 10; i ++ )
		a[i].key = 9 - i;
	::BubbleSort2( a, 10 );
	printf( "" );
}
#include"structDef.h"
#include<stdio.h>

void main()
{
	SqQueue * q;
	char ch;

	InitQueue( q );
	enQueue( q, 'a' );
	enQueue( q, 'b' );
	enQueue( q, 'c' );
	enQueue( q, 'd' );
	enQueue( q, 'e' );
	deQueue( q, ch );
	enQueue( q, 'f' );
	enQueue( q, 'g' );
	deQueue( q, ch );
	deQueue( q, ch );
	deQueue( q, ch );
	deQueue( q, ch );
}
#include"head.h"
#include<stdio.h>

/*���������ַ�����'.'��β�������ӡ*/
void reverse()
{
	char ch;
	if( ( ch = getchar() ) != '.' )
	{
		reverse();
		printf( "%c", ch );
	}
}
/*1/n�������*/
double f( int n )
{
	if( n > 1 )
		return f( n-1 ) + 1.0/n;
	return 1;
}
#include"head.h"
#include<stdio.h>

/*读入任意字符串以'.'结尾，倒序打印*/
void reverse()
{
	char ch;
	if( ( ch = getchar() ) != '.' )
	{
		reverse();
		printf( "%c", ch );
	}
}
/*1/n级数求和*/
double f( int n )
{
	if( n > 1 )
		return f( n-1 ) + 1.0/n;
	return 1;
}
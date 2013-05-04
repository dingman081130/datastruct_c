#include"structDef.h"
#include<stdio.h>

/*将中缀表达式转换为后缀表达式打印*/
void Trans( char * exp )
{
	SqStack opStack;
	char postexp[MaxSize];
	char * exp1 = exp;
	int indicator = 0;
	opStack.top = -1;	/*初始化操作符栈*/
	
	while( *exp1 != '\0' )
	{
		switch( *exp1 )
		{
		case '(':
			opStack.data[++opStack.top] = *exp1;
			exp1 ++;
			break;
		case ')':
			while( opStack.data[opStack.top] != '(' )
			{
				postexp[indicator++] = opStack.data[opStack.top--];
			}
			opStack.top --;	/*将'('从操作符栈中删除*/
			exp1 ++;
			break;
		case '+':
		case '-':
			while( opStack.top != -1 && opStack.data[opStack.top] != '(' )
			{
				postexp[indicator++] = opStack.data[opStack.top--];
			}
			opStack.data[++opStack.top] = *exp1;
			exp1 ++;
			break;
		case '*':
		case '/':
			while( opStack.data[opStack.top] == '*' || opStack.data[opStack.top] == '/' )
			{
				postexp[indicator++] = opStack.data[opStack.top--];
			}
			opStack.data[++opStack.top] = *exp1;
			exp1 ++;
			break;
		case ' ':	break;
		default:
			postexp[indicator++] = *exp1;
			exp1 ++;
		}
	}
	while( opStack.top != -1 )
	{
		postexp[indicator++] = opStack.data[opStack.top--];
	}
	postexp[indicator] = '\0';
	printf( "表达式 %s 的后缀表达式为 %s \n", exp, postexp );
}

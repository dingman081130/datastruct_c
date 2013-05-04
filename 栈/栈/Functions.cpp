#include"structDef.h"
#include<stdio.h>

/*����׺���ʽת��Ϊ��׺���ʽ��ӡ*/
void Trans( char * exp )
{
	SqStack opStack;
	char postexp[MaxSize];
	char * exp1 = exp;
	int indicator = 0;
	opStack.top = -1;	/*��ʼ��������ջ*/
	
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
			opStack.top --;	/*��'('�Ӳ�����ջ��ɾ��*/
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
	printf( "���ʽ %s �ĺ�׺���ʽΪ %s \n", exp, postexp );
}

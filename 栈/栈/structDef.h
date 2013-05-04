#define MaxSize 128

typedef char ElemType;

/*顺序栈类型定义*/
typedef struct
{
	ElemType data[MaxSize];
	int top;	/*栈指针*/
}SqStack;

void Trans( char * exp );	/*将中缀表达式转换为后缀表达式打印*/

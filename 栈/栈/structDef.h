#define MaxSize 128

typedef char ElemType;

/*˳��ջ���Ͷ���*/
typedef struct
{
	ElemType data[MaxSize];
	int top;	/*ջָ��*/
}SqStack;

void Trans( char * exp );	/*����׺���ʽת��Ϊ��׺���ʽ��ӡ*/

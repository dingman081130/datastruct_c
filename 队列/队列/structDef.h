#define MaxSize 5
typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue( SqQueue * &q );
void ClearQueue( SqQueue * &q );
int QueueEmpty( SqQueue * q );
int enQueue( SqQueue * q, ElemType e );
int deQueue( SqQueue * q, ElemType &e );
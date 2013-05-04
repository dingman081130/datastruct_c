typedef int KeyType;
typedef char * InfoType;

typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

/*ֱ�Ӳ�������*/
void InsertSort( RecType R[], int n );
/*ϣ������*/
void ShellSort( RecType R[], int n );
/*ð������*/
void BubbleSort( RecType R[], int n );
/*˫��ð������*/
void BubbleSort2( RecType R[], int n );
/*��������*/
void QuickSort( RecType R[], int front, int rear );
#define MaxSize 10
typedef struct node
{
	int data;	/*����Ӧ�˵ı��*/
	int rank;	/*�ڵ��Ӧ��*/
	int parent;	/*�ڵ��Ӧ˫���±�*/
}UFSTree;	/*���鼯���Ľ������*/

/*��ʼ�����鼯��*/
void MakeSet( UFSTree t[], int n );
/*����һ��Ԫ�������ļ���*/
int FindSet( UFSTree t[], int x );
/*����Ԫ�ظ��������ļ��Ϻϲ�*/
void Union( UFSTree t[], int x, int y );
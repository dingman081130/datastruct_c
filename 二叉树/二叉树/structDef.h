#define MaxSize 128
#define Formation %c
typedef char ElemType;

typedef struct node
{
	ElemType data;
	struct node * lchild, * rchild;
}BTNode;

void CreateBTNode( BTNode * &b, char * str );
void LevelOrder( BTNode * b );
void PreOrder( BTNode * b );
void InOrder( BTNode * b );
void PostOrder( BTNode * b );

void PreOrder1( BTNode * b );	/*�ǵݹ��������*/
void PostOrder1( BTNode * b );	/*�ǵݹ�������*/

/*���Ϸǵݹ����*/
void PreOrderD( BTNode * b );	/*�ǵݹ��������*/
void InOrderD( BTNode * b );	/*�ǵݹ��������*/
void PostOrderD( BTNode * b );	/*�ǵݹ�������*/

/*Ѱ��Ԫ��ch�����ز���*/
int findElem( BTNode * b, ElemType x );
/*�ݹ�Ѱ��Ԫ��ch�����ص�ַ*/
BTNode * findElem1( BTNode * b, ElemType x );
/*�ж����ö������Ƿ�����*/
int like( BTNode * b1, BTNode * b2 );
/*�ݹ���ڵ����*/
int getNum( BTNode * b );
/*�ݹ���Ҷ�ڵ����*/
int getLeafNum( BTNode * b );
/*�ݹ����Ϊ1�Ľڵ�*/
int getNum1( BTNode * b );
/*�ݹ����Ϊ2�Ľڵ�*/
int getNum2( BTNode * b );
/*�����ͷ����нڵ�*/
void release( BTNode * &b );
/*�ݹ�ʵ��֪��Ҷ�ڵ�ֵ ����ڵ�ֵ*/
int getSumValue( BTNode * b );
/*Ѱ�����е��·��*/
void longestPath( BTNode * b );
/*������ڵ㵽����Ҷ�ڵ��·��*/
void leafPath( BTNode * b );
/*�ݹ�������ڵ㵽����Ҷ�ڵ��·��*/
void leafPathRec( BTNode * b );
/*�ж϶������Ƿ�Ϊ��ȫ������*/
int isFullTree( BTNode * b );
/*������������ʽ�ṹת����˳��ṹ*/
int trans( BTNode * b, ElemType a[] );
/*��˳��ṹת���ɶ�����ʽ�洢*/
BTNode * trans1( ElemType a[], int n );
/*�ж�һ�����Ƿ�Ϊ����������*/
int isOrderedTree( BTNode * b );
/*�ж϶������Ƿ�Ϊ��ȫ������*/
int isFullTree2( BTNode * b );
/*ͨ�����鹹�������*/
void arrayToTree( BTNode * & b, ElemType a[], int i, int n );
/*�ж����Ŷ������Ƿ����*/
int isEqual( BTNode * b1, BTNode * b2 );
/*�ҳ�����㵽�����ڵ��·��*/
void path( BTNode * root, BTNode * p );
/*�ҳ��������ؼ���һ�µĽ���ָ��*/
BTNode * findPt( BTNode * b, ElemType x );
/*��һ��Ԫ�ز��뵽������������*/
void insertBSTree( BTNode * &b, ElemType a );
/*ͨ�����鹹��һ�Ŷ���������*/
void createBSTree( BTNode * &b, ElemType a[], int n );
/*��������Ԫ�ز��������
bΪԭ������������Ķ�����
���ز�����õ�����*/
BTNode * dislink( BTNode * & b, ElemType x );
/*˫�����*/
void doubleOrder( BTNode * b );
/*��ǰ���������������й��������*/
BTNode * restore( ElemType * ppos, ElemType * ipos, int n );
/*���Ժ���-�ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽڵ���*/
/*û�����ӵĽڵ�ΪҶ�ӽڵ� ʵ����ʱͳ��û�����ӵĽڵ����*/
int forLeaves( BTNode * t );
/*�������Ҷ�ӽ�㵽������·�� �ǵݹ�*/
void allLeavesPath1( BTNode * b );
/*�������Ҷ�ӽ�㵽���ڵ��·�� �ݹ�*/
void allLeavesPath2( BTNode * b, ElemType path[], int pathLen );
/*���������*/
int height( BTNode * bt );
/*��ջ�ǵݹ����������ĵ�һ�����*/
BTNode * PostFirst( BTNode * b );
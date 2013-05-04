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

void PreOrder1( BTNode * b );	/*非递归先序遍历*/
void PostOrder1( BTNode * b );	/*非递归后序遍历*/

/*丁氏非递归遍历*/
void PreOrderD( BTNode * b );	/*非递归先序遍历*/
void InOrderD( BTNode * b );	/*非递归中序遍历*/
void PostOrderD( BTNode * b );	/*非递归后序遍历*/

/*寻找元素ch并返回层数*/
int findElem( BTNode * b, ElemType x );
/*递归寻找元素ch并返回地址*/
BTNode * findElem1( BTNode * b, ElemType x );
/*判断两棵二叉树是否相似*/
int like( BTNode * b1, BTNode * b2 );
/*递归求节点个数*/
int getNum( BTNode * b );
/*递归求叶节点个数*/
int getLeafNum( BTNode * b );
/*递归求度为1的节点*/
int getNum1( BTNode * b );
/*递归求度为2的节点*/
int getNum2( BTNode * b );
/*后序释放所有节点*/
void release( BTNode * &b );
/*递归实现知道叶节点值 求根节点值*/
int getSumValue( BTNode * b );
/*寻找树中的最长路径*/
void longestPath( BTNode * b );
/*输出根节点到所有叶节点的路径*/
void leafPath( BTNode * b );
/*递归输出根节点到所有叶节点的路径*/
void leafPathRec( BTNode * b );
/*判断二叉树是否为完全二叉树*/
int isFullTree( BTNode * b );
/*将二叉树从链式结构转换成顺序结构*/
int trans( BTNode * b, ElemType a[] );
/*将顺序结构转换成二叉链式存储*/
BTNode * trans1( ElemType a[], int n );
/*判断一棵树是否为二叉排序树*/
int isOrderedTree( BTNode * b );
/*判断二叉树是否为完全二叉树*/
int isFullTree2( BTNode * b );
/*通过数组构造二叉树*/
void arrayToTree( BTNode * & b, ElemType a[], int i, int n );
/*判断两颗二叉树是否相等*/
int isEqual( BTNode * b1, BTNode * b2 );
/*找出根结点到所给节点的路径*/
void path( BTNode * root, BTNode * p );
/*找出与所给关键字一致的结点的指针*/
BTNode * findPt( BTNode * b, ElemType x );
/*将一个元素插入到二叉排序树中*/
void insertBSTree( BTNode * &b, ElemType a );
/*通过数组构造一颗二叉排序数*/
void createBSTree( BTNode * &b, ElemType a[], int n );
/*根据所给元素拆除二叉树
b为原二叉树与拆除后的二叉树
返回拆除所得的新树*/
BTNode * dislink( BTNode * & b, ElemType x );
/*双序遍历*/
void doubleOrder( BTNode * b );
/*由前序序列与中序序列构造二叉树*/
BTNode * restore( ElemType * ppos, ElemType * ipos, int n );
/*求以孩子-兄弟表示法存储的森林的叶子节点数*/
/*没有左孩子的节点为叶子节点 实际上时统计没有左孩子的节点个数*/
int forLeaves( BTNode * t );
/*输出所有叶子结点到根结点的路径 非递归*/
void allLeavesPath1( BTNode * b );
/*输出所有叶子结点到根节点的路径 递归*/
void allLeavesPath2( BTNode * b, ElemType path[], int pathLen );
/*求二叉树高*/
int height( BTNode * bt );
/*非栈非递归求后序遍历的第一个结点*/
BTNode * PostFirst( BTNode * b );
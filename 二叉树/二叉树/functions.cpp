#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>

char current = 0;	/*辅助函数isOrderedTree的全局变量*/

/*用括号表示法建造二叉树*/
void CreateBTNode( BTNode * &b, char * str )
{
	BTNode * St[MaxSize], *s = NULL;
	int top = -1;
	int flag = 0;		/*标记是左孩子还是右孩子*/
	b = NULL;

	while( *str != '\0' )
	{
		switch( *str )
		{
		case '(': St[++top] = s; flag = 1; break;	/*将前面创建的节点作为双亲节点进栈 k = 1表示后面的节点为栈顶节点的左孩子*/
		case ')': top --; break;				/*栈顶节点的左右孩子都处理完毕 退栈*/
		case ',': flag = 2; break;					/*表示后面建造的节点为右孩子节点*/
		case ' ': break;	/*过滤空格*/
		default:			/*建造一个二叉树节点*/
			s = ( BTNode * )malloc( sizeof( BTNode ) );
			s->data = *str;
			s->lchild = s->rchild = 0;
			if( b == NULL )
				b = s;
			else
			{
				switch( flag )
				{
				case 1:
					St[top]->lchild = s; break;
				case 2:
					St[top]->rchild = s; break;
				default:
					;
				}
			}
		}
		str ++;
	}
}

/*层次遍历二叉树*/
void LevelOrder( BTNode * b )
{
	BTNode * data[MaxSize];	/*层次便利用到的辅助队列*/
	int front, rear;

	front = rear = 0;	/*初始化队列*/
	rear = ( rear + 1 ) % MaxSize;
	data[rear] = b;	/*将二叉树根节点入队*/

	while( front != rear )	/*队不空时循环*/
	{
		front = ( front + 1 ) % MaxSize;	/*出队*/
		printf( "%c ", data[front]->data );	/*访问队首元素*/
		if( data[front]->lchild != NULL )
		{
			rear = ( rear + 1 ) % MaxSize;
			data[rear] = data[front]->lchild;
		}
		if( data[front]->rchild != NULL )
		{
			rear = ( rear + 1 ) % MaxSize;
			data[rear] = data[front]->rchild;
		}
	}
}



/*先序遍历*/
void PreOrder( BTNode * b )
{
	if( b != NULL )
	{
		printf( "%c ", b->data );
		PreOrder( b->lchild );
		PreOrder( b->rchild );
	}
}
/*中序遍历*/
void InOrder( BTNode * b )
{
	if( b != NULL )
	{
		InOrder( b->lchild );
		printf( "%c ", b->data );
		InOrder( b->rchild );
	}
}
/*后序遍历*/
void PostOrder( BTNode * b )
{
	if( b != NULL )
	{
		PostOrder( b->lchild );
		PostOrder( b->rchild );
		printf( "%c ", b->data );
	}
}

/*后序遍历非递归*/
void PostOrder1( BTNode * b )
{
	BTNode * St[MaxSize];
	BTNode * p;
	int flag, top = -1;
	if( b != NULL )
	{
		do
		{
			while( b != NULL )
			{
				top ++;
				St[top] = b;
				b = b->lchild;
			}
			/*执行到此处时，栈顶元素没有左孩子或左子树均已访问过*/
			p = NULL;
			flag = 1;
			while( top != -1 && flag )
			{
				b = St[top];
				if( b->rchild == p )
				{
					printf( "%c ", b->data );
					top --;
					p = b;
				}
				else
				{
					b = b->rchild;
					flag = 0;
				}
			}
		}while( top != -1 );
		printf( "\n" );
	}
}
/*先序遍历非递归*/
void PreOrder1( BTNode * b )
{
	BTNode *p;
	struct
	{
		BTNode * pt;
		int tag;
	}St[MaxSize];
	int top = -1;

	if( b == NULL )
		printf( "空树\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 1;
		while( top != -1 )
		{
			if( St[top].tag == 0 )
			{
				printf( "%c ", St[top].pt->data );
				top --;
			}
			else
			{
				p = St[top--].pt;
				if( p->rchild != NULL )
				{
					St[++top].pt = p->rchild;
					St[top].tag = 1;
				}
				if( p->lchild != NULL )
				{
					St[++top].pt = p->lchild;
					St[top].tag = 1;
				}
				St[++top].pt = p;
				St[top].tag = 0;
			}
		}
	}
}

/*先序遍历非递归*/
void PreOrderD( BTNode * b )
{
	struct
	{
		BTNode * pt;
		int tag;
	}St[MaxSize];
	int top = -1;
	BTNode * p = NULL;

	if( b == NULL )
		printf( "空树\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*左右孩子都没考虑过*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*左右孩子均未考察 访问*/
				printf( "%c ", St[top].pt->data );
				St[top].tag = 1;
				break;
			case 1:	/*已访问 考察左孩子*/
				St[top].tag = 2;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 2:	/*已考察左孩子 考察右孩子 退栈*/
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[top].pt = p->rchild;	/*将栈顶元素退栈 再进新元素*/
					St[top].tag = 0;
				}
				else
				{
					top --;
				}
				break;
			default:
				;
			}
		}
	}
}





/*中序遍历非递归*/
void InOrderD( BTNode * b )
{
	struct
	{
		BTNode * pt;
		int tag;
	}St[MaxSize];
	int top = -1;
	BTNode * p = NULL;

	if( b == NULL )
		printf( "空树\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*左右孩子都没考虑过*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*左右孩子均未考察*/
				St[top].tag = 1;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 1:	/*考察过左孩子 访问*/
				printf( "%c ", St[top].pt->data );
				St[top].tag = 2;
				break;
			case 2:	/*已访问 考察右孩子 退栈*/
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[top].pt = p->rchild;	/*将栈顶元素退栈 再进新元素*/
					St[top].tag = 0;
				}
				else
				{
					top --;
				}
				break;
			default:
				;
			}
		}
	}
}





/*后序遍历非递归*/
void PostOrderD( BTNode * b )
{
	struct
	{
		BTNode * pt;
		int tag;
	}St[MaxSize];
	int top = -1;
	BTNode * p = NULL;

	if( b == NULL )
		printf( "空树\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*左右孩子都没考虑过*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*左右孩子均未考察 考察左孩子*/
				St[top].tag = 1;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 1:	/*考察过左孩子 考察右孩子*/
				St[top].tag = 2;
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->rchild;	/*将右孩子进栈*/
					St[top].tag = 0;
				}
				break;
			case 2:	/*已访问 考察右孩子 退栈*/
				printf( "%c ", St[top].pt->data );
				top --;
				break;
			default:
				;
			}
		}
	}
}






/*寻找元素ch并返回层数*/
int findElem( BTNode * b, ElemType x )
{
	int n = 0;
	if( b != NULL )
	{
		if( b->data == x )
			return 1;
		if( ( n = findElem( b->lchild, x ) ) > 0 )
			return n + 1;
		if( ( n = findElem( b->rchild, x ) ) > 0 )
			return n + 1;
		return 0;
	}
	return 0; 
}
/*递归寻找元素ch并返回地址*/
BTNode * findElem1( BTNode * b, ElemType x )
{
	BTNode * p = NULL;
	if( b != NULL )
	{
		if( b->data == x )
			return b;
		if( ( p = findElem1( b->lchild, x ) ) != NULL )
			return p;
		if( ( p = findElem1( b->rchild, x ) ) != NULL )
			return p;
		return NULL;
	}
	return NULL;
}

/*递归判断两棵二叉树是否相似*/
int like( BTNode * b1, BTNode * b2 )
{
	if( b1 == NULL && b2 == NULL )	/*两颗空二叉树相似*/
		return 1;
	if( b1 == NULL || b2 == NULL )	/*一空一非空则不相似*/
		return 0;
	/*若均不空 则比较左右子树 仅当左右子树均相似时相似*/
	return like( b1->lchild, b2->lchild ) & like( b1->rchild, b2->rchild );
}
/*递归求节点个数*/
int getNum( BTNode * b )
{
	if( b == NULL )
		return 0;
	return ( getNum( b->lchild ) + getNum( b->rchild ) + 1 );
}
/*递归求叶节点个数*/
int getLeafNum( BTNode * b )
{
	if( b == NULL )	/*空树下有0个叶子节点*/
		return 0;
	if( b->lchild == NULL && b->rchild == NULL )	/*本节点就是叶子节点*/
		return 1;
	/*既不是空树也不是叶节点 则返回左子树的叶节点数加上右子树的节点数*/
	return ( getLeafNum( b->lchild ) + getLeafNum( b->rchild ) );
}
/*递归求度为1的节点*/
int getNum1( BTNode * b )
{
	if( b == NULL )	/*空树下有0个度为1的节点*/
		return 0;
	if( b->lchild == NULL && b->rchild != NULL )	/*左空右不空*/
		return getNum1( b->rchild ) + 1;
	if( b->rchild == NULL && b->lchild != NULL )	/*右空左不空*/
		return getNum1( b->lchild ) + 1;
	if( b->rchild == NULL && b->lchild == NULL )	/*左右均空*/
		return 0;
	/*左右均不空 则返回左子树与右子树度为1的节点的个数的和*/
	return ( getNum1( b->lchild ) + getNum1( b->rchild ) );
}
/*递归求度为2的节点*/
int getNum2( BTNode * b )
{
	if( b == NULL )	/*空树下有0个度为2的节点*/
		return 0;
	if( b->lchild != 0 && b->rchild != 0 )	/*左右均不空*/
		return ( getNum2( b->lchild ) + getNum2( b->rchild ) + 1 );
	if( b->lchild == NULL && b->rchild != NULL )	/*左空右不空*/
		return getNum2( b->rchild );
	if( b->rchild == NULL && b->lchild != NULL )	/*右空左不空*/
		return getNum2( b->lchild );
	if( b->lchild == NULL && b->rchild == NULL )
		return 0;
	return 0;
	
}
/*后序释放所有节点*/
void release( BTNode * &b )
{
	if( b != NULL )
	{
		release( b->lchild );
		release( b->rchild );
		free( b );
	}
}
/*递归实现知道叶节点值 求根节点值*/
int getSumValue( BTNode * b )
{
	if( b == NULL )	/*空树*/
		return 0;
	if( b->lchild == NULL && b->rchild == NULL )	/*叶节点*/
		return ( int )b->data;
	/*非空也非叶节点*/
	b->data = ( getSumValue( b->lchild ) + getSumValue( b->rchild ) );
	return ( int )b->data;
}
/*非递归输出根节点到所有叶节点的路径*/
void leafPath( BTNode * b )
{
	struct
	{
		BTNode * data;
		int tag;
	}st[MaxSize];
	BTNode * pt = NULL;
	int top = -1, n = 0;	/*用于遍历栈*/

	if( b == 0 )
		printf( "空树\n" );
	else
	{
		st[++top].data = b;	/*根节点进栈*/
		st[top].tag = 0;	/*左右孩子均未考察过*/

		while( top > -1 )
		{
			/*如果栈顶元素为叶子节点 则打印路径*/
			if( st[top].data->lchild == NULL && st[top].data->rchild == NULL )
			{
				n = 0;
				while( n <= top )
					printf( "%c -> ", st[n++].data->data );
				printf( "NULL\n" );
				top --;	/*退栈*/
				continue;
			}

			switch( st[top].tag )
			{
			case 0:	/*在左右孩子均未考察的情况下考察左孩子*/
				st[top].tag = 1;	/*设置考察过左孩子标志*/
				pt = st[top].data->lchild;
				if( pt != NULL )	/*左孩子不空*/
				{
					st[++top].data = pt;	/*左孩子进栈*/
					st[top].tag = 0;
				}
				break;
			case 1:	/*在考察过左孩子的情况下考虑右孩子*/
				st[top].tag = 2;	/*设置考察过右孩子标志*/
				pt = st[top].data->rchild;
				if( pt != NULL )	/*右孩子不空*/
				{
					st[++top].data = pt;
					st[top].tag = 0;
				}
				break;
			case 2:	/*右孩子考察过*/
				top --;	/*退栈*/
				break;
			default:
				;
			}
		}
	}
}

/*判断二叉树是否为完全二叉树*/
int isFullTree( BTNode * b )
{
	BTNode * queue[MaxSize], * pt = NULL;
	int front = -1, rear = -1, flag = 0, i = 0;

	if( b == 0 )	/*空树为完全二叉树*/
		return 1;
	queue[++rear] = b;	/*进队*/
	while( front != rear )	/*队不空*/
	{
		pt = queue[++front];
		if( pt != NULL )	/*不空 则将左右孩子进队*/
		{
			queue[++rear] = pt->lchild;
			queue[++rear] = pt->rchild;
		}
	}
	while( i<= rear )
	{
		if( flag == 0 && queue[i] == NULL )
		{
			flag = 1;
			continue;
		}
		if( flag == 1 && queue[i] != NULL )
			return 0;
		i ++;
	}
	return 1;
}
/*递归输出根节点到所有叶节点的路径*/
void leafPathRec( BTNode * b )
{
}

/*寻找树中的最长路径*/
void longestPath( BTNode * b )
{

}
/*将二叉树从链式结构转换成顺序结构 返回顺序存储的长度?????????????*/
int trans( BTNode * b, ElemType a[] )
{
	BTNode *queue[MaxSize], * pt = NULL;
	int rear, front, i = 0;
	rear = front = -1;
	if( b != NULL )
	{
		queue[++rear] = b;
		a[rear] = b->data;
		while( front != rear )	/*栈不空*/
		{
			pt = queue[++front];
			if( pt != NULL )
			{
				queue[++rear] = pt->lchild;
				if( pt->lchild == NULL )
					a[rear] = '0';
				else
					a[rear] = pt->lchild->data;

				queue[++rear] = pt->rchild;
				if( pt->rchild == NULL )
					a[rear] = '0';
				else
					a[rear] = pt->rchild->data;
			}
		}
		i = rear;
		while( i>= 0 && a[i] == '0' )
			i --;
		a[++i] = '#';
		return i;
	}
	return 0;
}
/*将顺序结构转换成二叉链式存储???????*/
BTNode * trans1( ElemType a[], int n )
{
	BTNode * queue[MaxSize], * pt = NULL;
	int i = 0;
	while( a[i] != '#' )
	{
		if( a[i] != '0' )
		{
			pt = ( BTNode * )malloc( sizeof( BTNode ) );
			pt->data = a[i];
			pt->lchild = pt->rchild = NULL;
		}
		else
			pt = NULL;
		
		queue[i] = pt;
		i ++;
	}
	i = 0;
	while( i < n )
	{
		if( queue[i] != NULL )
		{
			if( ( 2*i+1 ) < n )
				queue[i]->lchild = queue[2*i+1];
			if( ( 2*i+2 ) < n )
				queue[i]->rchild = queue[2*i+2];
		}
		i ++;
	}
	return queue[0];
}

/*判断一棵树是否为二叉排序树*/
int isOrderedTree( BTNode * b )
{
	if( b == NULL )	/*空树是排序二叉树*/
		return 1;
	
	/*考察左子数是否为排序二叉树*/
	if( isOrderedTree( b->lchild ) == 1 && current < b->data )
	{
		current = b->data;
		/*考察右子树是否为排序二叉树*/
		if( isOrderedTree( b->rchild ) == 1 )
			return 1;
		else
			return 0;
	}
	else
		return 0;	
}

/*判断二叉树是否为完全二叉树*/
int isFullTree2( BTNode * b )
{
	BTNode * queue[MaxSize], * pt;
	int front = 0, rear = 0, flag = 0;	/*用循环队列进行层次遍历*/
	if( b == NULL )	/*空树为完全二叉树*/
		return 1;
	rear = ( rear + 1 ) % MaxSize;
	queue[rear] = b;
	while( front != rear )	/*队不空*/
	{
		front = ( front + 1 ) % MaxSize;
		pt = queue[front];
		if( pt->lchild == NULL && pt->rchild != NULL)	/*左孩子空右孩子不空*/
			return 0;
		else if( pt->lchild == NULL && pt->rchild == NULL )	/*为叶子节点*/
			flag = 1;	/*标记从该节点以后均应为叶节点*/
		else if( pt->lchild != NULL && pt->rchild != NULL )	/*双节点*/
		{
			if( flag )
				return 0;
			else
			{
				rear = ( rear + 1 ) % MaxSize;
				queue[rear] = pt->lchild;
				rear = ( rear + 1 ) % MaxSize;
				queue[rear] = pt->rchild;
			}
		}
		else	/*左孩子不空右孩子空的节点*/
		{
			if( flag )
				return 0;
			else
			{
				rear = ( rear + 1 ) % MaxSize;	/*左孩子进栈*/
				queue[rear] = pt->lchild;
			}	
		}
	}
	return 1;
}
/*通过数组构造二叉树*/
void arrayToTree( BTNode * & b, ElemType a[], int i, int n )
{
	if( i < n )	/*没结束*/
	{
		if( a[i] != '0' )	/*不为空结点*/
		{
			b = ( BTNode * )malloc( sizeof( BTNode ) );
			b->data = a[i];
			b->lchild = b->rchild = NULL;
			arrayToTree( b->lchild, a, 2*i+1, n );
			arrayToTree( b->rchild, a, 2*i+2, n );
		}
	}
}
/*判断两颗二叉树是否相等*/
int isEqual( BTNode * b1, BTNode * b2 )
{
	if( b1 == NULL && b2 == NULL )	/*两颗均为空树*/
		return 1;
	else if( b1 != NULL && b2 != NULL )	/*两颗均不为空树*/
		return isEqual( b1->lchild ,b2->lchild ) & 
			isEqual( b1->rchild , b2->rchild );
	else
		return 0;
}
/*找出根结点到所给节点的路径*/
void path( BTNode * root, BTNode * p )
{
	int i = 0;
	/*本算法采用深度优先遍历寻找*/
	struct
	{
		BTNode * pt;
		int tag;	/*标识pt的访问状态*/
	}stack[MaxSize], * tmp;
	int top = -1;
	int flag = 0;	/*找到标志*/

	stack[++top].pt = root;
	stack[top].tag = 0;	/*左右子树都没考察过*/

	while( top > -1 && !flag )	/*栈不空且没有找到时循环*/
	{
		tmp = &stack[top];	/*取栈顶元素*/
		if( tmp->pt == p )	/*找到*/
			flag = 1;
		else
		{
			switch( tmp->tag )
			{
			case 0:		/*左右子树都没考察过*/
				if( tmp->pt->lchild != NULL )	/*当左子树不空时左子树进栈*/
				{
					stack[++top].pt = tmp->pt->lchild;
					stack[top].tag = 0;
				}
				tmp->tag = 1;
				break;
			case 1:		/*右子树没考察过*/
				if( tmp->pt->rchild != NULL )	/*当右子树不空时右子树进栈*/
				{
					stack[++top].pt = tmp->pt->rchild;
					stack[top].tag = 0;
				}
				tmp->tag = 2;
				break;
			case 2:		/*左右子树都已考察过 退栈*/
				top --;
			default:
				;
			}
		}
	}
	if( flag )	/*找到*/
		for( i = 0; i <= top; i ++ )
			printf( "%c ", stack[i].pt->data );
	else
		printf( "没找到！" );
	printf( "\n" );
}
/*找出与所给关键字一致的结点的指针*/
BTNode * findPt( BTNode * b, ElemType x )
{
	BTNode * tmp;
	if( b == NULL )	/*空树返回空*/
		return NULL;
	if( b->data == x )	/*本结点就是 则返回本结点指针*/
		return b;
	tmp = findPt( b->lchild, x );	/*在左子树中寻找*/
	if( tmp != NULL )	/*左子树中找到则返回*/
		return tmp;
	return findPt( b->rchild, x );	/*否则右子树中寻找*/
}
/*将一个元素插入到二叉排序树中*/
void insertBSTree( BTNode * &b, ElemType a )
{
	if( b == NULL )
	{
		b = ( BTNode * )malloc( sizeof( BTNode ) );
		b->data = a;
		b->lchild = b->rchild = NULL;
	}
	else
	{
		if( a < b->data )
			insertBSTree( b->lchild, a );
		else
			insertBSTree( b->rchild, a );
	}
}
/*通过数组构造一颗二叉排序数*/
void createBSTree( BTNode * &b, ElemType a[], int n )
{
	int i;
	for( i = 0; i < n; i ++ )
		insertBSTree( b, a[i] );
}
/*根据所给元素拆除二叉树
b为原二叉树与拆除后的二叉树
返回拆除所得的新树*/
BTNode * dislink( BTNode * & b, ElemType x )
{
	BTNode * p;
	if( b == NULL )	/*b为空树则返回空*/
		return NULL;
	if( b->data == x )	/*根结点就是该元素*/
	{
		p = b;
		b = NULL;
		return p;
	}
	else
	{
		p = dislink( b->lchild, x );
		if( p == NULL )
			p = dislink( b->rchild, x );
		return p;
	}
}
/*双序遍历*/
void doubleOrder( BTNode * b )
{
	if( b != NULL )
	{
		printf( "%c ", b->data );
		doubleOrder( b->lchild );
		printf( "%c ", b->data );
		doubleOrder( b->rchild );
	}
}
/*由前序序列与中序序列构造二叉树*/
BTNode * restore( ElemType * ppos, ElemType * ipos, int n )
{
	BTNode * p;
	int locator = 0;
	if( n > 0 )
	{
		while( ipos[locator] != ppos[0] )	/*找到先序首在中序中的位置*/
			locator ++;
		p = ( BTNode * )malloc( sizeof( BTNode ) );
		p->data = ppos[0];

		ppos ++;	/*前序序列去掉已生成结点的元素*/
		p->lchild = restore( ppos, ipos, locator );	/*locator也是左子树的长度*/
		ppos += locator;		/*之前已经滤去已建元素*/
		ipos += locator + 1;	/*滤去已建元素和左子树的长度*/
		p->rchild = restore( ppos, ipos, n - locator - 1 );
		return p;
	}
	else
		return NULL;
	
}
/*求以孩子-兄弟表示法存储的森林的叶子节点数*/
/*没有左孩子的节点为叶子节点 实际上时统计没有左孩子的节点个数*/
int forLeaves( BTNode * t )
{
	if( t == NULL )
		return 0;
	if( t->lchild == NULL )	/*没有孩子 是叶子节点*/
		return ( 1 + forLeaves( t->rchild ) );
	return ( forLeaves( t->lchild ) + forLeaves( t->rchild ) );
}

/*输出所有叶子结点到根结点的路径 非递归*/
void allLeavesPath1( BTNode * b )
{
	if( b == NULL )
		return;
	struct
	{
		BTNode * pt;
		int flag;	/*0左右孩子均为考察 1考察左孩子 2考察右孩子*/
	}St[MaxSize];
	int top = -1, i;
	top ++;
	St[top].pt = b;
	St[top].flag = 0;
	while( top > -1 )	/*栈不空循环*/
	{
		if( St[top].pt->lchild == NULL && St[top].pt->rchild == NULL )	/*栈顶元素为叶子结点*/
		{
			for( i = top; i >= 0; i -- )	/*输出路径*/
				printf( "%c ", St[i].pt->data );
			printf( "\n" );
			top --;	/*出栈*/
		}
		else	/*栈顶元素非叶子结点*/
		{
			switch( St[top].flag )
			{
			case 0: St[top].flag = 1;
				if( St[top].pt->lchild != NULL )
				{
					St[++top].pt = St[top-1].pt->lchild;
					St[top].flag = 0;
				}
				break;
			case 1: St[top].flag = 2;
				if( St[top].pt->rchild != NULL )
				{
					St[++top].pt = St[top-1].pt->rchild;
					St[top].flag = 0;
				}
				break;
			case 2: top --; break;
			default: ;
			}
		}
	}
}
/*输出所有叶子结点到根节点的路径 递归*/
void allLeavesPath2( BTNode * b, ElemType path[], int pathLen )
{
	int i;
	if( b != NULL )
	{
		if( b->lchild == NULL && b->rchild == NULL )	/*叶子结点*/
		{
			printf( "%c ", b->data );
			for( i = pathLen-1; i >= 0; i -- )
				printf( "%c ", path[i] );
			printf( "\n" );
		}
		else
		{
			path[pathLen++] = b->data;
			allLeavesPath2( b->lchild, path, pathLen );
			allLeavesPath2( b->rchild, path, pathLen );
			pathLen --;
		}
	}
}
/*求二叉树高*/
int height( BTNode * bt )
{
	int lh, rh, h;
	if( bt == NULL )
		h = 0;
	else
	{
		lh = height( bt->lchild );
		rh = height( bt->rchild );
		h = lh > rh ? lh + 1 : rh + 1;
	}
	return h;
}
/*非栈非递归求后序遍历的第一个结点*/
BTNode * PostFirst( BTNode * b )
{
	if( b == NULL )
		return NULL;
	while( b->lchild != NULL || b->rchild != NULL )
	{
		while( b->lchild != NULL )
			b = b->lchild;
		if( b->rchild != NULL )
			b = b->rchild;
	}
	return b;
}
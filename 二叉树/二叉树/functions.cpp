#include"structDef.h"
#include<stdio.h>
#include<stdlib.h>

char current = 0;	/*��������isOrderedTree��ȫ�ֱ���*/

/*�����ű�ʾ�����������*/
void CreateBTNode( BTNode * &b, char * str )
{
	BTNode * St[MaxSize], *s = NULL;
	int top = -1;
	int flag = 0;		/*��������ӻ����Һ���*/
	b = NULL;

	while( *str != '\0' )
	{
		switch( *str )
		{
		case '(': St[++top] = s; flag = 1; break;	/*��ǰ�洴���Ľڵ���Ϊ˫�׽ڵ��ջ k = 1��ʾ����Ľڵ�Ϊջ���ڵ������*/
		case ')': top --; break;				/*ջ���ڵ�����Һ��Ӷ�������� ��ջ*/
		case ',': flag = 2; break;					/*��ʾ���潨��Ľڵ�Ϊ�Һ��ӽڵ�*/
		case ' ': break;	/*���˿ո�*/
		default:			/*����һ���������ڵ�*/
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

/*��α���������*/
void LevelOrder( BTNode * b )
{
	BTNode * data[MaxSize];	/*��α����õ��ĸ�������*/
	int front, rear;

	front = rear = 0;	/*��ʼ������*/
	rear = ( rear + 1 ) % MaxSize;
	data[rear] = b;	/*�����������ڵ����*/

	while( front != rear )	/*�Ӳ���ʱѭ��*/
	{
		front = ( front + 1 ) % MaxSize;	/*����*/
		printf( "%c ", data[front]->data );	/*���ʶ���Ԫ��*/
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



/*�������*/
void PreOrder( BTNode * b )
{
	if( b != NULL )
	{
		printf( "%c ", b->data );
		PreOrder( b->lchild );
		PreOrder( b->rchild );
	}
}
/*�������*/
void InOrder( BTNode * b )
{
	if( b != NULL )
	{
		InOrder( b->lchild );
		printf( "%c ", b->data );
		InOrder( b->rchild );
	}
}
/*�������*/
void PostOrder( BTNode * b )
{
	if( b != NULL )
	{
		PostOrder( b->lchild );
		PostOrder( b->rchild );
		printf( "%c ", b->data );
	}
}

/*��������ǵݹ�*/
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
			/*ִ�е��˴�ʱ��ջ��Ԫ��û�����ӻ����������ѷ��ʹ�*/
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
/*��������ǵݹ�*/
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
		printf( "����\n" );
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

/*��������ǵݹ�*/
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
		printf( "����\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*���Һ��Ӷ�û���ǹ�*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*���Һ��Ӿ�δ���� ����*/
				printf( "%c ", St[top].pt->data );
				St[top].tag = 1;
				break;
			case 1:	/*�ѷ��� ��������*/
				St[top].tag = 2;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 2:	/*�ѿ������� �����Һ��� ��ջ*/
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[top].pt = p->rchild;	/*��ջ��Ԫ����ջ �ٽ���Ԫ��*/
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





/*��������ǵݹ�*/
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
		printf( "����\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*���Һ��Ӷ�û���ǹ�*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*���Һ��Ӿ�δ����*/
				St[top].tag = 1;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 1:	/*��������� ����*/
				printf( "%c ", St[top].pt->data );
				St[top].tag = 2;
				break;
			case 2:	/*�ѷ��� �����Һ��� ��ջ*/
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[top].pt = p->rchild;	/*��ջ��Ԫ����ջ �ٽ���Ԫ��*/
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





/*��������ǵݹ�*/
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
		printf( "����\n" );
	else
	{
		St[++top].pt = b;
		St[top].tag = 0;	/*���Һ��Ӷ�û���ǹ�*/

		while( top > -1 )
		{
			switch( St[top].tag )
			{
			case 0:	/*���Һ��Ӿ�δ���� ��������*/
				St[top].tag = 1;
				if( St[top].pt->lchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->lchild;
					St[top].tag = 0;
				}
				break;
			case 1:	/*��������� �����Һ���*/
				St[top].tag = 2;
				if( St[top].pt->rchild != NULL )
				{
					p = St[top].pt;
					St[++top].pt = p->rchild;	/*���Һ��ӽ�ջ*/
					St[top].tag = 0;
				}
				break;
			case 2:	/*�ѷ��� �����Һ��� ��ջ*/
				printf( "%c ", St[top].pt->data );
				top --;
				break;
			default:
				;
			}
		}
	}
}






/*Ѱ��Ԫ��ch�����ز���*/
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
/*�ݹ�Ѱ��Ԫ��ch�����ص�ַ*/
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

/*�ݹ��ж����ö������Ƿ�����*/
int like( BTNode * b1, BTNode * b2 )
{
	if( b1 == NULL && b2 == NULL )	/*���ſն���������*/
		return 1;
	if( b1 == NULL || b2 == NULL )	/*һ��һ�ǿ�������*/
		return 0;
	/*�������� ��Ƚ��������� ������������������ʱ����*/
	return like( b1->lchild, b2->lchild ) & like( b1->rchild, b2->rchild );
}
/*�ݹ���ڵ����*/
int getNum( BTNode * b )
{
	if( b == NULL )
		return 0;
	return ( getNum( b->lchild ) + getNum( b->rchild ) + 1 );
}
/*�ݹ���Ҷ�ڵ����*/
int getLeafNum( BTNode * b )
{
	if( b == NULL )	/*��������0��Ҷ�ӽڵ�*/
		return 0;
	if( b->lchild == NULL && b->rchild == NULL )	/*���ڵ����Ҷ�ӽڵ�*/
		return 1;
	/*�Ȳ��ǿ���Ҳ����Ҷ�ڵ� �򷵻���������Ҷ�ڵ��������������Ľڵ���*/
	return ( getLeafNum( b->lchild ) + getLeafNum( b->rchild ) );
}
/*�ݹ����Ϊ1�Ľڵ�*/
int getNum1( BTNode * b )
{
	if( b == NULL )	/*��������0����Ϊ1�Ľڵ�*/
		return 0;
	if( b->lchild == NULL && b->rchild != NULL )	/*����Ҳ���*/
		return getNum1( b->rchild ) + 1;
	if( b->rchild == NULL && b->lchild != NULL )	/*�ҿ��󲻿�*/
		return getNum1( b->lchild ) + 1;
	if( b->rchild == NULL && b->lchild == NULL )	/*���Ҿ���*/
		return 0;
	/*���Ҿ����� �򷵻�����������������Ϊ1�Ľڵ�ĸ����ĺ�*/
	return ( getNum1( b->lchild ) + getNum1( b->rchild ) );
}
/*�ݹ����Ϊ2�Ľڵ�*/
int getNum2( BTNode * b )
{
	if( b == NULL )	/*��������0����Ϊ2�Ľڵ�*/
		return 0;
	if( b->lchild != 0 && b->rchild != 0 )	/*���Ҿ�����*/
		return ( getNum2( b->lchild ) + getNum2( b->rchild ) + 1 );
	if( b->lchild == NULL && b->rchild != NULL )	/*����Ҳ���*/
		return getNum2( b->rchild );
	if( b->rchild == NULL && b->lchild != NULL )	/*�ҿ��󲻿�*/
		return getNum2( b->lchild );
	if( b->lchild == NULL && b->rchild == NULL )
		return 0;
	return 0;
	
}
/*�����ͷ����нڵ�*/
void release( BTNode * &b )
{
	if( b != NULL )
	{
		release( b->lchild );
		release( b->rchild );
		free( b );
	}
}
/*�ݹ�ʵ��֪��Ҷ�ڵ�ֵ ����ڵ�ֵ*/
int getSumValue( BTNode * b )
{
	if( b == NULL )	/*����*/
		return 0;
	if( b->lchild == NULL && b->rchild == NULL )	/*Ҷ�ڵ�*/
		return ( int )b->data;
	/*�ǿ�Ҳ��Ҷ�ڵ�*/
	b->data = ( getSumValue( b->lchild ) + getSumValue( b->rchild ) );
	return ( int )b->data;
}
/*�ǵݹ�������ڵ㵽����Ҷ�ڵ��·��*/
void leafPath( BTNode * b )
{
	struct
	{
		BTNode * data;
		int tag;
	}st[MaxSize];
	BTNode * pt = NULL;
	int top = -1, n = 0;	/*���ڱ���ջ*/

	if( b == 0 )
		printf( "����\n" );
	else
	{
		st[++top].data = b;	/*���ڵ��ջ*/
		st[top].tag = 0;	/*���Һ��Ӿ�δ�����*/

		while( top > -1 )
		{
			/*���ջ��Ԫ��ΪҶ�ӽڵ� ���ӡ·��*/
			if( st[top].data->lchild == NULL && st[top].data->rchild == NULL )
			{
				n = 0;
				while( n <= top )
					printf( "%c -> ", st[n++].data->data );
				printf( "NULL\n" );
				top --;	/*��ջ*/
				continue;
			}

			switch( st[top].tag )
			{
			case 0:	/*�����Һ��Ӿ�δ���������¿�������*/
				st[top].tag = 1;	/*���ÿ�������ӱ�־*/
				pt = st[top].data->lchild;
				if( pt != NULL )	/*���Ӳ���*/
				{
					st[++top].data = pt;	/*���ӽ�ջ*/
					st[top].tag = 0;
				}
				break;
			case 1:	/*�ڿ�������ӵ�����¿����Һ���*/
				st[top].tag = 2;	/*���ÿ�����Һ��ӱ�־*/
				pt = st[top].data->rchild;
				if( pt != NULL )	/*�Һ��Ӳ���*/
				{
					st[++top].data = pt;
					st[top].tag = 0;
				}
				break;
			case 2:	/*�Һ��ӿ����*/
				top --;	/*��ջ*/
				break;
			default:
				;
			}
		}
	}
}

/*�ж϶������Ƿ�Ϊ��ȫ������*/
int isFullTree( BTNode * b )
{
	BTNode * queue[MaxSize], * pt = NULL;
	int front = -1, rear = -1, flag = 0, i = 0;

	if( b == 0 )	/*����Ϊ��ȫ������*/
		return 1;
	queue[++rear] = b;	/*����*/
	while( front != rear )	/*�Ӳ���*/
	{
		pt = queue[++front];
		if( pt != NULL )	/*���� �����Һ��ӽ���*/
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
/*�ݹ�������ڵ㵽����Ҷ�ڵ��·��*/
void leafPathRec( BTNode * b )
{
}

/*Ѱ�����е��·��*/
void longestPath( BTNode * b )
{

}
/*������������ʽ�ṹת����˳��ṹ ����˳��洢�ĳ���?????????????*/
int trans( BTNode * b, ElemType a[] )
{
	BTNode *queue[MaxSize], * pt = NULL;
	int rear, front, i = 0;
	rear = front = -1;
	if( b != NULL )
	{
		queue[++rear] = b;
		a[rear] = b->data;
		while( front != rear )	/*ջ����*/
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
/*��˳��ṹת���ɶ�����ʽ�洢???????*/
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

/*�ж�һ�����Ƿ�Ϊ����������*/
int isOrderedTree( BTNode * b )
{
	if( b == NULL )	/*���������������*/
		return 1;
	
	/*�����������Ƿ�Ϊ���������*/
	if( isOrderedTree( b->lchild ) == 1 && current < b->data )
	{
		current = b->data;
		/*�����������Ƿ�Ϊ���������*/
		if( isOrderedTree( b->rchild ) == 1 )
			return 1;
		else
			return 0;
	}
	else
		return 0;	
}

/*�ж϶������Ƿ�Ϊ��ȫ������*/
int isFullTree2( BTNode * b )
{
	BTNode * queue[MaxSize], * pt;
	int front = 0, rear = 0, flag = 0;	/*��ѭ�����н��в�α���*/
	if( b == NULL )	/*����Ϊ��ȫ������*/
		return 1;
	rear = ( rear + 1 ) % MaxSize;
	queue[rear] = b;
	while( front != rear )	/*�Ӳ���*/
	{
		front = ( front + 1 ) % MaxSize;
		pt = queue[front];
		if( pt->lchild == NULL && pt->rchild != NULL)	/*���ӿ��Һ��Ӳ���*/
			return 0;
		else if( pt->lchild == NULL && pt->rchild == NULL )	/*ΪҶ�ӽڵ�*/
			flag = 1;	/*��ǴӸýڵ��Ժ��ӦΪҶ�ڵ�*/
		else if( pt->lchild != NULL && pt->rchild != NULL )	/*˫�ڵ�*/
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
		else	/*���Ӳ����Һ��ӿյĽڵ�*/
		{
			if( flag )
				return 0;
			else
			{
				rear = ( rear + 1 ) % MaxSize;	/*���ӽ�ջ*/
				queue[rear] = pt->lchild;
			}	
		}
	}
	return 1;
}
/*ͨ�����鹹�������*/
void arrayToTree( BTNode * & b, ElemType a[], int i, int n )
{
	if( i < n )	/*û����*/
	{
		if( a[i] != '0' )	/*��Ϊ�ս��*/
		{
			b = ( BTNode * )malloc( sizeof( BTNode ) );
			b->data = a[i];
			b->lchild = b->rchild = NULL;
			arrayToTree( b->lchild, a, 2*i+1, n );
			arrayToTree( b->rchild, a, 2*i+2, n );
		}
	}
}
/*�ж����Ŷ������Ƿ����*/
int isEqual( BTNode * b1, BTNode * b2 )
{
	if( b1 == NULL && b2 == NULL )	/*���ž�Ϊ����*/
		return 1;
	else if( b1 != NULL && b2 != NULL )	/*���ž���Ϊ����*/
		return isEqual( b1->lchild ,b2->lchild ) & 
			isEqual( b1->rchild , b2->rchild );
	else
		return 0;
}
/*�ҳ�����㵽�����ڵ��·��*/
void path( BTNode * root, BTNode * p )
{
	int i = 0;
	/*���㷨����������ȱ���Ѱ��*/
	struct
	{
		BTNode * pt;
		int tag;	/*��ʶpt�ķ���״̬*/
	}stack[MaxSize], * tmp;
	int top = -1;
	int flag = 0;	/*�ҵ���־*/

	stack[++top].pt = root;
	stack[top].tag = 0;	/*����������û�����*/

	while( top > -1 && !flag )	/*ջ������û���ҵ�ʱѭ��*/
	{
		tmp = &stack[top];	/*ȡջ��Ԫ��*/
		if( tmp->pt == p )	/*�ҵ�*/
			flag = 1;
		else
		{
			switch( tmp->tag )
			{
			case 0:		/*����������û�����*/
				if( tmp->pt->lchild != NULL )	/*������������ʱ��������ջ*/
				{
					stack[++top].pt = tmp->pt->lchild;
					stack[top].tag = 0;
				}
				tmp->tag = 1;
				break;
			case 1:		/*������û�����*/
				if( tmp->pt->rchild != NULL )	/*������������ʱ��������ջ*/
				{
					stack[++top].pt = tmp->pt->rchild;
					stack[top].tag = 0;
				}
				tmp->tag = 2;
				break;
			case 2:		/*�����������ѿ���� ��ջ*/
				top --;
			default:
				;
			}
		}
	}
	if( flag )	/*�ҵ�*/
		for( i = 0; i <= top; i ++ )
			printf( "%c ", stack[i].pt->data );
	else
		printf( "û�ҵ���" );
	printf( "\n" );
}
/*�ҳ��������ؼ���һ�µĽ���ָ��*/
BTNode * findPt( BTNode * b, ElemType x )
{
	BTNode * tmp;
	if( b == NULL )	/*�������ؿ�*/
		return NULL;
	if( b->data == x )	/*�������� �򷵻ر����ָ��*/
		return b;
	tmp = findPt( b->lchild, x );	/*����������Ѱ��*/
	if( tmp != NULL )	/*���������ҵ��򷵻�*/
		return tmp;
	return findPt( b->rchild, x );	/*������������Ѱ��*/
}
/*��һ��Ԫ�ز��뵽������������*/
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
/*ͨ�����鹹��һ�Ŷ���������*/
void createBSTree( BTNode * &b, ElemType a[], int n )
{
	int i;
	for( i = 0; i < n; i ++ )
		insertBSTree( b, a[i] );
}
/*��������Ԫ�ز��������
bΪԭ������������Ķ�����
���ز�����õ�����*/
BTNode * dislink( BTNode * & b, ElemType x )
{
	BTNode * p;
	if( b == NULL )	/*bΪ�����򷵻ؿ�*/
		return NULL;
	if( b->data == x )	/*�������Ǹ�Ԫ��*/
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
/*˫�����*/
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
/*��ǰ���������������й��������*/
BTNode * restore( ElemType * ppos, ElemType * ipos, int n )
{
	BTNode * p;
	int locator = 0;
	if( n > 0 )
	{
		while( ipos[locator] != ppos[0] )	/*�ҵ��������������е�λ��*/
			locator ++;
		p = ( BTNode * )malloc( sizeof( BTNode ) );
		p->data = ppos[0];

		ppos ++;	/*ǰ������ȥ�������ɽ���Ԫ��*/
		p->lchild = restore( ppos, ipos, locator );	/*locatorҲ���������ĳ���*/
		ppos += locator;		/*֮ǰ�Ѿ���ȥ�ѽ�Ԫ��*/
		ipos += locator + 1;	/*��ȥ�ѽ�Ԫ�غ��������ĳ���*/
		p->rchild = restore( ppos, ipos, n - locator - 1 );
		return p;
	}
	else
		return NULL;
	
}
/*���Ժ���-�ֵܱ�ʾ���洢��ɭ�ֵ�Ҷ�ӽڵ���*/
/*û�����ӵĽڵ�ΪҶ�ӽڵ� ʵ����ʱͳ��û�����ӵĽڵ����*/
int forLeaves( BTNode * t )
{
	if( t == NULL )
		return 0;
	if( t->lchild == NULL )	/*û�к��� ��Ҷ�ӽڵ�*/
		return ( 1 + forLeaves( t->rchild ) );
	return ( forLeaves( t->lchild ) + forLeaves( t->rchild ) );
}

/*�������Ҷ�ӽ�㵽������·�� �ǵݹ�*/
void allLeavesPath1( BTNode * b )
{
	if( b == NULL )
		return;
	struct
	{
		BTNode * pt;
		int flag;	/*0���Һ��Ӿ�Ϊ���� 1�������� 2�����Һ���*/
	}St[MaxSize];
	int top = -1, i;
	top ++;
	St[top].pt = b;
	St[top].flag = 0;
	while( top > -1 )	/*ջ����ѭ��*/
	{
		if( St[top].pt->lchild == NULL && St[top].pt->rchild == NULL )	/*ջ��Ԫ��ΪҶ�ӽ��*/
		{
			for( i = top; i >= 0; i -- )	/*���·��*/
				printf( "%c ", St[i].pt->data );
			printf( "\n" );
			top --;	/*��ջ*/
		}
		else	/*ջ��Ԫ�ط�Ҷ�ӽ��*/
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
/*�������Ҷ�ӽ�㵽���ڵ��·�� �ݹ�*/
void allLeavesPath2( BTNode * b, ElemType path[], int pathLen )
{
	int i;
	if( b != NULL )
	{
		if( b->lchild == NULL && b->rchild == NULL )	/*Ҷ�ӽ��*/
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
/*���������*/
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
/*��ջ�ǵݹ����������ĵ�һ�����*/
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
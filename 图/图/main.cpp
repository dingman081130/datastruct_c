#include"structDef.h"
#include"stdio.h"
extern int visited[MAXV];	/*����ͼʱ��Ҫά�ֵ�һ��ȫ�����ݽṹ*/

void main()
{
	MGraph * mg;
	ALGraph * alg;
	
	mg = createMGraph( "graph.txt" );
	MatToList( mg, alg );
	ConnNum( alg );
	::Prim( mg, 0 );
	printf( "" );
}
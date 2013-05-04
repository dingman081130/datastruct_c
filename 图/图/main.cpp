#include"structDef.h"
#include"stdio.h"
extern int visited[MAXV];	/*遍历图时所要维持的一个全局数据结构*/

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
#include"structDef.h"

/*初始化并查集树*/
void MakeSet( UFSTree t[], int n )
{
	int i = 0;
	for( i = 0; i < n; i ++ )
	{
		t[i].data = i;
		t[i].rank = 0;
		t[i].parent = i;
	}
}
/*查找一个元素所属的集合*/
int FindSet( UFSTree t[], int x )
{
	if( x != t[x].parent )	/*双亲不是自己*/
		return FindSet( t, t[x].parent );
	return x;
}

/*两个元素各自所属的集合合并*/
void Union( UFSTree t[], int x, int y )
{
	x = FindSet( t, x );
	y = FindSet( t, y );

	if( t[x].rank > t[y].rank )
		t[y].parent = x;
	else
	{
		t[x].parent = y;
		if( t[x].rank == t[y].rank )
			t[y].rank ++;
	}
}
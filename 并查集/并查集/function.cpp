#include"structDef.h"

/*��ʼ�����鼯��*/
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
/*����һ��Ԫ�������ļ���*/
int FindSet( UFSTree t[], int x )
{
	if( x != t[x].parent )	/*˫�ײ����Լ�*/
		return FindSet( t, t[x].parent );
	return x;
}

/*����Ԫ�ظ��������ļ��Ϻϲ�*/
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
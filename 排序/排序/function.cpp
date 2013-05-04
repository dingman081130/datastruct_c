#include"structDef.h"

/**********************��������************************************/
/*ֱ�Ӳ�������*/
void InsertSort( RecType R[], int n )
{
	int i, j;
	RecType tmp;
	for( i = 1; i < n; i ++ )
	{
		tmp = R[i];
		j = i - 1;
		while( j >= 0 && tmp.key < R[j].key )
		{
			R[j+1] = R[j];
			j --;
		}
		R[j+1] = tmp;
	}
}
/*ϣ������*/
void ShellSort( RecType R[], int n )
{
	int i, j, gap = 5;
	RecType tmp;
	while( gap >= 1)
	{
		for( i = gap; i < n; i = i ++ )
		{
			tmp = R[i];
			j = i - gap;

			while( j >= 0 && tmp.key < R[j].key )
			{
				R[j+gap] = R[j];
				j -= gap;
			}
			R[j+gap] = tmp;
			j -= gap;
		}
		gap /= 2;
	}
}
/**********************��������************************************/
/*ð������*/
void BubbleSort( RecType R[], int n )
{
	int i, j;
	RecType tmp;
	for( i = 0; i < n - 1; i ++ )
	{
		for( j = n - 1; j > i; j -- )
		{
			if( R[j].key < R[j-1].key )
			{
				tmp = R[j];
				R[j] = R[j-1];
				R[j-1] = tmp;
 			}
		}
	}
}

/*˫��ð������*/
void BubbleSort2( RecType R[], int n )
{
	int low = 0, high = n - 1;	/*ð�ݷ�Χ*/
	int i, change = 1;
	RecType tmp;
	while( low <= high && change )
	{
		change = 0;
		for( i = low; i < high; i ++ )	/*��������ð����*/
		{
			if( R[i].key > R[i+1].key )
			{
				tmp = R[i];
				R[i] = R[i+1];
				R[i+1] = tmp;
				change = 1;
			}
		}
		high --;
		for( i = high; i > low; i -- )	/*��������ðС��*/
		{
			if( R[i].key < R[i-1].key )
			{
				tmp = R[i];
				R[i] = R[i-1];
				R[i-1] = tmp;
				change = 1;
			}
		}
		low ++;
	}
}
/*��������*/
void QuickSort( RecType R[], int front, int rear )
{
	if( front > rear )
		return ;
	int i = front, j = rear;
	RecType tmp = R[i];
	while( i != j )
	{
		while( j > i && R[j].key > tmp.key )
			j --;
		R[i] = R[j];
		while( i < j && R[i].key < tmp.key )
			i ++;
		R[j] = R[i];
	}
	R[i] = tmp;
	QuickSort( R, front, i - 1 );
	QuickSort( R, i + 1, rear );

}
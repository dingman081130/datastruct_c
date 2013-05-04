typedef int KeyType;
typedef char * InfoType;

typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

/*ж╠╫с╡ЕхКеепР*/
void InsertSort( RecType R[], int n );
/*оё╤ШеепР*/
void ShellSort( RecType R[], int n );
/*ц╟ещеепР*/
void BubbleSort( RecType R[], int n );
/*к╚оРц╟ещеепР*/
void BubbleSort2( RecType R[], int n );
/*©ЛкыеепР*/
void QuickSort( RecType R[], int front, int rear );
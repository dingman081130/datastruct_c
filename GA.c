#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define POPSIZE 500					//��Ⱥ��С
#define CHROMlENGTH 8				//Ⱦɫ�峤��

int popsize ;						//��Ⱥ��С
int maxgeneration;					//���������
double pc = 0.0;					//������
double pm = 0.0;					//������

struct individual					//����Ⱦɫ�����ṹ��
{
	int chrom[CHROMlENGTH];			//����Ⱦɫ������Ʊ����ʽ��edit by ppme ��char תΪ int
	double value;					//Ⱦɫ���ֵ
	double fitness;					//Ⱦɫ�����Ӧֵ
};

int generation;						//��ǰִ�е�������
int best_index;						//��õ�Ⱦɫ���������
int worst_index;					//����Ⱦɫ���������

struct individual bestindividual;		//���Ⱦɫ�����
struct individual worstindividual;		//���Ⱦɫ�����
struct individual currentbest;			//��ǰ��õ�Ⱦɫ����� currentbest
struct individual population[POPSIZE];	//��Ⱥ����


//��������                                       
void generateinitialpopulation();			//ok-��ʼ��������Ⱥ      
void generatenextpopulation();				//����������һ����Ⱥ
void evaluatepopulation();					//������Ⱥ
void calculateobjectfitness();				//������Ⱥ��Ӧ��
//long decodechromosome(char *,int,int);	//Ⱦɫ�����
double decodechromosome(int,int);			//Ⱦɫ�����
void findbestandworstindividual();			//Ѱ����õĺ����Ⱦɫ�����
void performevolution();					//�����ݱ����
void selectoperator();						//ѡ�����
void crossoveroperator();					//��������
void mutationoperator();					//�������
void input();								//����ӿ�
void outputtextreport();					//������ֱ���


void main()			//������
{
	int i;

	srand( ( unsigned )time( NULL ) );			//ǿ������ת�����Ե�ǰʱ����������������
	printf( "������Ϊ����y=x*x�����ֵ\n" );
	generation=0;								//��ʼ��generation��ǰִ�еĴ�
	input();									//��ʼ����Ⱥ��С�������ʡ�������

	/*edit by ppme*/
	//�����á�����������ʾinput()���
	printf("popsize %d;maxgeneration %d;pc %f;pm %f\n\n",popsize,maxgeneration,pc,pm);
	/*edit by ppme*/

	generateinitialpopulation();			//������ʼ����Ⱥ
    evaluatepopulation();					//���۵�ǰ��Ⱥ,(A.������Ⱥ�������Ӧ��;B.�ҳ���ú����ĸ���)    
    while( generation < maxgeneration )		//С�����������,ִ��ѭ����
	{
		generation ++;                   
		generatenextpopulation();			//�����Ӵ���Ⱥ(A.ѡ��; B.����; C.����)
		evaluatepopulation();				//���������Ӵ���Ⱥ
		performevolution();					//�����Ӵ�����
		outputtextreport();					//���뵱��������Ⱥ
	}
	printf( "\n" );
	printf( "          ͳ�ƽ��:         " );
	printf( "\n" );
	printf( "�����ֵ���ڣ�%f\n", currentbest.fitness );
    printf( "��Ⱦɫ�����Ϊ��" );

	//����currentbest��value
	for( i = 0 ; i < CHROMlENGTH ; i++ )
		printf( " %d",currentbest.chrom[i] );

}


void generateinitialpopulation( )		//��Ⱥ��ʼ��
{
	int i,j;
	srand( ( unsigned )time( NULL ) );	//ǿ������ת�����Ե�ǰʱ����������������
	for( i = 0; i < popsize; i ++ )
		for( j = 0; j < CHROMlENGTH; j++ )
			population[i].chrom[j] = ( rand() % 10 < 5 ) ? 0 : 1;		//rand()%10�������0-9������  С��5��ע0,�����ע1
}

void generatenextpopulation()		//������һ��
{
	selectoperator();		//ѡ�����
	crossoveroperator();	//�������
	mutationoperator();		//�������
}

void evaluatepopulation()	//������Ⱥ???
{
	calculateobjectfitness();		//������Ⱥ?�������Ӧ��
	findbestandworstindividual();	//�ҵ���ú�����Ⱦɫ�����
}

void calculateobjectfitness()		//����Ⱦɫ�������Ӧֵ����Ӧ��
{
	int i;
	int j;
	printf(	"calculateobjectfitness is executing!"	);
	for( i = 0; i < popsize; i ++ )
	{
		double temp; 
		temp = decodechromosome( i, CHROMlENGTH );	//���������Ӧֵ
		population[i].value=(double)temp;
		population[i].fitness=population[i].value*population[i].value;
	}
	//������
	printf( "��ʾ��ǰ��Ⱥ���:\n" );
	for( i = 0; i < popsize; i++ )
	{
		for( j = 0; j < CHROMlENGTH; j++ )
			printf( " %d", population[i].chrom[j] );

		printf( " %lf", population[i].value );
		printf( " %lf", population[i].fitness );
		printf( "\n" );
	}
}

//error
double decodechromosome( int pop_index, int length )	//��Ⱦɫ����� 
{
	int i; 
	double decimal = 0;
	for( i = 0 ; i < length ; i++ )
		decimal += population[pop_index].chrom[i] * pow( (double)2, (double)i );	//����Ⱦɫ������Ʊ���,
	return ( decimal );																//���������10���Ƶ�valueֵ
}

void findbestandworstindividual( )	//����Ѹ����������
{
	int i;
	double sum = 0.0;

	bestindividual = population[0];
	worstindividual = population[0];

	for( i = 1; i < popsize; i ++ )
	{
		if ( population[i].fitness > bestindividual.fitness )			//���αȽ�,�ҳ���Ѹ���
		{
			bestindividual = population[i];
			best_index = i;
		}
		else if( population[i].fitness < worstindividual.fitness )		//���αȽ�,�ҳ�������
		{
			worstindividual = population[i];
			worst_index=i;
		}
		sum += population[i].fitness;									//sum �����Ⱥ������Ӧֵ
	}//for
	
	if( generation == 0 )
	{
		currentbest = bestindividual;                     //��һ����õ���ʱ�����currentbest
	}
	else
	{
		if( bestindividual.fitness >= currentbest.fitness )	//��n����õģ�ͨ���Ƚϴ���������ø���Ļ���
		{													//��ʱ�����currentbest
			currentbest = bestindividual;
		}
	}
}

void performevolution()		//��ʾ���۽��
{
	if( bestindividual.fitness > currentbest.fitness )
	{
		currentbest = population[best_index];
	}
	else
	{
		population[worst_index] = currentbest;
	}
}

void selectoperator()	//����ѡ���㷨
{
	int i, index;
	double p, sum = 0.0;							//p���������ʣ�sum��Ÿ�����Ӧ�ʺ��ۼ���Ӧ��
	double cfitness[POPSIZE];						//������ȺȾɫ��������Ӧ��

	struct individual newpopulation[POPSIZE];		//����Ⱥ

	srand( ( unsigned )time( NULL ) );				//�����������

	for( i = 0; i < popsize; i ++ )                       //
	{
		sum += population[i].fitness;						//sum�����Ⱥ��Ӧֵ�ܺ�
	}

	for( i = 0; i < popsize; i ++ )
	{
		cfitness[i] = population[i].fitness / sum;			// cfitness[] = fitness/sum�õ�������Ӧ��
	}

	for( i = 1; i < popsize; i ++ )
	{
		cfitness[i] = cfitness[i -1] + cfitness[i];			//cfitness[]= cfitness[i-1]+cfitness[i]�õ���Ⱥ
	}														//�ۼ���Ӧ��

	for ( i = 0; i < popsize; i ++ )						//forѭ��ʵ�����̶��㷨
	{
		p = rand() % 1000 / 1000.0;							//�õ�ǧ��λС��
		index = 0;
		while( p > cfitness[index] )
		{
			index ++;
		}
		newpopulation[i] = population[index];			//ѡ���ĸ�������µ�һ��,��ʱ�����newpopulation[]��
	}
	for( i = 0; i < popsize; i++ )
	{
		population[i] = newpopulation[i];				//ȫ�ֱ���populaiton����µ���Ⱥ�����ظ���ֵ��
	}
}



void crossoveroperator() //�����㷨
{
	int i, j;
	int index[POPSIZE];                         
	int point, temp;
	double p;

	srand( ( unsigned )time( NULL ) );					//�����������

	for( i = 0; i < popsize; i ++ )
	{						//��ʼ��index[]����
		index[i]=i;
	}

	for( i = 0; i < popsize; i ++)
	{						//for ѭ��ʵ����Ⱥ�������������
		point=rand() % ( popsize - i );					//������Ⱥ˳��
		temp = index[i];
		index[i] = index[point+i];
		index[point + i] = temp;
	}

	for( i = 0; i < popsize - 1; i += 2 )
	{
		p = rand() % 1000 / 1000.0;
		if( p < pc )
		{												//���㽻���㷨
			point = rand() % ( CHROMlENGTH - 1 ) + 1;
			for( j = point; j < CHROMlENGTH; j ++ )
			{
				temp = population[index[i]].chrom[j];
				population[index[i]].chrom[j] = population[index[i+1]].chrom[j];
				population[index[i+1]].chrom[j] = temp;
			}
		}
	}
}



void mutationoperator() //�������
{
	int i, j;
	double p;

	srand( ( unsigned )time( NULL ) );				//�����������

	for( i = 0; i < popsize; i ++ )
	{
		for( j = 0; j < CHROMlENGTH; j ++ )
		{
			p=rand()%1000/1000.0;
			if( p < pm )
			{
				population[i].chrom[j] = ( population[i].chrom[j] == 0 ) ? 1 : 0;
			}
		}
	}
}

void input() //��������
{
	printf( "��ʼ��ȫ�ֱ���:\n" );
  
	printf( "     ��Ⱥ��С(50-500ż��)��" );
	scanf( "%d", &popsize );				//������Ⱥ��С������Ϊż��
	if( ( popsize % 2 ) != 0 )          
	{
		printf( "    ��Ⱥ��С������Ϊż��\n" );
		popsize++;
    }

	printf( "      ���������(100-300)��" );	//�������������
	scanf( "%d", &maxgeneration );
	printf( "      ������(0.2-0.99)��" );		//���뽻����
	scanf( "%lf", &pc );
	printf( "      ������(0.001-0.1)��" );		//���������
	scanf( "%lf", &pm );
}



void outputtextreport()//�������
{
	int i;
	double sum;
	double average;
	sum=0.0;
	for( i = 0; i < popsize; i ++ ) 
	{
		sum += population[i].value;
	}
	average = sum / popsize;

	printf( "��ǰ���� = %d\n��ǰ����Ⱦɫ��ƽ��ֵ = %f\n��ǰ����Ⱦɫ�����ֵ = %f\n ", generation, average, population[best_index].value );
}

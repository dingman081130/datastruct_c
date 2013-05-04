#include<stdio.h> 
#include<time.h> 
#include<stdlib.h>
#include<string.h>

#define PLAYER 3	/*�������*/
#define CARDNUM 54	/*��������*/
#define REM 3		/*��������*/

/*���Ƴ���*/
void deal( char * card[], char * player[PLAYER][(CARDNUM-REM)/PLAYER], int flag[CARDNUM] ){
	int i, j, k;	/*k���ڱ��flag*/

	for( i = 0; i < (CARDNUM-REM)/PLAYER; i ++ )	/*17�֣�ÿ�����17����*/
		for( j = 0; j < PLAYER; j ++ ){				/*ÿ�ַ��������*/
			do{
				k = rand() % 54;
			}while( flag[k] == 1 );		/*ֱ�������K����û����Ϊֹ*/
			player[j][i] = card[k];		/*�ѵ�k���Ʒ�����j����� �ǵ�j����ҵĵ�i����*/
			flag[k] = 1;				/*��ǵ�k�����ѷ��� */
		}
}

/*��ӡ*/
void print( char * card[], char * player[PLAYER][(CARDNUM-REM)/PLAYER], int flag[CARDNUM] ){	/*��ӡ������Ϣ*/
	int i, j;

	for( i = 0; i < PLAYER; i ++ ){						/*����������δ�ӡ*/
		printf( "\n\n���%d:\n\n", i+1 );
		for( j = 0; j < (CARDNUM-REM)/PLAYER; j ++ ){	/*��ӡ��i����ҵ�������*/
			printf( "%20s ", player[i][j] );
			if( ( j+1 ) % 2 == 0 )
				printf( "\n" );
		}
	}

	printf( "\n\n����:\n\n" );			/*��ӡ����û�з�������*/
	for( i = 0; i < CARDNUM; i ++  ){
		if( flag[i] == 0 ){
			printf( "%20s ", card[i] );
			if( ( i+1 ) % 2 == 0 )
				printf( "\n" );
		}
	}
}

void main(){
	int i;
	char * player[PLAYER][(CARDNUM-REM)/PLAYER];

	char str[4] = "yes";	/*����Ƿ����·���*/
	
	/*54�������ַ�������ʽ����*/
	char * card[] = {	"Ace of Hearts", "Ace of Diamonds", "Ace of Clubs", "Ace of Spades",	
						"Deuce of Hearts", "Deuce of Diamonds", "Deuce of Clubs", "Deuce of Spades",
						"Three of Hearts", "Three of Diamonds", "Three of Clubs", "Three of Spades",
						"Four of Hearts", "Four of Diamonds", "Four of Clubs", "Four of Spades",
						"Five of Hearts", "Five of Diamonds", "Five of Clubs", "Five of Spades",
						"Six of Hearts", "Six of Diamonds", "Six of Clubs", "Six of Spades",
						"Seven of Hearts", "Seven of Diamonds", "Seven of Clubs", "Seven of Spades",
						"Eight of Hearts", "Eight of Diamonds", "Eight of Clubs", "Eight of Spades",
						"Nine of Hearts", "Nine of Diamonds", "Nine of Clubs", "Nine of Spades",
						"Ten of Hearts", "Ten of Diamonds", "Ten of Clubs", "Ten of Spades",
						"Jack of Hearts", "Jack of Diamonds", "Jack of Clubs", "Jack of Spades",
						"Queen of Hearts", "Queen of Diamonds", "Queen of Clubs", "Queen of Spades",
						"King of Hearts", "King of Diamonds", "King of Clubs", "King of Spades",
						"Joker of Color", "Joker of Black"
					};

	int flag[CARDNUM];	/*���card[i]�Ƿ񷢳� 1Ϊ����0���*/

	srand( time( NULL ) );	/*��ʱ�������ʼ�����������*/

	while( strcmp( str, "yes" ) == 0 ){		/*�ж��Ƿ����·���*/
		system( "cls" );	/*����*/
		for( i = 0; i < CARDNUM; i ++ )	/*��ʼ��ȫ������*/
			flag[i] = 0;

		deal( card, player, flag );		/*����*/
		print( card, player, flag );	/*��ӡ���ƽ��*/

		printf( "\n\n�Ƿ����·���: (yes/no)" );
		scanf( "%s", str );
	}
}
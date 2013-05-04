#include<stdio.h> 
#include<time.h> 
#include<stdlib.h>
#include<string.h>

#define PLAYER 3	/*玩家数量*/
#define CARDNUM 54	/*卡牌数量*/
#define REM 3		/*底牌数量*/

/*发牌程序*/
void deal( char * card[], char * player[PLAYER][(CARDNUM-REM)/PLAYER], int flag[CARDNUM] ){
	int i, j, k;	/*k用于标记flag*/

	for( i = 0; i < (CARDNUM-REM)/PLAYER; i ++ )	/*17轮，每个玩家17张牌*/
		for( j = 0; j < PLAYER; j ++ ){				/*每轮发三个玩家*/
			do{
				k = rand() % 54;
			}while( flag[k] == 1 );		/*直到随机第K张牌没发出为止*/
			player[j][i] = card[k];		/*把第k张牌发给第j个玩家 是第j个玩家的第i张牌*/
			flag[k] = 1;				/*标记第k张牌已发出 */
		}
}

/*打印*/
void print( char * card[], char * player[PLAYER][(CARDNUM-REM)/PLAYER], int flag[CARDNUM] ){	/*打印发牌信息*/
	int i, j;

	for( i = 0; i < PLAYER; i ++ ){						/*所有玩家依次打印*/
		printf( "\n\n玩家%d:\n\n", i+1 );
		for( j = 0; j < (CARDNUM-REM)/PLAYER; j ++ ){	/*打印第i个玩家的所有牌*/
			printf( "%20s ", player[i][j] );
			if( ( j+1 ) % 2 == 0 )
				printf( "\n" );
		}
	}

	printf( "\n\n底牌:\n\n" );			/*打印所有没有发出的牌*/
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

	char str[4] = "yes";	/*标记是否重新发牌*/
	
	/*54张牌以字符串的形式定义*/
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

	int flag[CARDNUM];	/*标记card[i]是否发出 1为发出0则否*/

	srand( time( NULL ) );	/*带时间参数初始化随机发生器*/

	while( strcmp( str, "yes" ) == 0 ){		/*判断是否重新发牌*/
		system( "cls" );	/*清屏*/
		for( i = 0; i < CARDNUM; i ++ )	/*初始化全不发出*/
			flag[i] = 0;

		deal( card, player, flag );		/*发牌*/
		print( card, player, flag );	/*打印发牌结果*/

		printf( "\n\n是否重新发牌: (yes/no)" );
		scanf( "%s", str );
	}
}
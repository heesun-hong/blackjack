#include <stdio.h>
#include <stdlib.h>

#define N_CARDSET			1
#define N_CARD				52
#define N_DOLLAR			50


#define N_MAX_CARDNUM		13
#define N_MAX_USER			5
#define N_MAX_CARDHOLD		10
#define N_MAX_GO			17
#define N_MAX_BET			5

#define N_MIN_ENDCARD		30


//card tray object
int CardTray[N_CARDSET*N_CARD];
int cardIndex = 0;							
int card[52];
int cardnum;
//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
int cardcnt = 2;							//initial distribution of two cards


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag

//some utility functions

//get an integer input from standard input (keyboard)
//return : input integer value
//         (-1 is returned if keyboard input was not integer)



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	int calcStepResult();
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();
	printf("-->card is mixed and put into the tray\n\n");	


	//Game initialization --------
	//1. players' dollar
	
	//2. card tray
	mixCardTray();



	//Game start --------
	int roundCount=1;
	{printf("------------------------------------------------\n------------ ROUND %d (cardIndex:%d)--------------------------\n------------------------------------------------\n\n",roundCount,cardIndex);

		
		
		betDollar();
		offerCards(); //1. give cards to all the players
		printCardInitialStatus();
		
		printf("\n------------------ GAME start --------------------------\n");
		
		//my turn
		printf(">>> my turn! -------------\n");
		printUserCardStatus(1, cardcnt); 
		getAction();
		
		//each player's turn
		for (i=1;i<n_user;i++) //각 플레이어가 루프를 돌도록  
		{
			cardcnt = 2; 
			printf("\n\n>>> player %d turn! -------------\n", i);
			printUserCardStatus(i+1, cardcnt); 
			
			do 
			{
				if(calcStepResult(i+1)>17)
				break;
				cardhold[i+1][cardcnt] = pullCard(); 
				cardcnt++;
				printf("GO!\n"); 
				printUserCardStatus(i+1, cardcnt); //Show current card status
			} while (calcStepResult(i+1) < 17); ////Repeat receiving if credit card total is less than 17 
			if(calcStepResult(i+1)>16&&calcStepResult(i+1)<21)
				{
					printf("STAY!\n");	
				}
				else if(calcStepResult(i+1)>21)
				{
					printf("DEAD(sum:%d)-->-$%d ($%d)\n",calcStepResult(i+1),bet[i],dollar[i]-bet[i]);
				}
				else if(calcStepResult(i+1)==21)
				{
					printf("Black Jack!congratulation, you win!!\n");
				}			
		}
		//server's turn
		printf("\n\n>>> server turn! ------------------------\n");
		printUserCardStatus(0, cardcnt);
		cardcnt=2;
			do 
				{
					if(calcStepResult(0)>17)
					break;
					cardhold[0][cardcnt] = pullCard(); 
					cardcnt++;					
					printf("GO!\n"); 
					printUserCardStatus(0, cardcnt);
				} while (calcStepResult(0) < 17); 
				if(calcStepResult(0)>16&&calcStepResult(0)<21)
				{
					printf("STAY!\n");	
					printf("\n[[[[[[[ server result is .... %d ]]]]]]]",calcStepResult(0));
			
				}
				else if(calcStepResult(0)>21)
				{
					printf("server DEAD (sum:%d",calcStepResult(0));
					printf("\n[[[[[[[ server result is .... ....overflow!! ]]]]]]]");
				}
				else if(calcStepResult(0)==21)
				{
					printf(" Black Jack!T_T... server win\n");
					printf("[[[[[[[ server result is ....  Blackjack, T_T all remained players lose! ]]]]]]]");
				}
		 

	}
				
}






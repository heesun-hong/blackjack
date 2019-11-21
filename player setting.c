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
extern int cardIndex;							
extern int cardcnt;

//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 


int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


//player settiing
int configUser(void) 
{
	do
	{
		printf("Input the number of players (MAX:5):");
		n_user = getIntegerInput();
		printf("-->card is mixed and put into the tray\n");	

		if (n_user == -1)
		{
			printf("Invalid input players(%d).\n", n_user);
		}
		else if (n_user>5)
		{
			printf("Too many players!\n");
		}
		else if (n_user<1)
		{
			printf("Invalid input players(%d)\n.", n_user);
		}
		
	}while (n_user==-1||n_user<0||n_user>5);
	
}
//betting
int betDollar(void) {
	configUser();
	int i;
	
	dollar[0]=50;
	printf(" ------- BETTING STEP -------");
	do
	{	
		printf("->your betting (total:$%d) : ", dollar[0]);
		bet[0]=getIntegerInput();
		if (bet[0]==-1 || bet[0]<1)
		{
			printf("->invalid input for betting $%d\n", bet[0]);
		}
		else if (bet[0]>dollar[0])
		{
			printf("->you only have $%d! bet again\n", dollar[0]);
		} 
	
	}while (bet[0]==-1 ||bet[0]<1||bet[0]>dollar[0]);
	
	printf("your betting(total:$%d) : %d\n",dollar[0],bet[0]);
	
	for (i=1;i<n_user;i++)
	{
		bet[i]=1+rand()%5;
		dollar[i]=50;
		printf("->player%d bets $%d (out of $%d)\n", i,bet[i],dollar[i]);
	}
	printf("----------------------------\n");

	return 0;
			
}

//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
	printf("----------- CARD OFFERING ---------------\n");
	for (i=0;i<n_user;i++)
	{
		cardhold[i][0] = pullCard();
		cardhold[i][1] = pullCard();
	}
	//2. give two card for the operator
	cardhold[n_user][0] = pullCard();
	cardhold[n_user][1] = pullCard();
	
	return;
}

//print initial card status
void printCardInitialStatus(void) {
	int cardnum,j,i,X;
		X=cardhold[0][0];
		printf("--- server      : ");
		printf("X ",cardhold[0][0]);
		printCard(cardhold[0][1]);
			printf("\n");
		
		printf("  -> you        : ");
		for(j=0;j<2;j++)
			{
				cardnum=cardhold[1][j];
				printCard(cardnum);
			}
			printf("\n");
		
		for(i=2;i<n_user+1;i++)
			{
				printf("  -> player %d   : ",i-1);
				for(j=0;j<2;j++)
					{
						cardnum=cardhold[i][j];
						printCard(cardnum);
					}
				printf("\n");		
			}
}

//GO? STOP?
int getAction(void) {
	int input;
	int i;
	
	do
	{
		printf(" Action? (0 - go, others - stay) :");
		input = getIntegerInput();
		if (input==0)
		{
			cardhold[1][cardcnt] = pullCard();
			cardcnt++;
			printUserCardStatus(1, cardcnt);
		}	
	if (calcStepResult(1)>21)
	break;
	}
	while (input==0);
	
}


//print current card status
void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}

//check the card status
int calcStepResult(int user) {
	int i;
	int cardSum = 0;
	for (i=0;i<cardcnt;i++)
		cardSum += getCardNum(cardhold[user][i]); //You only need the cardSum of the players 
		
		
	return cardSum;
}

int checkResult() {
	
}

int checkWinner() {
	
}

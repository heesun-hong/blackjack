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


//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
int gameEnd = 0; 							//game end flag


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
	
	return 0;
			
}

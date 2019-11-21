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


//card array controllers -------------------------------


//mix the card sets and put in the array
int mixCardTray(void)
{
	int i,j;

	srand((unsigned)time(NULL));
	
	for (i=0;i<52;i++){
		CardTray[i]=1+rand()%52;
		for(j=1;j<i;j++){
			if(CardTray[i]==CardTray[j]){
				i--;
				break;
			}
		}
	}
	
	
	return 0;
		
}

//get one card from the tray
int pullCard(void) {
	cardIndex++;
	return CardTray[cardIndex-1];
	
}



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
int card[52];
extern int cardnum;
//player info
int dollar[N_MAX_USER];						//dollars that each player has
int n_user;									//number of users
extern int cardcnt;							//initial distribution of two cards


//play yard information
int cardhold[N_MAX_USER+1][N_MAX_CARDHOLD];	//cards that currently the players hold
int cardSum[N_MAX_USER];					//sum of the cards
int bet[N_MAX_USER];						//current betting 
extern int gameEnd; 							//game end flag//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
	int i;
	i=cardnum;
	if(i>0&&i<11)
	{
		return i;
	}
	else if(i>10&&i<14)
	{
		return 10;
	}
	else if(i>13&&i<24)
	{
		return (i-13);
	}
	else if(i>23&&i<27)
	{
		return 10;
	}
	else if(i>26&&i<37)
	{
		return(i-26);
	}
	else if(i>36&&i<40)
	{
		return 10;
	}
	else if(i>39&&i<50)
	{
		return (i-39);
	}
	else if(i>49&&i<53)
	{
		return 10;
	}
}


//print the card information (e.g. DiaA)
extern int printCard(int cardnum) {
	
	
	if (cardnum<11&&cardnum>0)
	{
		printf("DIA%d ",cardnum);
	}
	else if (cardnum==11)
	{
		printf("DIAJack ");
	}
	else if (cardnum==12)
	{
		printf("DIAQueen ");
	}
	else if (cardnum==13)
	{
		printf("DIAKing ");
	}
	else if (cardnum<24&&cardnum>13)
	{
		printf("CLV%d ",cardnum-13);
	}
	else if (cardnum==24)
	{
		printf("CLVJack ");
	}
	else if (cardnum==25)
	{
		printf("CLVQueen ");
	}
	else if (cardnum==26)
	{
		printf("CLVKing ");
	}
	else if (cardnum<37&&cardnum>26)
	{
		printf("SPD%d ",cardnum-26);
	}
	else if (cardnum==37)
	{
		printf("SPDJack ");
	}
	else if (cardnum==38)
	{
		printf("SPDQueen ");
	}
	else if (cardnum==39)
	{
		printf("SPDKing ");
	}
	else if (cardnum<50&&cardnum>39)
	{
		printf("HRT%d ",cardnum-39);
	}
	else if (cardnum==50)
	{
		printf("HRTJack ");
	}
	else if (cardnum==51)
	{
		printf("HRTQueen ");
	}
	else if (cardnum==52)
	{
		printf("HRTKing ");
	}

	return 0;
}


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
int getIntegerInput(void) {
    int input, num;
    
    num = scanf("%d", &input);
    fflush(stdin);
    if (num != 1) //if it fails to get integer
        input = -1;
    
    return input;
}


//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
}

//print the card information (e.g. DiaA)
void printCard(int cardnum) {
	
}


//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {

}

//get one card from the tray
int pullCard(void) {
}


//playing game functions -----------------------------

//player settiing
int configUser(void) {
	
}


//betting
int betDollar(void) {
	
}


//offering initial 2 cards
void offerCards(void) {
	int i;
	//1. give two card for each players
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
	int cardnum,j,i;
		printf("--- server      : ");
		printf("X ");
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

int getAction(void) {
	
}


void printUserCardStatus(int user, int cardcnt) {
	int i;
	
	printf("   -> card : ");
	for (i=0;i<cardcnt;i++)
		printCard(cardhold[user][i]);
	printf("\t ::: ");
}




// calculate the card sum and see if : 1. under 21, 2. over 21, 3. blackjack
int calcStepResult() {
	
}

int checkResult() {
	
}

int checkWinner() {
	
}



int main(int argc, char *argv[]) {
	int roundIndex = 0;
	int max_user;
	int i;
	
	srand((unsigned)time(NULL));
	
	//set the number of players
	configUser();
	printf("-->card is mixed and put into the tray\n");	


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
		
		printf(">>> my turn! -------------\n");
		printUserCardStatus(1, cardcnt); 
		getAction();
		
		//each player's turn
		for (i=1;i<n_user;i++) //each player
		{
			cardcnt = 2; //Initialize to 2 
			
			printf("\n>>> player %d turn! -------------\n", i);
			printUserCardStatus(i+1, cardcnt);
			do 
			{
				cardhold[i+1][cardcnt] = pullCard(); 
				cardcnt++;
				printf("\n"); 
				printUserCardStatus(i+1, cardcnt); //Show current card status
			} while (calcStepResult(i) < 17); //Repeat receiving if credit card total is less than 17 
			 
			 //do until the player dies or player says stop
			
				//print current card status printUserCardStatus();
				//check the card status ::: calcStepResult()
				//GO? STOP? ::: getAction()
				//check if the turn ends or not
		}
		
		//result
		checkResult();
	} while (gameEnd == 0);
	
	checkWinner();
	
	
	return 0;
}

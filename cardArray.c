//card array controllers -------------------------------

//mix the card sets and put in the array
int mixCardTray(void) {
	int i;
	int card[52];
	
	for (i=1;i<53;i++)
	card[i]=1+rand()%10;
	
	for (i=1;i<53;i++)
	printf("card[%d]=%d\n", i, card[i]);
	
	return 0;
}


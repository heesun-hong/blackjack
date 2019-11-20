//card processing functions ---------------

//calculate the actual card number in the blackjack game
int getCardNum(int cardnum) {
}


//print the card information (e.g. DiaA)
int printCard(int cardnum) {
	
	
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


#include<stdio.h>
void
main(void)
{	
	int change;
	int coins; 
	int amt=0;
	printf("O hai! How much change is owed?");
	scanf("%d",&change);
	
		coins=(int)(change/25);
		change=change-(coins*25);
		amt=amt+coins;
		coins=(int)(change/10);
		change=change-(coins*10);
		amt=amt+coins;
		coins=(int)(change/5);
		change=change-(coins*5);
		amt=amt+coins;
		coins=(int)(change/1);
		change=change-(coins*1);
		amt=amt+coins;
	
	
	printf("Number of coins required = %d",amt);
}

#include<stdio.h>
void
main(void)
{	
	double change;
	int coins; 
	int amt=0,index=0;
	double values[]={0.25,0.10,0.05,0.01};
	printf("O hai! How much change is owed?");
	scanf("%lf",&change);
	for(index=0;index<4;index++)
	{
		coins=(int)(change/values[index]);
		change=change-(coins*values[index]);
		amt=amt+coins;
	}
		
	printf("Number of coins required = %d",amt);
}

#include<stdio.h>
#include<math.h>
void
main(void)
{	
	double change;
	int coins,amt=0,index=0;
	printf("\ntest:%d\n",(int)fmod(0.01,0.01));
	float values[]={0.25,0.10,0.05,0.01};
	printf("O hai! How much change is owed?");
	scanf("%f",&change);
		for(index=0;index<4;index++)
		{
		printf("\nchange div remaining:%f\n",change/(float)values[index]);
		printf("\nchange:%f\n",change);
		printf("\ncoin amount:%f\n",values[index]);
		coins=(int)(change/(float)values[index]);
		change=change-(coins*values[index]);
		amt=amt+coins;
		printf("\nchange remaining:%f\n",change);
		printf("\ncoins remaining:%d\n",coins);
		}
	printf("Number of coins required = %d",amt);
}

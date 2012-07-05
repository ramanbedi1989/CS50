#include<stdio.h>
#include<cs50.h>
void 
main(void)
{
	int q=1;		
	while(q)
	{	
		printf("Days in months :");		
		int days;		
		scanf("%d",&days);
		if(days>27 && days<32)
		{
			while(q)
			{	
				long long pennies;
				printf("Pennies on first day :");		
				scanf("%lluLL",&pennies);
				if(pennies>0)
				{	long long j=0;
					int i=0;
					for(i=0;i<days;i++)
					{
						j=j+pennies;
						pennies=pennies*2;	
					}
					printf("Your total amount for the month = $%llu",j);
					q=0;
				}
			}
		}
	}
}

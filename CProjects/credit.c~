#include<stdio.h>
void
main (void)
{
	int validSerial(long long dup)
	{
		long long p;
		int bigSum;
		int use,index,sum=0,sum1=0,store[7],store1[8];
		for(index=1;index<8;index++)
		{	
			int i;
			long long pow=1;
			for(i=1;i<=index*2;i++)
			{
				pow=pow*10;
			}
			p=dup%pow;
			pow=pow/10;
			store[index-1]=p/pow;
		}
		for(index=0;index<7;index++)
		{
			if((store[index])<5)
			{
				store[index]=store[index]*2;			
			}
			else
			{
				store[index]=1+((store[index]*2)%10);			
			}
		}
		for(index=1;index<9;index++)
		{	
			int i;
			long long pow=1;
			for(i=1;i<=index*2-1;i++)
			{
				pow=pow*10;
			}
			p=dup%pow;
			pow=pow/10;
			store1[index-1]=p/pow;
		}
		for(index=0;index<7;index++)	
		{
			//printf("store[index]=%d\n",store[index]);
			sum=sum+store[index];		
		}
		for(index=0;index<8;index++)	
		{
			sum1=sum1+store1[index];		
		}
		bigSum=sum+sum1;
		//printf("sum,sum1,bigsum is %d %d %d",sum,sum1,bigSum);				
		if((bigSum%10) == 0)
		{
			return 1; 		
		}
		else
		{
			return 0;		
		}
	}	
	long long number;
	printf("Number :");
	scanf("%lluLL",&number);
	if((number>100000000000000) && (number<10000000000000000) )
	{
		//printf("\nThe function gives output as :%d\n",validSerial(number));
		if(validSerial(number) == 1)
		{
				if((number/100000000000000) == 4)
				{
					printf("VISA\n");
				}
				else if((number/10000000000000) == 34 || (number/10000000000000) == 37)
				{
					printf("AMEX\n");
				}
				else if((number/10000000000000) == 51 || (number/10000000000000) == 52 || (number/10000000000000) == 53 || (number/10000000000000) == 54 || (number/10000000000000) == 55)
				{
					printf("MASTERCARD\n");
				}
				else
				{
					printf("INVALID\n");
				}
		}
		else
		{
			printf("INVALID\n");
		}
	}
	else
	{
		printf("INVALID\n");
	}
}

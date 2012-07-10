#include<stdio.h>
#include<cs50.h>
#include <stdlib.h>
#include<string.h>
int main(int argc,string argv[])
{
	if(argc-1 == 1)
	{
		string final;		
		string p;
		p = (char*)malloc(256); 
		printf("enter your line to be cyphered\n");		
		fgets (p, 256 , stdin);
		int len= strlen(p);
		int i;
		char c[len];
		int key=atoi(argv[1]);
		for(i=0;i<len;i++)
		{
			if(p[i]>=65 && p[i]<=90)
			{
				c[i]=((((int)(p[i]-64+key))%26)+64);
			}
			else if(p[i]>=97 && p[i]<=122)
			{			
				c[i]=((((int)(p[i]-96+key))%26)+96);
			}
			else
			{
				c[i]=p[i];				
			}		
		}
		printf("\nyour cyphered text is as follows :\n");
		for(i=0;i<len;i++)
		{
			printf("%c",c[i]);
		}
		/*printf("your cyphered text is as follows :\n%s",final);*/
			
	}
	else
	{
		return 1;	
	}



}

#include<stdio.h>
#include<cs50.h>
#include <stdlib.h>
#include<string.h>
int main(int argc,string argv[])
{
	if(argc-1 == 1)
	{
		int i;	
		int temp=0;	
		string final;		
		string p;
		//printf("%s",argv[1]);
		int len1= strlen(argv[1]);
		int key[3*len1];		
		for(i=0;i<len1;i++)
		{
			if(argv[1][i]>=65 && argv[1][i]<=90)
			{
				key[i]=(argv[1][i]-65);
			}
			else
			{			
				key[i]=(argv[1][i]-97);
			}			
			//key[i]=argv[1][i];
			//printf("%d\n",key[i]);		
		}
		//printf("%d\n",(sizeof(key)/sizeof(int)));	
		p = (char*)malloc(256); 
		printf("enter your line to be cyphered\n");		
		fgets (p, 256 , stdin);
		int len= strlen(p);
		char c[len];
		int j=0;
		for(i=0;i<len;i++)
		{
			if(j != len1)
			{	
				if(p[i]>=65 && p[i]<=90)
				{
					if((((int)(p[i]-64+key[j]))%26) != 0)
					c[i]=((((int)(p[i]-64+key[j]))%26)+64);
					else
					c[i]='Z';
					j++;
				}	
				else if(p[i]>=97 && p[i]<=122)
				{	
					if((((int)(p[i]-96+key[j]))%26) != 0)		
					c[i]=((((int)(p[i]-96+key[j]))%26)+96);
					else
					c[i]='z';
					j++;
				}
				else
				{
					c[i]=p[i];				
				}			
			}
			else
			{	int inc;
				for(inc=0;inc<len1;inc++)
				{key[inc+j]=key[inc];}
				if(p[i]>=65 && p[i]<=90)
				{
					if((((int)(p[i]-64+key[j]))%26) != 0)
					c[i]=((((int)(p[i]-64+key[j]))%26)+64);
					else
					c[i]='Z';
					j++;
				}	
				else if(p[i]>=97 && p[i]<=122)
				{	
					if((((int)(p[i]-96+key[j]))%26) != 0)		
					c[i]=((((int)(p[i]-96+key[j]))%26)+96);
					else
					c[i]='z';
					j++;
				}
				else
				{
					c[i]=p[i];				
				}							
							
						
			}		
		}
		printf("\nyour cyphered text is as follows :\n");
				
		
		for(i=0;i<len;i++)
		{		
			printf("%c",c[i]);
		}
			
			/*int debug;
			debug=(sizeof(key)/sizeof(int));
			for(i=0;i<debug;i++)
			{printf("%d\n",key[i]);}*/
			
	}
	else
	{
		return 1;	
	}



}

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>
#define _XOPEN_SOURCE
void main (void)
{	
	string key;
	//key ="%cellowor",db;
	string result="50lMLvy/mlPIE";
	//void setkey (key);
	int edflag=1;
	int i,i1,i2,i3,i4,i5,i6,i7;
	//void encrypt (result,edflag);
	string salt="chartier";
	key=(char *)malloc(256);
	for(i=0;i<26;i++)
	{	
		for(i1=0;i1<26;i1++)
		{
			for(i2=0;i2<26;i2++)
			{
				for(i3=0;i3<26;i3++)
				{
					for(i4=0;i4<26;i4++)
					{
						for(i5=0;i5<26;i5++)
						{
							for(i6=0;i6<26;i6++)
							{
								for(i7=0;i7<26;i7++)
								{
									key[0]=(char)(97+i);
									key[1]=(char)(97+i1);
									key[2]=(char)(97+i2);
									key[3]=(char)(97+i3);
									key[4]=(char)(97+i4);
									key[5]=(char)(97+i5);
									key[6]=(char)(97+i6);
									key[7]=(char)(97+i7);
									string s=(string)crypt(key,salt);
									if(s == result)
									{					
										printf("\nthe key is%s\n",key);
										return;
									}
								}	
							}
						}
					}		
				}
			}
		}
	}
	printf("the end");
}

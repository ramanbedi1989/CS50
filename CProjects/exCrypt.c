#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#define _XOPEN_SOURCE
int main (void)
{	
	string key;
	//key ="%cellowor",db;
	string result="50q.zrL5e0Sak";
	//void setkey (key);
	//int edflag=1;
	//int i,i1,i2,i3,i4,i5,i6,i7;	//fgets(p,256,stdin);
	//void encrypt (result,edflag);
	string salt;
	key=(char *)malloc(256);
	salt=(char *)malloc(256);
	static const char filename[] = "wordsHack.txt";
   	FILE *file = fopen ( filename, "r" );
	static const char filename1[] = "wordsHack.txt";
   	FILE *file1 = fopen ( filename1, "r" );
	if ( file != NULL )
   	{
      		char line [ 128 ]; 
		char line1 [ 128 ];/* or other suitable maximum line size */
      		while ( fgets (line, sizeof(line), file ) != NULL ) /* read a line */
      		{
			key=line;
			while ( fgets (line1, sizeof(line1), file1 ) != NULL ) /* read a line */
      			{
         			salt=line1;
				string s=(string)crypt(key,salt);
				//printf("\nthe result is%s\n",result);
			  	if(!strcmp(s,result))
				{					
				printf("\nthe key is %s\n",key);
				return 1;
				}
			}      		
		}
      		fclose ( file );
		fclose ( file1 );
   	}
   	else
   	{
      		perror ( filename );
		printf("I am here......"); /* why didn't the file open? */
   	}
   	return 0;
}

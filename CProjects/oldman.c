#include<stdio.h>
#include<string.h>
#include<cs50.h>
void 
main(void)
{
	int i=0;
	string number[]={"ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN"};
	string name[]={"ON MY THUMB","ON MY SHOE","ON MY KNEE","ON MY DOOR","ON MY HIVE","ON MY STICKS","UP IN HEAVEN","ON MY GATE","ON MY SPINE","ONCE AGAIN"};
	for(i=0;i<10;i++)
	{
		printf("THIS OLD MAN, HE PLAYED %s\nHE PLAYED KNICK-KNACK ON MY %s\nKNICK-KNACK PADDYWHACK, GIVE YOUR DOG A BONE\nTHIS OLD MAN CAME ROLLING HOME\n\n",number[i],name[i]);	
	}

}

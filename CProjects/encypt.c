#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#define _XOPEN_SOURCE
void main(void)
{
	string key="password";
	string salt="50";
	//string result="50lMLvy/mlPIE";
	//result=(char *)malloc(13);
	string s=(string)crypt(key,salt);
	//setkey(key);	
	//encrypt(result,50);
	//struct {*}data;
	//data=(struct {*})malloc(100);
	//setkey_r (key, {*}data);
	printf("%s\n",s);
	//printf("%s\n",result);


}

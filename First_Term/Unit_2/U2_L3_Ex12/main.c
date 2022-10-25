/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */

#include <stdio.h>


void main()
{
	char ch;
	printf("Enter a character : "); //print
	fflush(stdin); fflush(stdout); //clear buffer
	scanf("%c", &ch); //take char from user
	if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
	{
		printf("%c is an alphabet.\n", ch); //print
	}
	else
	{
		printf("%c is not an alphabet.\n", ch); //print
	}
}

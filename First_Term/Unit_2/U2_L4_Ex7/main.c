/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: User
 */
#include <stdio.h>

int main()
{
	char string[100];
	int counter = 0;

	printf("Enter a string      : ");
	fflush(stdin); fflush(stdout);
	gets(string);

	while( string[counter] != 0 )
	{
		counter++;
	}

	printf("length of string is : %d\n", counter);

	return 0;
}

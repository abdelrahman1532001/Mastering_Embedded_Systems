/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: User
 */
#include <stdio.h>
int main()
{
	int counter = 0, str_size;
	char string[50], string_reversed[50];

	printf("Enter the string  :");
	fflush(stdin); fflush(stdout);
	gets(string);

	while( string[counter] != 0 )
	{
		counter++;
	}
	str_size = counter;
	string_reversed[str_size] = 0;
	counter = 0;
	while( string[counter] != 0 )
	{
		string_reversed[str_size-1] = string[counter];
		counter++;
		str_size--;
	}
	printf("reverse string is :%s\n", string_reversed);

	return 0;
}


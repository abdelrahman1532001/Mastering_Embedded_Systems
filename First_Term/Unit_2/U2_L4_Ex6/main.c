/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: User
 */
#include <stdio.h>
int main()
{
	int counter = 0;
	char string[100], search_char, char_freq = 0;

	printf("enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(string);

	printf("enter a char to find frequency :");
	fflush(stdin); fflush(stdout);
	scanf("%c", &search_char);

	while(string[counter] != 0)
	{
		if( string[counter] == search_char )
		{
			char_freq++;
			counter++;
		}
		else
		{
			counter++;
		}
	}

	printf("Frequency of %c is %d.\n", search_char, char_freq);

	return 0;
}


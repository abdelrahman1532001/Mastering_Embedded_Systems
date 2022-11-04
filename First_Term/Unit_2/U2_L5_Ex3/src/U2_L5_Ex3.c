/*
 ============================================================================
 Name        : U2_L5_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void string_reverse(void);

int main(void) {



	printf("Enter a sentence: ");
	string_reverse();
	return EXIT_SUCCESS;
}
void string_reverse( void)
{
	char c;
	fflush(stdout);
	scanf("%c", &c);
	if( c != '\n' )
	{
		string_reverse();
		printf("%c", c);

	}

}


/*
 ============================================================================
 Name        : U2_L5_Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
unsigned int calc_fact( unsigned int number );
int main(void) {

	int number;
	printf("Enter a positive integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number); ///take positive number from user
	printf("Factorial of %d is %u", number, calc_fact( number ));
	return EXIT_SUCCESS;
}//end main
//function to calculate factorial
unsigned int calc_fact( unsigned int number )
{
	unsigned int fact = 1;
	//condition to stop recursion
	if( number == 0 || number == 1 )
	{
		fact = 1;
	}
	else
	{
		fact = number * calc_fact( ( number - 1 ));
	}
	return fact;
}//end function /* calc_fact() */

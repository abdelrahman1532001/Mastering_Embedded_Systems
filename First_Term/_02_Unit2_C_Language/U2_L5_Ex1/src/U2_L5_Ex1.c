/*
 ============================================================================
 Name        : U2_L5_Ex1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int check_intPrime( unsigned int number );


int main(void) {

	unsigned char counter;//declaration and definition
	unsigned int start_num, end_num; //declaration and definition
	printf("Enter two numbers(intervals): "); //print
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &start_num, &end_num); //take intervals from user
	printf("Prime numbers between %d and %d are:", start_num, end_num); //print
    //loop to print prime numbers between intervals
	for( counter = start_num; counter < end_num; counter++ )
	{
		//if true then number is prime
		if( check_intPrime( counter ) )
		{
			printf(" %d", counter);
		} //end if
	} //end for
	return EXIT_SUCCESS;
} //end main

//return 1 for prime && 0 for not prime
int check_intPrime( unsigned int number )
{
	char counter;
	char prime_Flag=1;
	//loop to check prime or not
	for( counter = 2; counter < 10; counter++ )
	{
		//if true then number is not prime
		if( ( number % counter ) == 0 && counter != number )
		{
			prime_Flag = 0; //number is not prime
			break; //exit from loop
		}//end if
	}
	return prime_Flag;
}

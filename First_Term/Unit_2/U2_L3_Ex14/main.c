/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */

#include <stdio.h>

void main()
{
    int num, fact = 1, count;
	printf("Enter an integer : "); //print
	fflush(stdin); fflush(stdout); //clear buffers
	scanf("%d", &num); //take an positive integer
	// calculate factorial
	if( num == 0 )
	{
		printf("Factorial = %d", fact);
	}
	else if( num > 0 )
	{
		for( count = 2; count <= num; count++ )
		{
			fact *= count;
		}
		printf("Factorial = %d", fact); //print
	}
	else
	{
		printf("Error! Factorial negative does not exist.\n");
	}
}

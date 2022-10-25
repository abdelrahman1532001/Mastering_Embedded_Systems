/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */

#include <stdio.h>

void main()
{
	unsigned int num, sum = 0, count;
	printf("Enter an integer : "); //print
	fflush(stdin); fflush(stdout); //clear buffers
	scanf("%d", &num); //take integer from user
	// calculate sum of natural numbers
	if( num > 0 )
	{
		for( count = 1; count <= num; count++ )
		{
			sum += count;
		}
	}
	printf("Sum = %d", sum); //print sum
}

/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */

#include <stdio.h>

void main()
{
    float num;
	printf("Enter a number : "); //print
	fflush(stdin); fflush(stdout); //clear buffer
	scanf("%f", &num); //take number from user
	//check positive or negative
	if( num == 0 )
	{
		printf("You entered zero.\n");
	}
	else if( num > 0 )
	{
		printf("%.2f is positive.\n", num);
	}
	else
	{
		printf("%.2f is negative.\n", num);
	}
}

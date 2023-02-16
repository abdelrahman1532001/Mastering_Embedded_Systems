/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: Abdelrahman
 */
#include <stdio.h>

void main()
{
	int number; //declare variable
	printf("Enter number : "); //print on screen
	fflush(stdin); fflush(stdout); //clear buffers
	scanf("%d", &number); //take integer number from user
	//check number odd or even
	if( (number % 2) == 0 )
	{
		printf("number is even!\n");
	}
	else
	{
		printf("number is odd!\n");
	}
	//another solution with one line
    //( (number % 2 ) == 0 ) ? printf("number is even\n") : printf("number is odd\n");
}


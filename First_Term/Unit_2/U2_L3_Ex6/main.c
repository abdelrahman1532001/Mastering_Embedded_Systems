/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: User
 */
#include "stdio.h"

void main()
{
	//create 3 variables
	float num1, num2, swap;
	//taking number 1
	printf("Enter number 1: ");
	//clear buffer
	fflush(stdout); fflush(stdin);
	//take float number from user
	scanf("%f", &num1);
	//taking number 2
	printf("Enter number 2: ");
	//clear buffer
	fflush(stdout); fflush(stdin);
	//take float number from user
	scanf("%f", &num2);
	//swap two number
	swap = num1;
	num1 = num2;
	num2 = swap;
	//print numbers after swapping
	printf("after swapping, num1 = %f\n", num1);
	printf("after swapping, num2 = %f\n", num2);
}//end main

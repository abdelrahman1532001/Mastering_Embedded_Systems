/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: User
 */
#include <stdio.h>
void main()
{
	//two integer
	int num1, num2;
	//take num1
	printf("num1 = ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num1);
	//take num2
	printf("num2 = ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num2);
	//swap
	num1 = num1 + num2; //num1 = 5 , num2 = 4 --> num1 = 5 + 4
	num2 = num1 - num2; //num2 = (5 + 4) - 4 = 5
	num1 = num1 - num2; //num1 = (5 + 4) - 5 = 4
	//print two numbers
	printf("num1 = %d \nnum2 = %d\n", num1, num2);
}

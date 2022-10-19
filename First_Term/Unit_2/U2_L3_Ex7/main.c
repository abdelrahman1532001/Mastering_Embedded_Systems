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
	printf("after swap without temp, num1 = %d\n", num2);
	printf("after swap without temp, num2 = %d\n", num1);
}

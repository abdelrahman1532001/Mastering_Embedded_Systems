/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: Abdelrahman
 */

#include "stdio.h"

void main()
{
	//initialization
	int Sum = 0;
	//declaration
	int i_1, i_2;
	//print
	printf("Enter Two Integer :");
	//clear buffers
	fflush(stdout); fflush(stdin);
	//read integers from user
	scanf("%d %d", &i_1, &i_2);
	//sum integer and print sum
	Sum = i_1 + i_2;
	printf("Sum = %d\n", Sum);

}//end main




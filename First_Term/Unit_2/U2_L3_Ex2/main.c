/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: Abdelrahman
 */

#include "stdio.h"

void main()
{
	//declaration
	int i;
	//print on screen
	printf("Enter Integer Number :");
	//clear buffering
	fflush(stdout); fflush(stdin);
	//take integer from user
	scanf("%d", &i);
	//print integer on screen
	printf("You Enter            :%d\n", i);

}//end main



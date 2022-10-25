/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: User
 */
#include <stdio.h>

void main()
{
	float num1, num2, num3; //three variables
	printf("Enter three numbers : \n"); //print
	fflush(stdin); fflush(stdout); //clear buffers
	scanf("%f %f %f", &num1, &num2, &num3); //take three numbers from user
	//compare and find biggest number
	if( num1 >= num2 )
	{
		if( num1 >= num3 )
		{
			printf("Largest number is %f.", num1); //print num1 on screen
		}
		else
		{
			printf("Largest number is %f.", num3); //print num3 on screen
		}
	}
	else if( num2 > num1  )
	{
		if( num2 > num3 )
		{
			printf("Largest number is %f.", num2); //print num2 on screen
		}
		else
		{
			printf("Largest number is %f.", num3); //print num3 on screen
		}
	}
	//another solution
	/*if( (num1 > num2) && (num1 > num3 ) )
	{
		printf("\nLargest number is %f.", num1);
	}
	else if( (num2 > num1) && (num2 > num3) )
	{
		printf("\nLargest number is %f.", num2);
	}
	else
	{
		printf("\nLargest number is %f.", num3);
	}*/
}

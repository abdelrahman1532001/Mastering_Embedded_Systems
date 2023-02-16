/*
 * main.c
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */

#include "stdio.h"

void main ()
{
	float arr1[2][2], arr2[2][2];
	int row, col;
	printf("Enter elements of 1st array : \n");
	fflush(stdout); fflush(stdin);
	for( row = 0; row < 2; row++ )
	{
		for( col = 0; col < 2; col++ )
		{
			printf("arr1[%d][%d] = ", row, col);
			fflush(stdout); fflush(stdin);
			scanf("%f", &arr1[row][col]);
		}
	}
	printf("Enter elements of 2nd array : \n");
	fflush(stdout); fflush(stdin);
	for( row = 0; row < 2; row++ )
	{
		for( col = 0; col < 2; col++ )
		{
			printf("arr2[%d][%d] = ", row, col);
			fflush(stdout); fflush(stdin);
			scanf("%f", &arr2[row][col]);
		}
	}
	printf("Sum of matrix:\n");
	for( row = 0; row < 2; row++ )
	{
		for( col = 0; col < 2; col++ )
		{
			printf("%.1f   ", arr1[row][col] + arr2[row][col]);
		}
		printf("\n");
	}

}

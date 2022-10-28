/*
 * main.c
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */
#include "stdio.h"

void main()
{
	float arr[50][50], arr_trans[50][50];
	int arr_rows, arr_cols, counter_row, counter_col;

	printf("Enter row && col : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &arr_rows, &arr_cols);

	printf("Elements of matrix:\n");
	for( counter_row = 0; counter_row < arr_rows; counter_row++ )
	{
		for( counter_col = 0; counter_col < arr_cols; counter_col++ )
			{
				printf("Element[%d][%d]: ", counter_row, counter_col);
				fflush(stdin); fflush(stdout);
				scanf("%f", &arr[counter_row][counter_col]);
				arr_trans[counter_col][counter_row] = arr[counter_row][counter_col];
			}
	}
	printf("Trans array :\n");
	for( counter_row = 0; counter_row < arr_cols; counter_row++ )
	{
		for( counter_col = 0; counter_col < arr_rows; counter_col++ )
			{
				printf("%.f  ", arr_trans[counter_row][counter_col]);
			}
		printf("\n");
	}

}

/*
 * main.c
 *
 *  Created on: Oct 28, 2022
 *      Author: User
 */
#include "stdio.h"

void main()
{
	float arr[15], sum = 0;
	int counter, n;
	printf("Enter number of element to calc average : (note number < 15)\n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);
	for( counter = 0; counter < n; counter++ )
	{
		printf("Enter number %d :", counter + 1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &arr[counter]);
		sum += arr[counter];
	}
	printf("Average = %.1f\n", (sum / n));
}

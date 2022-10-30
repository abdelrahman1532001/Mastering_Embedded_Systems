/*
 * main.c
 *
 *  Created on: Oct 30, 2022
 *      Author: User
 */
#include <stdio.h>
int main()
{
	int arr_size, counter;
	float arr[ 100 ], search_elem;
	printf("Enter number of elements :");
	fflush(stdin); fflush(stdout);
    scanf("%d", &arr_size);
    printf("Enter ELements:\n");
    //take elements of array
    for(counter = 0; counter < arr_size; counter++)
    {
    	fflush(stdin); fflush(stdout);
    	scanf("%f", &arr[counter]);
    }
    printf("Enter ELement to search for:\n");
	fflush(stdin); fflush(stdout);
	scanf("%f", &search_elem);
    for(counter = 0; counter < arr_size; counter++)
    {
    	if( arr[counter] == search_elem )
    	{
    		printf("Number found at location : %d", counter+1);
    		break;
    	}
    }
	return 0;
}


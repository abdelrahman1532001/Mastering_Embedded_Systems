/*
 * main.c
 *
 *  Created on: Oct 29, 2022
 *      Author: User
 */

#include "stdio.h"

int main()
{
	int arr_s, counter, elem_pos;
	float arr[20], insrt_elem, temp;
	printf("Enter no of Elements :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &arr_s);
	if( arr_s < 20 )
	{
		for( counter = 0; counter < arr_s; counter++ )
		{
			scanf("%f", &arr[counter]);
		}

		printf("the Element to be inserted : ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &insrt_elem);

		printf("Enter the location : ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &elem_pos);

		arr_s++; //increase size of array to take inserted value
		for( counter = 0; counter < arr_s; counter++ )
		{
			//do not do anything before position of insert value
		    if( counter+1 >= elem_pos )
			{
		    	//temp = arr[counter]; //save the value before write insert value over it
				//arr[counter] = insrt_elem; //assign this position to insert element
				//insrt_elem = temp; //insert element change for next loop

				//without using temp
				insrt_elem += arr[counter]; // assume insert=6, arr[counter]=5 then insert = 6 + 5
				arr[counter] = insrt_elem - arr[counter]; // arr[counter] = (6 + 5) - 5 = 6 we changed value to origin insert
				insrt_elem = insrt_elem - arr[counter]; // insert = (6 + 5) - 6 = 5 we change insert to next iteration
			}
		}
		for( counter = 0; counter < arr_s; counter++ )
		{
			printf("%.2f  ", arr[counter]);
		}

	}

	return 0;
}

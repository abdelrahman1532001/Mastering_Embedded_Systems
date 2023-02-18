/*
 	 @author Eng.Abdelrahman Reda
 	 @file	 main.c
 	 @date   2/18/2023
 	 @course Learn-In-Depth Online Diploma
 */
#include "stdio.h"
#include "LIFO.h"

unsigned int U32Buffer1[6];

int main(  )
{
	unsigned int i, item=0, counter;
	LIFO_t Uart_LIFOBuffer;

	LIFO_init(&Uart_LIFOBuffer, U32Buffer1, 5);

	for( i = 0; i < 10; i++ )
	{
		LIFO_Add_U32Item(&Uart_LIFOBuffer, i);
	}
	LIFO_Count_U32Items(&Uart_LIFOBuffer, &counter);
	printf("number of item : %d\n", counter);
	LIFO_Get_U32Item(&Uart_LIFOBuffer, &item);
	printf("top item : %d\n", item);
	LIFO_Count_U32Items(&Uart_LIFOBuffer, &counter);
	printf("number of item : %d\n", counter);

	LIFO_Free(&Uart_LIFOBuffer);
	LIFO_Count_U32Items(&Uart_LIFOBuffer, &counter);

	printf("number of item : %d\n", counter);
	for( i = 0; i < 10; i++ )
	{
		LIFO_Get_U32Item(&Uart_LIFOBuffer, i);
	}
	LIFO_Count_U32Items(&Uart_LIFOBuffer, &counter);
	printf("number of item : %d\n", counter);

	return 0;
}



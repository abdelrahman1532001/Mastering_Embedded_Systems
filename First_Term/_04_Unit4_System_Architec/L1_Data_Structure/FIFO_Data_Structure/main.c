/*
 	 @author Eng.Abdelrahman Reda
 	 @file	 main.c
 	 @date   2/18/2023
 	 @course Learn-In-Depth Online Diploma
 */
#include "stdio.h"
#include "stdint.h"
#include "FIFO.h"

int main( void )
{
	FIFO_Error_Status Error2;
	uint16_t  U16_Buffer[5];
	S_FIFO_t Uart_U16_FIFO_Buffer;
	FIFO_Item_Init(&Uart_U16_FIFO_Buffer , U16_Buffer , 2);

	printf("base address : %p \n", (Uart_U16_FIFO_Buffer.P_ItemBuff_Base) );
	printf("top  address : %p \n", (Uart_U16_FIFO_Buffer.P_ItemBuff_Base) + (Uart_U16_FIFO_Buffer.U32Length) );
	printf("\n");


	return 0;

	FIFO_Error_Status Error;
	uint32_t U32_Buffer[6];
	uint32_t i, item=0;
	S_U32FIFO_t Uart_U32_FIFO_Buffer;
	FIFO_U32_Init (&Uart_U32_FIFO_Buffer, U32_Buffer, 3);

	printf("base address : %p \n", (Uart_U32_FIFO_Buffer.P_U32Base) );
	printf("head address : %p \n", (Uart_U32_FIFO_Buffer.P_U32Head) );
	printf("Length       : %d (%u Byte) \n", (Uart_U32_FIFO_Buffer.U32Length), sizeof(uint32_t) );
	printf("top  address : %p \n", (Uart_U32_FIFO_Buffer.P_U32Base) + (Uart_U32_FIFO_Buffer.U32Length) );
	printf("===========================================================\n");
	for(i=0 ; i<4 ; i++)
	{
		Error = FIFO_U32_Enqueue(&Uart_U32_FIFO_Buffer, i); /* return error status to test */

		if(Error == FIFO_no_error)
			printf("Enqueue %d success, no error, head address = %p\n", i, Uart_U32_FIFO_Buffer.P_U32Head);
		else if(Error == FIFO_null)
			printf("Enqueue %d failed, null error\n", i);
		else if(Error == FIFO_full)
		{
			printf("Enqueue %d failed, full error, head address = %p\n", i, Uart_U32_FIFO_Buffer.P_U32Head);

		}
	}
	printf("===========================================================\n");
	Error = FIFO_U32_Print(&Uart_U32_FIFO_Buffer);
	if( Error == FIFO_no_error)
		printf("print items success\n");
	else if(Error == FIFO_null)
		printf("print items failed, null error\n");
	else if(Error == FIFO_empty)
		printf("empty FIFO\n");
	printf("===========================================================\n");
	for(i=0 ; i<2 ; i++)
	{
		Error = FIFO_U32_Dequeue(&Uart_U32_FIFO_Buffer, &item); /* return error status to test */

		if(Error == FIFO_no_error)
			printf("Dequeue %d success, no error\n", item);
		else if(Error == FIFO_null)
			printf("Dequeue failed, null error\n");
		else if(Error == FIFO_empty)
			printf("Dequeue failed, empty error\n");
	}
	printf("===========================================================\n");
	Error = FIFO_U32_Print(&Uart_U32_FIFO_Buffer);
	if( Error == FIFO_no_error)
		printf("print items success\n");
	else if(Error == FIFO_null)
		printf("print items failed, null error\n");
	else if(Error == FIFO_empty)
		printf("empty FIFO\n");
	printf("===========================================================\n");
	for(i=0 ; i<3 ; i++)
	{
		Error = FIFO_U32_Enqueue(&Uart_U32_FIFO_Buffer, i); /* return error status to test */

		if(Error == FIFO_no_error)
			printf("Enqueue %d success, no error, head address = %p\n", i, Uart_U32_FIFO_Buffer.P_U32Head);
		else if(Error == FIFO_null)
			printf("Enqueue %d failed, null error\n", i);
		else if(Error == FIFO_full)
		{
			printf("Enqueue %d failed, full error, head address = %p\n", i, Uart_U32_FIFO_Buffer.P_U32Head);

		}
	}
	printf("===========================================================\n");
	Error = FIFO_U32_Print(&Uart_U32_FIFO_Buffer);
	if( Error == FIFO_no_error)
		printf("print items success\n");
	else if(Error == FIFO_null)
		printf("print items failed, null error\n");
	else if(Error == FIFO_empty)
		printf("empty FIFO\n");
	printf("===========================================================\n");

	return 0;
}



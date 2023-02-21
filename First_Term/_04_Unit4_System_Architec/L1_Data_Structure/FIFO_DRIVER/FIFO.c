/*
 	 @author Eng.Abdelrahman Reda
 	 @file	 FIFO.c
 	 @date   2/18/2023
 	 @course Learn-In-Depth Online Diploma
 */
#include "FIFO.h"

#include "stdio.h"

/****************************************************************************************************
	@job        -use this function when you want to initialize your LIFO buffer, So you can use it.
				*************************************************************************************
*****************************************************************************************************
 	@inputs		-argument1 => pointer to variable of type LIFO_t.
 				-argument2 => address of static array.
				-argument3 => length of your LIFO buffer (must less than or equal size of array).
				*************************************************************************************
*****************************************************************************************************
	@output		-return indication if the pushing success or not.
	 	 	 	-success => function return (LIFO_Noerror).
	 	 	 	-failed  => function return (LIFO_Full).
	 	 	 	*************************************************************************************
*****************************************************************************************************/
FIFO_Error_Status FIFO_Item_Init(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE* Copy_P_Buffer, uint32_t Copy_Buff_Length)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( Copy_P_Buffer != NULL_POINTER )
	{
		FIFO_Pname->P_ItemBuff_Base = Copy_P_Buffer;
		FIFO_Pname->P_ItemBuff_Tail = FIFO_Pname->P_ItemBuff_Base;
		FIFO_Pname->P_ItemBuff_Head = FIFO_Pname->P_ItemBuff_Base;
		FIFO_Pname->P_ItemBuff_Top  = (FIFO_Pname->P_ItemBuff_Base) + (Copy_Buff_Length);
		FIFO_Pname->U32Counter      = ZERO;
		FIFO_Pname->U32Length       = Copy_Buff_Length;
	}
	else
	{
		Error = FIFO_init_error;
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Init (S_U8FIFO_t * U8FIFO_Pname , uint8_t * Copy_P_U8Buffer , uint32_t Copy_U8Buff_Length )
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( Copy_P_U8Buffer != NULL_POINTER )
	{
		U8FIFO_Pname->P_U8Tail  = Copy_P_U8Buffer   ;
		U8FIFO_Pname->P_U8Base  = Copy_P_U8Buffer   ;
		U8FIFO_Pname->P_U8Head  = Copy_P_U8Buffer   ;
		U8FIFO_Pname->U32Length = Copy_U8Buff_Length;
	}
	else
	{
		Error = FIFO_init_error;
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Init(S_U16FIFO_t* U16FIFO_Pname, uint16_t* Copy_P_U16Buffer, uint32_t Copy_U16Buff_Length)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( Copy_P_U16Buffer != NULL_POINTER )
	{
		U16FIFO_Pname->P_U16Tail = Copy_P_U16Buffer   ;
		U16FIFO_Pname->P_U16Base = Copy_P_U16Buffer   ;
		U16FIFO_Pname->P_U16Head = Copy_P_U16Buffer   ;
		U16FIFO_Pname->U32Length = Copy_U16Buff_Length;
	}
	else
	{
		Error = FIFO_init_error;
	}
	return Error;
}
FIFO_Error_Status FIFO_U32_Init(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Buffer, uint32_t Copy_U32Buff_Length)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( Copy_P_U32Buffer != NULL_POINTER )
	{
		U32FIFO_Pname->P_U32Tail = Copy_P_U32Buffer   ;
		U32FIFO_Pname->P_U32Base = Copy_P_U32Buffer   ;
		U32FIFO_Pname->P_U32Head = Copy_P_U32Buffer   ;
		U32FIFO_Pname->U32Length = Copy_U32Buff_Length;
	}
	else
	{
		Error = FIFO_init_error;
	}
	return Error;
}
/****************************************************************************************************
	@job        -use this function when you want to push element in your LIFO buffer.
				-please make sure you initialize your LIFO buffer, before using this function.
				-note that this function add 4 byte by 4 byte.
				*************************************************************************************
*****************************************************************************************************
 	@inputs		-argument1 is pointer to your initialized LIFO buffer.
				-argument2 is unsigned integer to be pushed in the top of the buffer.
				*************************************************************************************
*****************************************************************************************************
	@output		-return indication if the pushing success or not.
	 	 	 	-success => function return (LIFO_Noerror).
	 	 	 	-failed  => function return (LIFO_Full).
	 	 	 	*************************************************************************************
*****************************************************************************************************/
FIFO_Error_Status FIFO_Item_Enqueue(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE Item)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer full or not before adding any item */
	if( ((FIFO_Pname->U32Counter) < (FIFO_Pname->U32Length)) && ((FIFO_Pname->P_ItemBuff_Base) != NULL) )
	{
		*(FIFO_Pname->P_ItemBuff_Head) = Item; /* add item in buffer */
		(FIFO_Pname->P_ItemBuff_Head)++; /* make head point to next item to be ready for following add */
		(FIFO_Pname->U32Counter)++;  /* update counter after adding */
		if((FIFO_Pname->P_ItemBuff_Head) == (FIFO_Pname->P_ItemBuff_Top))/* if head reach to top */
		{
			(FIFO_Pname->P_ItemBuff_Head) = (FIFO_Pname->P_ItemBuff_Base);
		}
	}
	else if( (FIFO_Pname->U32Counter) == (FIFO_Pname->U32Length) )
	{
		Error = FIFO_full; /* this will happen if (counter = length) */
	}
	else
	{
		Error = FIFO_null; /* this will happen if not found */
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Enqueue (S_U8FIFO_t * U8FIFO_Pname , uint8_t  U8Item )
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer full or not before adding any item */
	if( ((U8FIFO_Pname->U32Counter) < (U8FIFO_Pname->U32Length)) && ((U8FIFO_Pname->P_U8Head) != NULL) )
	{
		*(U8FIFO_Pname->P_U8Head) = U8Item; /* add item in buffer */
		(U8FIFO_Pname->P_U8Head)++; /* make head point to next item to be ready for following add */
		(U8FIFO_Pname->U32Counter)++;  /* update counter after adding */
		if((U8FIFO_Pname->P_U8Head) == ((U8FIFO_Pname->P_U8Base) + (U8FIFO_Pname->U32Length)))/* if head reach to top */
		{
			(U8FIFO_Pname->P_U8Head) = (U8FIFO_Pname->P_U8Base);
		}
	}
	else if( (U8FIFO_Pname->U32Counter) >= (U8FIFO_Pname->U32Length) )
	{
		Error = FIFO_full; /* this will happen if (counter = length) */
	}
	else
	{
		Error = FIFO_null; /* this will happen if not found */
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Enqueue(S_U16FIFO_t* U16FIFO_Pname, uint16_t U16Item)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer full or not before adding any item */
	if( ((U16FIFO_Pname->U32Counter) < (U16FIFO_Pname->U32Length)) && ((U16FIFO_Pname->P_U16Head) != NULL) )
	{
		*(U16FIFO_Pname->P_U16Head) = U16Item; /* add item in buffer */
		(U16FIFO_Pname->P_U16Head)++; /* make head point to next item to be ready for following add */
		(U16FIFO_Pname->U32Counter)++;  /* update counter after adding */
		if((U16FIFO_Pname->P_U16Head) == ((U16FIFO_Pname->P_U16Base) + (U16FIFO_Pname->U32Length)))/* if head reach to top */
		{
			(U16FIFO_Pname->P_U16Head) = (U16FIFO_Pname->P_U16Base);
		}
	}
	else if( (U16FIFO_Pname->U32Counter) >= (U16FIFO_Pname->U32Length) )
	{
		Error = FIFO_full; /* this will happen if (counter = length) */
	}
	else
	{
		Error = FIFO_null; /* this will happen if not found */
	}
	return Error;
}
FIFO_Error_Status FIFO_U32_Enqueue(S_U32FIFO_t* U32FIFO_Pname, uint32_t U32Item)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer full or not before adding any item */
	if( ((U32FIFO_Pname->U32Counter) < (U32FIFO_Pname->U32Length)) && ((U32FIFO_Pname->P_U32Head) != NULL) )
	{
		*(U32FIFO_Pname->P_U32Head) = U32Item; /* add item in buffer */
		(U32FIFO_Pname->P_U32Head)++; /* make head point to next item to be ready for following add */
		(U32FIFO_Pname->U32Counter)++;  /* update counter after adding */
		if((U32FIFO_Pname->P_U32Head) == ((U32FIFO_Pname->P_U32Base) + (U32FIFO_Pname->U32Length)))/* if head reach to top */
		{
			(U32FIFO_Pname->P_U32Head) = (U32FIFO_Pname->P_U32Base);
		}
	}
	else if( (U32FIFO_Pname->U32Counter) >= (U32FIFO_Pname->U32Length) )
	{
		Error = FIFO_full; /* this will happen if (counter = length) */
	}
	else
	{
		Error = FIFO_null; /* this will happen if not found */
	}
	return Error;
}
/****************************************************************************************************
	@job        -use this function when you want to pop element from your LIFO buffer.
				-please make sure you initialize your LIFO buffer, before using this function.
				-note that this function get 4 byte by 4 byte
				*************************************************************************************
*****************************************************************************************************
 	@inputs		-argument1 is pointer to your initialized LIFO buffer.
				-argument2 is pointer to unsigned integer variable you want to store popped data in.
				*************************************************************************************
*****************************************************************************************************
	@output		-return indication if the popping success or not.
	 	 	 	-success => function return (LIFO_Noerror).
	 	 	 	-failed  => function return (LIFO_Full).
	 	 	 	*************************************************************************************
*****************************************************************************************************/
FIFO_Error_Status FIFO_Item_Dequeue(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE* Copy_P_Var)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer is empty or not before popping*/
	if( (FIFO_Pname->U32Counter) > ZERO && (FIFO_Pname->P_ItemBuff_Base != NULL))
	{
		*(Copy_P_Var) = *(FIFO_Pname->P_ItemBuff_Tail); /* put value which in tail in the variable */
		(FIFO_Pname->P_ItemBuff_Tail)++;  /* make tail pointer points to the next item should be dequeue */
		(FIFO_Pname->U32Counter)--; /* decrement number of elements by one after dequeuing */
		if((FIFO_Pname->P_ItemBuff_Tail) == (FIFO_Pname->P_ItemBuff_Top))/* if tail reach to top */
		{
			(FIFO_Pname->P_ItemBuff_Tail) = (FIFO_Pname->P_ItemBuff_Base);
		}
	}
	else if( (FIFO_Pname->U32Counter) == ZERO )
	{
		Error = FIFO_empty; /* this will happen if (counter = 0) */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Dequeue (S_U8FIFO_t * U8FIFO_Pname , uint8_t * Copy_P_U8Var )
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer is empty or not before popping*/
	if( (U8FIFO_Pname->U32Counter) > ZERO && (U8FIFO_Pname->P_U8Tail != NULL))
	{
		*(Copy_P_U8Var) = *(U8FIFO_Pname->P_U8Tail); /* put value which in tail in the variable */
		(U8FIFO_Pname->P_U8Tail)++;  /* make tail pointer points to the next item should be dequeue */
		(U8FIFO_Pname->U32Counter)--; /* decrement number of elements by one after dequeuing */
		if((U8FIFO_Pname->P_U8Tail) == ((U8FIFO_Pname->P_U8Base) + (U8FIFO_Pname->U32Length)))/* if tail reach to top */
		{
			(U8FIFO_Pname->P_U8Tail) = (U8FIFO_Pname->P_U8Base);
		}
	}
	else if( (U8FIFO_Pname->U32Counter) <= ZERO )
	{
		Error = FIFO_empty; /* this will happen if (counter = 0) */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Dequeue(S_U16FIFO_t* U16FIFO_Pname, uint16_t* Copy_P_U16Var)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer is empty or not before popping*/
	if( (U16FIFO_Pname->U32Counter) > ZERO && (U16FIFO_Pname->P_U16Tail != NULL))
	{
		*(Copy_P_U16Var) = *(U16FIFO_Pname->P_U16Tail); /* put value which in tail in the variable */
		(U16FIFO_Pname->P_U16Tail)++;  /* make tail pointer points to the next item should be dequeue */
		(U16FIFO_Pname->U32Counter)--; /* decrement number of elements by one after dequeuing */
		if((U16FIFO_Pname->P_U16Tail) == ((U16FIFO_Pname->P_U16Base) + (U16FIFO_Pname->U32Length)))/* if tail reach to top */
		{
			(U16FIFO_Pname->P_U16Tail) = (U16FIFO_Pname->P_U16Base);
		}
	}
	else if( (U16FIFO_Pname->U32Counter) <= ZERO )
	{
		Error = FIFO_empty; /* this will happen if (counter = 0) */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U32_Dequeue(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Var)
{
	FIFO_Error_Status Error = FIFO_no_error;
	/* check if buffer is empty or not before popping*/
	if( (U32FIFO_Pname->U32Counter) > ZERO && (U32FIFO_Pname->P_U32Head != NULL))
	{
		*(Copy_P_U32Var) = *(U32FIFO_Pname->P_U32Tail); /* put value which in tail in the variable */
		(U32FIFO_Pname->P_U32Tail)++;  /* make tail pointer points to the next item should be dequeue */
		(U32FIFO_Pname->U32Counter)--; /* decrement number of elements by one after dequeuing */
		if((U32FIFO_Pname->P_U32Tail) == ((U32FIFO_Pname->P_U32Base) + (U32FIFO_Pname->U32Length)))/* if tail reach to top */
		{
			(U32FIFO_Pname->P_U32Tail) = (U32FIFO_Pname->P_U32Base);
		}
	}
	else if( (U32FIFO_Pname->U32Counter) <= ZERO )
	{
		Error = FIFO_empty; /* this will happen if (counter = 0) */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
/****************************************************************************************************
	@job        -use when you want to know number of element of your initialized LIFO buffer.
				-please make sure you initialize your LIFO buffer, before using this function.
				*************************************************************************************
*****************************************************************************************************
 	@inputs		-argument1 => pointer to your initialized LIFO buffer.
 				-argument2 => pointer to unsigned integer to store number of item in.
				*************************************************************************************
*****************************************************************************************************
	@output		-return indication of error status.
	 	 	 	*************************************************************************************
*****************************************************************************************************/
FIFO_Error_Status FIFO_Item_Count(S_FIFO_t* FIFO_Pname, uint32_t* Copy_P_U32Count)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( FIFO_Pname->P_ItemBuff_Head != NULL )
	{
		*(Copy_P_U32Count) = (FIFO_Pname->U32Counter); /* counter = number of elements of buffer */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Count (S_U8FIFO_t * U8FIFO_Pname , uint32_t * Copy_P_U32Count )
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( U8FIFO_Pname->P_U8Head != NULL )
	{
		*(Copy_P_U32Count) = (U8FIFO_Pname->U32Counter); /* counter = number of elements of buffer */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Count(S_U16FIFO_t* U16FIFO_Pname, uint32_t* Copy_P_U32Count)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( U16FIFO_Pname->P_U16Head != NULL )
	{
		*(Copy_P_U32Count) = (U16FIFO_Pname->U32Counter); /* counter = number of elements of buffer */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U32_Count(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Count)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( U32FIFO_Pname->P_U32Head != NULL )
	{
		*(Copy_P_U32Count) = (U32FIFO_Pname->U32Counter); /* counter = number of elements of buffer */
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}




FIFO_Error_Status FIFO_Item_Print(S_FIFO_t* FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (FIFO_Pname->P_ItemBuff_Base != NULL_POINTER) )
	{
		uint32_t Local_U32Counter = (FIFO_Pname->U32Counter);
		FIFO_ELEMENT_TYPE* Local_P_U32Tail = (FIFO_Pname->P_ItemBuff_Tail);
		printf("items:");
		if(Local_U32Counter == ZERO)
		{
			Error = FIFO_empty;
		}
		while(Local_U32Counter != ZERO)
		{
			printf("%2d ", *(Local_P_U32Tail));
			Local_P_U32Tail++;
			Local_U32Counter--;
			if(Local_P_U32Tail == ((FIFO_Pname->P_ItemBuff_Base) + (FIFO_Pname->U32Length)))
			{
				(Local_P_U32Tail) = (FIFO_Pname->P_ItemBuff_Base);
			}
		}
		printf("\n");
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Print (S_U8FIFO_t * U8FIFO_Pname )
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U8FIFO_Pname->P_U8Base != NULL_POINTER) )
	{
		uint32_t Local_U32Counter = (U8FIFO_Pname->U32Counter);
		uint8_t* Local_P_U8Tail = (U8FIFO_Pname->P_U8Tail);
		printf("items:");
		if(Local_U32Counter == ZERO)
		{
			Error = FIFO_empty;
		}
		while(Local_U32Counter != ZERO)
		{
			printf("%2d ", *(Local_P_U8Tail));
			Local_P_U8Tail++;
			Local_U32Counter--;
			if(Local_P_U8Tail == ((U8FIFO_Pname->P_U8Base) + (U8FIFO_Pname->U32Length)))
			{
				(Local_P_U8Tail) = (U8FIFO_Pname->P_U8Base);
			}
		}
		printf("\n");
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Print(S_U16FIFO_t* U16FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U16FIFO_Pname->P_U16Base != NULL_POINTER) )
	{
		uint32_t Local_U32Counter = (U16FIFO_Pname->U32Counter);
		uint16_t* Local_P_U16Tail = (U16FIFO_Pname->P_U16Tail);
		printf("items:");
		if(Local_U32Counter == ZERO)
		{
			Error = FIFO_empty;
		}
		while(Local_U32Counter != ZERO)
		{
			printf("%2d ", *(Local_P_U16Tail));
			Local_P_U16Tail++;
			Local_U32Counter--;
			if(Local_P_U16Tail == ((U16FIFO_Pname->P_U16Base) + (U16FIFO_Pname->U32Length)))
			{
				(Local_P_U16Tail) = (U16FIFO_Pname->P_U16Base);
			}
		}
		printf("\n");
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}

FIFO_Error_Status FIFO_U32_Print(S_U32FIFO_t* U32FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U32FIFO_Pname->P_U32Base != NULL_POINTER) )
	{
		uint32_t Local_U32Counter = (U32FIFO_Pname->U32Counter);
		uint32_t* Local_P_U32Tail = (U32FIFO_Pname->P_U32Tail);
		printf("items:");
		if(Local_U32Counter == ZERO)
		{
			Error = FIFO_empty;
		}
		while(Local_U32Counter != ZERO)
		{
			printf("%2d ", *(Local_P_U32Tail));
			Local_P_U32Tail++;
			Local_U32Counter--;
			if(Local_P_U32Tail == ((U32FIFO_Pname->P_U32Base) + (U32FIFO_Pname->U32Length)))
			{
				(Local_P_U32Tail) = (U32FIFO_Pname->P_U32Base);
			}
		}
		printf("\n");
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}




FIFO_Error_Status FIFO_Item_Clear(S_FIFO_t* FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (FIFO_Pname->P_ItemBuff_Base != NULL_POINTER) )
	{
		FIFO_Pname->P_ItemBuff_Tail  = FIFO_Pname->P_ItemBuff_Base;
		FIFO_Pname->P_ItemBuff_Head  = FIFO_Pname->P_ItemBuff_Base;
		FIFO_Pname->U32Counter = ZERO;
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U8_Clear(S_U8FIFO_t* U8FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U8FIFO_Pname->P_U8Base != NULL_POINTER) )
	{
		U8FIFO_Pname->P_U8Tail  = U8FIFO_Pname->P_U8Base;
		U8FIFO_Pname->P_U8Head  = U8FIFO_Pname->P_U8Base;
		U8FIFO_Pname->U32Counter = ZERO;
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U16_Clear(S_U16FIFO_t* U16FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U16FIFO_Pname->P_U16Base != NULL_POINTER) )
	{
		U16FIFO_Pname->P_U16Tail  = U16FIFO_Pname->P_U16Base;
		U16FIFO_Pname->P_U16Head  = U16FIFO_Pname->P_U16Base;
		U16FIFO_Pname->U32Counter = ZERO;
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}
FIFO_Error_Status FIFO_U32_Clear(S_U32FIFO_t* U32FIFO_Pname)
{
	FIFO_Error_Status Error = FIFO_no_error;
	if( (U32FIFO_Pname->P_U32Base != NULL_POINTER) )
	{
		U32FIFO_Pname->P_U32Tail  = U32FIFO_Pname->P_U32Base;
		U32FIFO_Pname->P_U32Head  = U32FIFO_Pname->P_U32Base;
		U32FIFO_Pname->U32Counter = ZERO;
	}
	else
	{
		Error = FIFO_null;
	}
	return Error;
}


void FIFO_Item_Free(S_FIFO_t* FIFO_Pname)
{
	FIFO_Pname->P_ItemBuff_Base = NULL;
	FIFO_Pname->P_ItemBuff_Head = NULL;
	FIFO_Pname->P_ItemBuff_Tail = NULL;
}
void FIFO_U32_Free(S_U32FIFO_t* U32FIFO_Pname)
{
	U32FIFO_Pname->P_U32Base = NULL;
	U32FIFO_Pname->P_U32Head = NULL;
	U32FIFO_Pname->P_U32Tail = NULL;
}


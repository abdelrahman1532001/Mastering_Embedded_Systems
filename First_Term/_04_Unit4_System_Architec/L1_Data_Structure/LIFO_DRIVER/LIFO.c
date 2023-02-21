/*
 	 @author Eng.Abdelrahman Reda
 	 @file	 LIFO.c
 	 @date   2/18/2023
 	 @course Learn-In-Depth Online Diploma
 */
#include "stdio.h"
#include "LIFO.h"

LIFO_Error_Status LIFO_Add_U32Item(LIFO_t* LIFO_Pname, unsigned int U32Item)
{
	LIFO_Error_Status Error = LIFO_Noerror;
	/* check if buffer full or not before adding any item */
	if( (LIFO_Pname->U32Counter) < (LIFO_Pname->U32Length) && (LIFO_Pname->P_U32Head != NULL) )
	{
		*(LIFO_Pname->P_U32Head) = U32Item; /* add item in buffer */
		(LIFO_Pname->P_U32Head)++; /* make head point to next item to be ready for following add */
		(LIFO_Pname->U32Counter)++;  /* update counter after adding */
	}
	else if( (LIFO_Pname->U32Counter) >= (LIFO_Pname->U32Length) )
	{
		Error = LIFO_Full; /* this will happen if (counter = length) */
	}
	else
	{
		Error = LIFO_Notfound; /* this will happen if not found */
	}
	return Error;
}
LIFO_Error_Status LIFO_init(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Buffer, unsigned int Copy_U32Buff_Length)
{
	LIFO_Error_Status Error = LIFO_Noerror;
	if( Copy_P_U32Buffer != NULL_POINTER )
	{
		LIFO_Pname->P_U32Base = Copy_P_U32Buffer;
		LIFO_Pname->P_U32Head = Copy_P_U32Buffer;
		LIFO_Pname->U32Length = Copy_U32Buff_Length;
	}
	else
	{
		Error = LIFO_Initerror;
	}
	return Error;
}
LIFO_Error_Status LIFO_Get_U32Item(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Var)
{
	LIFO_Error_Status Error = LIFO_Noerror;
	/* check if buffer is empty or not before popping*/
	if( (LIFO_Pname->U32Counter) > ZERO && (LIFO_Pname->P_U32Head != NULL))
	{
		(LIFO_Pname->P_U32Head)--;  /* make head pointer points to the next item should be popped */
		*(Copy_P_U32Var) = *(LIFO_Pname->P_U32Head); /* this make received pointer points to top value */
		(LIFO_Pname->U32Counter)--; /* decrement number of elements by one after popping */
	}
	else if( (LIFO_Pname->U32Counter) <= ZERO )
	{
		Error = LIFO_Empty; /* this will happen if (counter = 0) */
	}
	else
	{
		Error = LIFO_Notfound;
	}
	return Error;
}

LIFO_Error_Status LIFO_Count_U32Items(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Count)
{
	LIFO_Error_Status Error = LIFO_Noerror;
	if( LIFO_Pname->P_U32Head != NULL )
	{
		*(Copy_P_U32Count) = (LIFO_Pname->U32Counter); /* counter = number of elements of buffer */
	}
	else
	{
		Error = LIFO_Notfound;
	}
	return Error;
}

void LIFO_Free(LIFO_t* LIFO_Pname)
{
	LIFO_Pname->P_U32Base = NULL;
	LIFO_Pname->P_U32Head = NULL;

}


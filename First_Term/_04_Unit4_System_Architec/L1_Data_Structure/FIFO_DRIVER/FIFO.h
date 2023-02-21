/*
	@author	Eng.Abdelrahman Reda

	@file	LIFO.h

	@date   2/18/2023

	@course Learn-In-Depth Online Diploma


	@about			FIFO_Driver @version 0.0.0

	@description	this FIFO driver support four FIFO buffers, three of them are uint8_t, uint16_t, and uint32_t, and you can use this three
					buffers at same time in one code as each buffer has its functions. and the fourth buffer is general one you can set its
					data as you want, just change the FIFO_ELEMENT_TYPE to your data as,
					#define FIFO_ELEMENT_TYPE uint16_t, In this case we set it as uint16_t, but feel comfortable to change to your data type

	@warning!!!	   	don't try to change any thing in this header file, except FIFO_ELEMENT_TYPE as we mention above.

*/

#ifndef FIFO_H_ /* file guard */
#define FIFO_H_ /* file guard */

#include "stdint.h"
#define NULL_POINTER ((void*)0)
#define ZERO 0

/* use S_FIFO_t data type when you you want to use the general FIFO buffer */
/* don't forget when you initialize buffer in your code, it should the same data type of FIFO_ELEMENT_TYPE */
#define FIFO_ELEMENT_TYPE	uint16_t
typedef struct{
	 uint32_t  U32Length ;
	 uint32_t  U32Counter;
	 FIFO_ELEMENT_TYPE* P_ItemBuff_Top  ;
	 FIFO_ELEMENT_TYPE* P_ItemBuff_Base ;
	 FIFO_ELEMENT_TYPE* P_ItemBuff_Head ;
	 FIFO_ELEMENT_TYPE* P_ItemBuff_Tail ;
}S_FIFO_t;
/* use S_U32_FIFO_t data type when you you want to use the uint32_t FIFO buffer */
typedef struct{
	 uint32_t  U32Length ;
	 uint32_t  U32Counter;
	 uint32_t* P_U32Base ;
	 uint32_t* P_U32Head ;
	 uint32_t* P_U32Tail ;
}S_U32FIFO_t;
/* use S_U16_FIFO_t data type when you you want to use the uint16_t FIFO buffer */
typedef struct{
	uint32_t  U32Length ;
	uint32_t  U32Counter;
	uint16_t* P_U16Base ;
	uint16_t* P_U16Head ;
	uint16_t* P_U16Tail ;
}S_U16FIFO_t;
/* use S_U8_FIFO_t data type when you you want to use the uint8_t FIFO buffer */
typedef struct{
	uint32_t U32Length ;
	uint32_t U32Counter;
	uint8_t* P_U8Base  ;
	uint8_t* P_U8Head  ;
	uint8_t* P_U8Tail  ;
}S_U8FIFO_t;
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_init_error,
	FIFO_null
}FIFO_Error_Status;
/******************************/
/* Application Interface(API) */
/******************************/
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
FIFO_Error_Status FIFO_Item_Init(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE* Copy_P_Buffer, uint32_t Copy_Buff_Length);
FIFO_Error_Status FIFO_U32_Init(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Buffer, uint32_t Copy_U32Buff_Length);
FIFO_Error_Status FIFO_U16_Init(S_U16FIFO_t* U16FIFO_Pname, uint16_t* Copy_P_U16Buffer, uint32_t Copy_U16Buff_Length);
FIFO_Error_Status FIFO_U8_Init (S_U8FIFO_t * U8FIFO_Pname , uint8_t * Copy_P_U8Buffer , uint32_t Copy_U8Buff_Length );


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
FIFO_Error_Status FIFO_Item_Enqueue(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE Item);
FIFO_Error_Status FIFO_U32_Enqueue(S_U32FIFO_t* U32FIFO_Pname, uint32_t U32Item);
FIFO_Error_Status FIFO_U16_Enqueue(S_U16FIFO_t* U16FIFO_Pname, uint16_t U16Item);
FIFO_Error_Status FIFO_U8_Enqueue (S_U8FIFO_t * U8FIFO_Pname , uint8_t  U8Item );


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
FIFO_Error_Status FIFO_Item_Dequeue(S_FIFO_t* FIFO_Pname, FIFO_ELEMENT_TYPE* Copy_P_Var);
FIFO_Error_Status FIFO_U32_Dequeue(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Var);
FIFO_Error_Status FIFO_U16_Dequeue(S_U16FIFO_t* U16FIFO_Pname, uint16_t* Copy_P_U16Var);
FIFO_Error_Status FIFO_U8_Dequeue (S_U8FIFO_t * U8FIFO_Pname , uint8_t * Copy_P_U8Var );


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
FIFO_Error_Status FIFO_Item_Count(S_FIFO_t* FIFO_Pname, uint32_t* Copy_P_U32Count);
FIFO_Error_Status FIFO_U32_Count(S_U32FIFO_t* U32FIFO_Pname, uint32_t* Copy_P_U32Count);
FIFO_Error_Status FIFO_U16_Count(S_U16FIFO_t* U16FIFO_Pname, uint32_t* Copy_P_U32Count);
FIFO_Error_Status FIFO_U8_Count (S_U8FIFO_t * U8FIFO_Pname , uint32_t* Copy_P_U32Count);


/****************************************************************************************************
	@job        -use when you want to destroy your initialized LIFO buffer.
				*************************************************************************************
*****************************************************************************************************
 	@inputs		-argument1 => pointer to your initialized LIFO buffer you want to delete.
				*************************************************************************************
*****************************************************************************************************
	@output		-No return.
	 	 	 	*************************************************************************************
*****************************************************************************************************/
void FIFO_Item_Free(S_FIFO_t* FIFO_Pname);
void FIFO_U32_Free(S_U32FIFO_t* U32FIFO_Pname);
void FIFO_U16_Free(S_U16FIFO_t* U16FIFO_Pname);
void FIFO_U8_Free (S_U8FIFO_t * U8FIFO_Pname );


FIFO_Error_Status FIFO_Item_Print(S_FIFO_t* FIFO_Pname);
FIFO_Error_Status FIFO_U32_Print(S_U32FIFO_t* U32FIFO_Pname);
FIFO_Error_Status FIFO_U16_Print(S_U16FIFO_t* U16FIFO_Pname);
FIFO_Error_Status FIFO_U8_Print (S_U8FIFO_t * U8FIFO_Pname );

FIFO_Error_Status FIFO_Item_Clear(S_FIFO_t* FIFO_Pname);
FIFO_Error_Status FIFO_U32_Clear(S_U32FIFO_t* U32FIFO_Pname);
FIFO_Error_Status FIFO_U16_Clear(S_U16FIFO_t* U16FIFO_Pname);
FIFO_Error_Status FIFO_U8_Clear(S_U8FIFO_t* U8FIFO_Pname)   ;




#endif /* FIFO_H_ */

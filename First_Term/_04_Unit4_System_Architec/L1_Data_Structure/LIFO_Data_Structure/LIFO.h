/*
 	 @author Eng.Abdelrahman Reda
 	 @file	 LIFO.h
 	 @date   2/18/2023
 	 @course Learn-In-Depth Online Diploma
 */

#ifndef LIFO_H_ /* File Guard */
#define LIFO_H_

#define NULL_POINTER ((void*)0)
#define ZERO 0

/* Type definition */

/*
	@new data type of LIFO_t
	@only support unsigned integer data type
 */
typedef struct{
	 unsigned int  U32Length;
	 unsigned int  U32Counter ;
	 unsigned int* P_U32Base;
	 unsigned int* P_U32Head;
}LIFO_t;

typedef enum{
	LIFO_Noerror,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Initerror,
	LIFO_Notfound
}LIFO_Error_Status;

/* Application Interface(API) */


LIFO_Error_Status LIFO_init(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Buffer, unsigned int Copy_U32Buff_Length);
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


LIFO_Error_Status LIFO_Add_U32Item(LIFO_t* LIFO_Pname, unsigned int U32Item);
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


LIFO_Error_Status LIFO_Get_U32Item(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Var);
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


LIFO_Error_Status LIFO_Count_U32Items(LIFO_t* LIFO_Pname, unsigned int* Copy_P_U32Count);
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

void LIFO_Free(LIFO_t* LIFO_Pname);
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

#endif /* LIFO_H_ */

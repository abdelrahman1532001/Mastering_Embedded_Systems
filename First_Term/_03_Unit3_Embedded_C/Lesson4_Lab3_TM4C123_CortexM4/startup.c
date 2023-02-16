/*
	@author	Eng.abdelrahman reda
	@file    Startup.c
	@date    2/16/2023
	@target  TM4C123 ARM-CORTEX-M
	@note	In this code we get _SP(top stack pointer) and vectors array with two methods:
				#method_1 #make (#define RUN_CODE 1)#
					- get _SP(top stack pointer) with the help of linker locator(.). 
					- implement vector array as array of int 
				#method_1 #make (#define RUN_CODE 2)#
					- get _SP without using linker locator. 
					- implement vector array as array of pointer to function 
*/
/*
	@Options 
		(1) 1
		(2) 2
*/
#define RUN_CODE 2
/*
	@Memory_Map used in this linker
	===============================
	
	Offset		Vector
	
	~~~~~	----------------------
			
			
			
			
			
	0x0018	----------------------
			Bus Fault	
	0x0014	----------------------
			Memory Management	
	0x0010	----------------------
			Hard Fault	
	0x000C	----------------------
			NMI	
	0x0008	----------------------
			Reset	
	0x0004	----------------------
			SP Value
	0x0000	----------------------

*/
#if RUN_CODE==1
/****************************************************************************************
*****************************************************************************************
***************************|||||||||||| FIRST CODE |||||||||||||*************************
*****************************************************************************************
*****************************************************************************************/
extern unsigned long _SP;            /* from linker script */
extern unsigned long _E_text;		 /* from linker script */
extern unsigned long _S_data;		 /* from linker script */
extern unsigned long _E_data;        /* from linker script */
extern unsigned long _S_bss;         /* from linker script */
extern unsigned long _E_bss;         /* from linker script */

void _reset(void)
{
	unsigned long Data_Size = (unsigned char*)(&_E_data) - (unsigned char*)(&_S_data); /* get the size of data by byte */
	unsigned char* P_SCR = (unsigned char*)(&_E_text); /* cast pointer to points to only 1 byte */
	unsigned char* P_DST = (unsigned char*)(&_S_data); /* cast pointer to points to only 1 byte */
	unsigned long i;
	for(i=0; i<Data_Size; i++) /* we will copy data byte by byte */
	{
		*((unsigned char*)P_DST++) = *((unsigned char*)P_SCR++); /* copy data from FLASH to SRAM */
	}
	unsigned long Bss_Size = (unsigned char*)(&_E_bss) - (unsigned char*)(&_S_bss);
	P_DST = (unsigned char*)(&_S_bss);
	for(i=0; i<Bss_Size; i++)
	{
		*((unsigned char*)P_DST++) = (unsigned char)0; /* all uninit global data will equal 0 */
	}
	main(); /* call main after prepare all inits */
} 

void _Default_Handler(void) /* it's not our scope right now so put it _reset() */ 
{
	_reset(); 
}

/* weak  attribute ---> allow you to redifinition function */
/* alias attribute ---> allow you to make many symbols refer to one symbol untile you use it */
void _NMI_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _HardFault_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _MemMangement_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _BusFault_Handler(void) __attribute__((weak, alias("_Default_Handler")));;

/* section attribute ---> make linker put symbol under specific name */
unsigned long _isr_vectore[] __attribute__((section(".vector"))) = 
{
	(unsigned long)(&_SP),
	(unsigned long)(&_reset),
	(unsigned long)(&_NMI_Handler),
	(unsigned long)(&_HardFault_Handler),
	(unsigned long)(&_MemMangement_Handler),
	(unsigned long)(&_BusFault_Handler)
};
#endif





#if RUN_CODE==2
/****************************************************************************************
*****************************************************************************************
***************************|||||||||||| SECOND CODE |||||||||||||************************
*****************************************************************************************
*****************************************************************************************/         
extern unsigned long _E_text;		 /* from linker script */
extern unsigned long _S_data;		 /* from linker script */
extern unsigned long _E_data;        /* from linker script */
extern unsigned long _S_bss;         /* from linker script */
extern unsigned long _E_bss;         /* from linker script */

#define _STACK_SIZE 256			 	 		/* make stack size 256*4 Byte */
static unsigned long _STACK[_STACK_SIZE];	/* We will use this bss section to get _SP */
void _reset(void)
{
	unsigned long Data_Size = (unsigned char*)(&_E_data) - (unsigned char*)(&_S_data); /* get the size of data by byte */
	unsigned char* P_SCR = (unsigned char*)(&_E_text); /* cast pointer to points to only 1 byte */
	unsigned char* P_DST = (unsigned char*)(&_S_data); /* cast pointer to points to only 1 byte */
	unsigned long i;
	for(i=0; i<Data_Size; i++) /* we will copy data byte by byte */
	{
		*((unsigned char*)P_DST++) = *((unsigned char*)P_SCR++); /* copy data from FLASH to SRAM */
	}
	unsigned long Bss_Size = (unsigned char*)(&_E_bss) - (unsigned char*)(&_S_bss);
	P_DST = (unsigned char*)(&_S_bss);
	for(i=0; i<Bss_Size; i++)
	{
		*((unsigned char*)P_DST++) = (unsigned char)0; /* all uninit global data will equal 0 */
	}
	main(); /* call main after prepare all inits */
} 

void _Default_Handler(void) /* it's not our scope right now so put it _reset() */ 
{
	_reset(); 
}

/* weak  attribute ---> allow you to redifinition function */
/* alias attribute ---> allow you to make many symbols refer to one symbol untile you use it */
void _NMI_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _HardFault_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _MemMangement_Handler(void) __attribute__((weak, alias("_Default_Handler")));;
void _BusFault_Handler(void) __attribute__((weak, alias("_Default_Handler")));;

/* section attribute ---> make linker put symbol under specific name */
void(*const P_ISR_Vectors[])(void) __attribute__((section(".vector"))) = /* array of const pointer to function */
{
	(void(*)(void))(&_STACK[256]), /* pointer of top of stack _SP */
	(void(*)(void))(&_reset),	/* you can delete cast from here as it's already pointer to function */ 
	(void(*)(void))(&_NMI_Handler),	/* you can delete cast from here as it's already pointer to function */
	(void(*)(void))(&_HardFault_Handler),	/* you can delete cast from here as it's already pointer to function */
	(void(*)(void))(&_MemMangement_Handler),	/* you can delete cast from here as it's already pointer to function */
	(void(*)(void))(&_BusFault_Handler)	/* you can delete cast from here as it's already pointer to function */
};
#endif

/* 
	@author	Eng.Abdelrahman Reda
	@file    startup.c
	@date	2/15/2023
	@MCU     ARM32F103C6(CORTEX-M3)
*/

#include "stdint.h"
#define	STACK_TOP_POINTER 0x20001000

/* 
	//This is bad way as it consume flash with unused vectores, so we will use (weak && alias). See down
extern int main(void); //to pass to linker where will be solved 
void _Reset(void)
{
	main();
}
void NMI_Handler(void)
{
	_Reset();
}
void HardFault_Handler(void)
{
	_Reset();
}
void MemManage_Handler(void)
{
	_Reset();
}
void BusFault_Handler(void)
{
	_Reset();
}
void UsageFault_Handler(void)
{
	_Reset();
}*/

/*
	@weak	this make redifinition allowable
	@alias	this make all vecoters points to one specified vectore to free flash unitle user use the wanted vectore
*/
extern int main(void); // to pass to linker where will be solved 
extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
extern unsigned int _STACK_POINTER;

void _Reset(void)
{
	unsigned int i;
	unsigned int Data_Size = (unsigned char *) &_E_DATA - (unsigned char *) &_S_DATA;
	unsigned char *P_scr = (unsigned char *) &_E_TEXT;
	unsigned char *P_dst = (unsigned char *) &_S_DATA;
	for(i=0; i<Data_Size; i++)
	{
		*((unsigned char *)P_dst++) = *((unsigned char *)P_scr++);
	}
	unsigned int Bss_Size = (unsigned char *) &_E_BSS - (unsigned char *) &_S_BSS;
	P_dst = (unsigned char *) &_S_BSS;
	for(i=0; i<Bss_Size; i++)
	{
		*((unsigned char *)P_dst++) = (unsigned char)0;
	}
	main();
}
void Default_Handler(void)
{
	_Reset();
}
void NMI_Handler(void)			__attribute__((weak, alias("Default_Handler")));;
void HardFault_Handler(void) 	__attribute__((weak, alias("Default_Handler")));;
void MemManage_Handler(void) 	__attribute__((weak, alias("Default_Handler")));;
void BusFault_Handler(void) 	__attribute__((weak, alias("Default_Handler")));;
void UsageFault_Handler(void) 	__attribute__((weak, alias("Default_Handler")));;

uint32_t* isr_vectores[] __attribute__((section(".vectors")))=
{
	(uint32_t *) &_STACK_POINTER,
	(uint32_t *) &_Reset,
	(uint32_t *) &NMI_Handler,
	(uint32_t *) &HardFault_Handler,
	(uint32_t *) &MemManage_Handler,
	(uint32_t *) &BusFault_Handler,
	(uint32_t *) &UsageFault_Handler,
}; 
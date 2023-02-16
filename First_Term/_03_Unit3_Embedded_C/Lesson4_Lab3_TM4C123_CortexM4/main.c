/*
	@author	abdelrahman reda
	@Date 	2/16/2023
	@file	main.c
	@target  TM4C123 AMR-CORTEX-M4
	@lab		Write a Baremetal SW to toggle PF3
			which is connected with green LED
*/

#include "stdint.h"

#define SYSCTL_RCGC2_R	    (*(volatile unsigned long*)0x400FE108)
#define GPIO_PORTF_DIR_R	(*(volatile unsigned long*)0x40025400)
#define GPIO_PORTF_DEN_R	(*(volatile unsigned long*)0x4002551C)
#define GPIO_PORTF_DATA_R	(*(volatile unsigned long*)0x400253FC)


int main(void)
{
	volatile unsigned long i;
	SYSCTL_RCGC2_R = 0x20 ;
	for(i=0; i<2000; i++);
	GPIO_PORTF_DIR_R |= ( 1 << 3 );
	GPIO_PORTF_DEN_R |= ( 1 << 3 );
	while(1)
	{
		GPIO_PORTF_DATA_R |= ( 1 << 3 );
		for(i=0; i<200000; i++);
		GPIO_PORTF_DATA_R &= ~( 1 << 3 );
		for(i=0; i<200000; i++);		

	}
	return 0;
}
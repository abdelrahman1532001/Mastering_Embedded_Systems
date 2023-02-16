/*
	@author	Eng.abdelrahman reda
	@file   ld_script.ld
	@date   2/16/2023
	@target TM4C123 ARM-CORTEX-M
*/

MEMORY
{
	FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : 
	{
		*(.vector*)
		*(.text*)
		*(.rodata*)
		. = ALIGN(4) ;
		_E_text = . ;
	} > FLASH
	.data : 
	{
		_S_data = . ;
		*(.data*)
		. = ALIGN(4) ;
		_E_data = . ;
	} > SRAM AT> FLASH
	.bss : 
	{
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4) ;
		_E_bss = . ;
		_SP = . + 1024 ; /* 1K */
	} > SRAM
}
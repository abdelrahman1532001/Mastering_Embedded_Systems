/* 
	@owner	Eng.Abdelrahman Reda
	@file	linker_script.ld
	@target arm cortex-m3
	@course learn-in-depth online diploma
	@date	2/15/2023 "D/M/Y"
*/

MEMORY
{
	FLASH(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}
SECTIONS
{
	.text :
	{
		*(.vectors*)	/* take any (.vectors....) section in any relocatable file */
		*(.text*)		/* take any (.text.......) section in any relocatable file */
		*(.rodata*)
		. = ALIGN(0x4) ;
		_E_TEXT = . ;
	} > FLASH
	.data : 
	{
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(0x4) ;
		_E_DATA = . ;
	} > SRAM AT> FLASH
	.bss :
	{
		_S_BSS = . ;
		*(.bss*)		/* take any (.bss........) section in any relocatable file */
		. = ALIGN(0x4) ;
		_E_BSS = . ;
	} > SRAM
	_STACK_POINTER = . + 1024 ;
}

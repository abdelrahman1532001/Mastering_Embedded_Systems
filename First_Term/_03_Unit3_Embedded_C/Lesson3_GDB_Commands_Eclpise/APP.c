// give alias names to some data types
typedef unsigned long          uint32_t ;
typedef volatile unsigned long vuint32_t;
typedef unsigned char          uchar8_t ;

#include "UART.h" //include header file of uart
uchar8_t String_Tx1[200] = "learn-in-depth: abdelrahman <from Tx1>"; //in .data section
uchar8_t const String_Tx2[200] = "learn-in-depth: abdelrahman <from Tx2>"; //in .rodata section

int main()
{
	UART0_voidSend_String(String_Tx1); //send string to uart0
	for(;;);
	return 0;
}
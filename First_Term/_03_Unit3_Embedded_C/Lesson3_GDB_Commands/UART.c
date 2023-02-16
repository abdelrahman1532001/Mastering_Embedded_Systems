typedef unsigned long          uint32_t ;
typedef volatile unsigned long vuint32_t;
typedef unsigned char          uchar8_t ;

#define UART0 *(vuint32_t *const)(0x101f1000)

#include "UART.h"

/**************************************************
* @input       : pointer to const string          *
***************************************************
* @output      : nothing                          *
***************************************************
* @discription : take string and send it to uart0 *
*                in ARM VersatilePB               *
**************************************************/
void UART0_voidSend_String( uchar8_t const *Pstring_Tx )
{
	while( *Pstring_Tx != '\0')
	{ //loop untile end of string
		UART0 = (uint32_t)(*Pstring_Tx);
		Pstring_Tx++;
	}//end while loop 
}




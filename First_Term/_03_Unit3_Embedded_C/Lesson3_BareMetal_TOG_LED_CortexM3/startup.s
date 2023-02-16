/* 
	@owner	Eng.Abdelrahman Reda
	@file	startup.s
	@target arm cortex-m3
	@course learn-in-depth online diploma
	@date	2/10/2023 "D/M/Y"
*/
/* 
	notes:
	======
	- SRAM starts @0x20,000,000 
	- When cpu boots, PC(Program Counter) points @0x8,000,000
	  ,and it's supposed to read SP(Stack Pointer) @0x8,000,000
	- Tnen PC points @0x8,000,004 , and it's supposed to read 
	  @Reset_Handler
	- Then PC points @0x8,000,008 , and it's supposed to read
	  @NMI_Handler 
	- Again & Again untile handeling all vector table
	- (.word) means 4Bytes(32Bits)
*/ 
.section .vectors       /* List some sections under name .vectors */

.word 0x20001000       	/* stack top address */
.word _reset            /* 1  reser          */
.word vector_handler	/* 2  NMI            */
.word vector_handler	/* 3  Hard Fault     */
.word vector_handler	/* 4  MM Fault       */
.word vector_handler	/* 5  Bus Fault      */
.word vector_handler	/* 6  Usage Fault    */
.word vector_handler	/* 7  RESERVED       */
.word vector_handler	/* 8  RESERVED       */
.word vector_handler	/* 9  RESERVED       */
.word vector_handler	/* 10 RESERVED       */
.word vector_handler	/* 11 SV call        */
.word vector_handler	/* 12 Debug reserved */
.word vector_handler	/* 13 RESERVED       */
.word vector_handler	/* 14 PendSV         */
.word vector_handler	/* 15 SysTick        */ 
.word vector_handler	/* 16 IRQ0           */
.word vector_handler	/* 17 IRQ1     		 */
.word vector_handler	/* 18 IRQ2			 */
.word vector_handler	/* 19 .... 			 */ 	

.section .text	/* List some section under .text */

_reset:
	bl main		/* branch to main */
	b  .        /* branch to ur location *//* infinite loop *//* this happens when main function exits */
.thumb_func
vector_handler:
	bl main     /* branch to main for now :( */
	
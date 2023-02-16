
********************************
**@author**: Abdelrahman
**@target**: ARM versatilePB
**@date**  : 2/6/2023
**@name**  : Lab1
*********************************

**_Discription_**
  Create a baremetal software to send a "Learn-in-deapth:<your_name>" using <UART>

********************************
**_You will learn in this lab_**
********************************
  startup 
  linker
  location counter
  linker script symbols
  make file
  GDB commands
  binary utilities: "objdump, strip, readelf, addr2line,size" 
    
*******************************************************************************************


***************************************** startup *******************************************************

*********************
**. assemply code .**
*********************
****************************************************
@@ author: abdelrahman <learn-in-depth deploma>
.globl reset 
reset: 
		ldr sp, =0x00011000
		bl main
stop:	b  //stop
****************************************************

********************
**. explaination .**
********************
--------------------------------------
@@           
***. to make comment in assemply .***
--------------------------------------
---------------------------------------------------------------
reset:       
***. make symbole called "reset" .***
***. You cann call it any name but reset is a common name .***
---------------------------------------------------------------
----------------------------
ldr          
***. load from register .***
----------------------------
----------------------
bl            
***. branch label .***
----------------------
----------------------------------------------------------------------------------
bl main      
***. branch to main symbole .***
***. this why we should call the main fuction as main .***
***. you can the name of "main", but in this case change the "main" in c code .***
----------------------------------------------------------------------------------
-----------------------------------------------------------
stop: b stop 
***. this is a finite loop .*** ***. if exit from main .***
-----------------------------------------------------------
--------------------------------------------------------------
.globl reset 
***. make reset symbol global to can be seen by all files .***
--------------------------------------------------------------
*************************************************************************************
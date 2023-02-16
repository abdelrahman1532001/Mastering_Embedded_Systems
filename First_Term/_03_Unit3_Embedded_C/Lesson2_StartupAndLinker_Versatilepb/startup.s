@@ author: abdelrahman <learn-in-depth deploma>
.globl reset 
reset: 
		ldr sp, =stack_top
		bl main
stop:	b  stop

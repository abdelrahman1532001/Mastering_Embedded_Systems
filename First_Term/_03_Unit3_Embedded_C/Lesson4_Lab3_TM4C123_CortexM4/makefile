###################################################################################
#@copyright abdelrahman <learn-in-depth-deploma>
#makefile for arm
###################################################################################
###################################################################################
PROJECT_NAME=TM4C123_CORTEX_M4
CC=arm-none-eabi
CFLAGS=-gdwarf-2 -g -mcpu=cortex-m4 -mthumb
INCS=-I .
LIB=
###################################################################################
###################################################################################
SRC=$(wildcard *.c)
As=$(wildcard *.s)
OBJ=$(SRC:.c=.o) $(As:.s=.o)
LINKSCR=$(wildcard *.ld)
###################################################################################
###################################################################################
all: $(PROJECT_NAME).bin
	@echo "==========Debug Done=========="
%.o: %.s
	$(CC)-as.exe $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)-ld.exe -T $(LIB) $(LINKSCR) $(OBJ) -o $(PROJECT_NAME).elf
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)-objcopy.exe -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin
rma:
	rm -rf *.o *.elf *.bin *.axf *.txt
	@echo "==========all cleaned=========="
rm:
	rm *.bin *.elf *.axf
%.txt: %.o
	$(CC)-nm.exe $< >> $(<:.o=_symbol.txt) 
%.txt: %.elf
	$(CC)-nm.exe $< >> $(<:.elf=_symbol.txt) 
s: $(OBJ:.o=.txt) $(PROJECT_NAME).txt
	@echo "==============symbols created============="
rms: 
	rm *.txt
	@echo "================all .txt removed================"
####################################################################################
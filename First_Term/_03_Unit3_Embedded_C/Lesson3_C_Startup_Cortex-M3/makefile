###################################################################################
#@copyright abdelrahman <learn-in-depth-deploma>
#makefile for arm "cortex-m3"
###################################################################################
###################################################################################
PROJECT_NAME=Learn-In-Depth-CortexM3
CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m3 -gdwarf-2 -mthumb
INCS=-I .
LIB=
###################################################################################
###################################################################################
SRC=$(wildcard *.c)
As=$(wildcard *.s)
OBJ=$(SRC:.c=.o) $(As:.s=.o)
LDSCRIPT=$(wildcard *.ld)
###################################################################################
###################################################################################
all: $(PROJECT_NAME).bin
	@echo "==========Debug Done=========="
%.o: %.s
	$(CC)-as.exe $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)-ld.exe -T $(LIB) $(LDSCRIPT) $(OBJ) -o $(PROJECT_NAME).elf
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)-objcopy.exe -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin
clean-all:
	rm -rf *.o *.elf *.bin
	@echo "==========all cleaned=========="
clean:
	rm *.bin *.elf
####################################################################################
###################################################################################
#@copyright abdelrahman <learn-in-depth-deploma>
#makefile for arm
###################################################################################
###################################################################################
PROJECT_NAME=Learn-In-Depth
CC=arm-none-eabi
CFLAGS=-g -mcpu=arm926ej-s
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
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)-objcopy.exe -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin
clean-all:
	rm -rf *.o *.elf *.bin
	@echo "==========all cleaned=========="
clean:
	rm *.bin *.elf
####################################################################################
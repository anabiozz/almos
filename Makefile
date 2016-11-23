P=almos
BOOT=vidar/
program_C_SRCS := $(wildcard *.c)
program_C_OBJS := ${program_C_SRCS:.c=.o}
OBJECTS=kasm.o kc.o screen.o
CFLAGS = -m32 -c -I include/
LDFLAGS= -m elf_i386 -T link.ld
CC=gcc
LD=ld
TOP_DIR=$(pwd)
NASM=nasm

kernel.bin: kasm.o kc.o screen.o system.o keyboard.o string.o
	$(LD) $(LDFLAGS) kasm.o kc.o screen.o system.o \
	keyboard.o string.o -o $(BOOT)/boot/kernel.bin

kasm.o: kernel/kernel.asm
	$(NASM) -f elf32 kernel/kernel.asm -o kasm.o

kc.o: kernel/kernel.c
	$(CC) $(CFLAGS) kernel/kernel.c -o kc.o

string.o: kernel/string.c include/string.h
	$(CC) $(CFLAGS) kernel/string.c -o string.o

keyboard.o: kernel/keyboard.c include/keyboard.h
	$(CC) $(CFLAGS) kernel/keyboard.c -o keyboard.o

screen.o: kernel/screen.c include/screen.h
	$(CC) $(CFLAGS) kernel/screen.c -o screen.o

system.o: kernel/system.c include/system.h
	$(CC) $(CFLAGS) kernel/system.c -o system.o

clear:
	rm *.o
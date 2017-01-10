KERNEL_DIR=kernel
OBJ_DIR=obj
CLIB_DIR=libc

KERNEL_SOURCES=$(shell find $(KERNEL_DIR) -name '*.c')
OBJECTS=$(patsubst $(KERNEL_DIR)/%.c, $(OBJ_DIR)/%.o, $(KERNEL_SOURCES))

SOURCES_ASM=$(shell find $(KERNEL_DIR) -name '*.asm')
OBJECTS_ASM=$(patsubst $(KERNEL_DIR)/%.asm, $(OBJ_DIR)/%.o, $(SOURCES_ASM))

SOURCES_CLIB=$(shell find $(CLIB_DIR) -name '*.c')
OBJECTS_CLIB=$(patsubst $(CLIB_DIR)/%.c, $(OBJ_DIR)/libc/%.o, $(SOURCES_CLIB))

OBJ += \
	$(OBJECTS) $(OBJECTS_ASM) $(OBJECTS_CLIB)

CC=gcc
LD=ld
NASM=nasm

CFLAGS = -c -g -m32 -std=c99 -nostdlib -fno-builtin \
	-fno-exceptions -fno-leading-underscore -I include/ -I libc/include/
LDFLAGS= -m elf_i386 -T link.ld

EMULATOR=$(HOME)/qemu/build/x86_64-softmmu/qemu-system-x86_64
EMULATOR_FLAGS=-kernel
OUTPUT=vidar/boot/kernel.bin

run: kernel.bin
	$(EMULATOR) $(EMULATOR_FLAGS) $(OUTPUT)

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(OUTPUT)

$(OBJ_DIR)/%.o: $(KERNEL_DIR)/%.asm
	$(NASM) -f elf32 -o $@ $<

$(OBJ_DIR)/%.o: $(KERNEL_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/libc/%.o: $(CLIB_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

push:
	@if [ "x$(MSG)" = 'x' ] ; then \
	echo "Usage: MSG='whatever.' make push"; fi
	@test "x$(MSG)" != 'x'
	git commit -a -m "$(MSG)"
	git push origin master

pull:
	git pull origin master

clear:
	rm -rf $(OBJ_DIR)/*
	rm -f vidar/boot/kernel.bin
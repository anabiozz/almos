include init/*.mk

SOURCEDIR=kernel
BUILDDIR=obj
SOURCEDIR_CLIB=clib

SOURCES=$(shell find $(SOURCEDIR) -name '*.c')
OBJECTS=$(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

SOURCES_ASM=$(shell find $(SOURCEDIR) -name '*.asm')
OBJECTS_ASM=$(patsubst $(SOURCEDIR)/%.asm, $(BUILDDIR)/%.o, $(SOURCES_ASM))

SOURCES_CLIB=$(shell find $(SOURCEDIR_CLIB) -name '*.c')
OBJECTS_CLIB=$(patsubst $(SOURCEDIR_CLIB)/%.c, $(BUILDDIR)/clib/%.o, $(SOURCES_CLIB))

OBJ += \
	$(OBJECTS) $(OBJECTS_ASM) $(OBJECTS_CLIB)

CC=gcc
LD=ld
NASM=nasm

CFLAGS = -c -m32 -std=c99 -nostdlib -fno-builtin \
	-fno-exceptions -fno-leading-underscore -I include/ -I clib/include/
LDFLAGS= -m elf_i386 -T link.ld

MD=mkdir -p

kernel.bin: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o vidar/boot/kernel.bin

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.asm
	$(NASM) -f elf32 -o $@ $<

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

$(BUILDDIR)/clib/%.o: $(SOURCEDIR_CLIB)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

clear:
	rm -fr $(BUILDDIR)/*
	rm -f vidar/boot/kernel.bin
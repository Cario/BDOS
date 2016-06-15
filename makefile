.PHONY: all compile clean run

all: compile clean run

compile:
	@echo "Compiling..."
	@# Compile the Assembly file that loads the C kernel
	@nasm -f elf32 boot.asm -o boot.o
	@# Compile the C code
	@gcc -m32 -c kernel.c include/*.c -ffreestanding -std=c99
	@# Link the Assembly and C code together to form a .bin file
	@ld -m elf_i386 -T linker.ld -o kernel.bin *.o

clean:
	@# Clean up by removing the .o files
	@rm *.o

run:
	@echo "Running..."
	@# Emulate the operating system using QEMU
	@qemu-system-i386 -kernel kernel.bin

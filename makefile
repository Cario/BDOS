all: compile clean run

compile:
	@echo "Compiling..."
	@# Compile the Assembly file that loads the C kernel
	@nasm -f elf32 kernel.asm -o kasm.o
	@# Compile the C code
	@gcc -m32 -c kernel.c -o kc.o -ffreestanding
	@# Link the Assembly and C code together to form a .bin file
	@ld -m elf_i386 -T link.ld -o iso/boot/kernel.bin kasm.o kc.o

clean:
	@# Clean up by removing the .o files
	@rm *.o

run:
	@echo "Running..."
	@# Emulate the operating system using QEMU
	@qemu-system-i386 -kernel iso/boot/kernel.bin

iso:
	@echo "Generating ISO..."
	@# Generate an ISO image
	@grub-mkrescue -o bdos.iso iso/

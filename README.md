# BDOS
This is intended to be a highly efficient, powerful, lightweight console operating system. Although, it is certainly a work in progress.

## Compiling and Testing
In order to compile and test BDOS on a Linux system, you will need to have **gcc** and **ld** (although, in linux these should be installed by default) and **nasm** installed. You will also want to have **qemu** installed because this is what the makefile uses to test the operating system. Additionally, **grub-mkrescue** is recommended.
After installing all of those, just run the **makefile** by navigating to the BDOS directory in the terminal and using the following command: `make` 

### Generating an ISO
To generate an .iso file, which can be virtualized in a VM client or burned to a CD, USB, or floppy, you will need to have **grub-mkrescue** installed on your system. Once this is installed, you can generate an ISO by using the command: `make iso`

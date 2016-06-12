# BDOS
This is intended to be a highly efficient, powerful, lightweight console operating system. Although, it is certainly a work in progress.

## Compiling and Testing
In order to compile and test BDOS on a Linux system, you will need to have **gcc** and **ld** to compile (although, in linux these should be installed by default), you will also want to have **qemu** installed because this is what the build script uses to test the operating system. Additionally, **nasm** and **grub-mkrescue** are recommended.
After installing all of those, just run the **build.sh** script by navigating to the BDOS directory in the terminal and using the following command: `./build.sh` 

### Generating an ISO
To generate an .iso file, which can be virtualized in a VM client or burned to a CD, USB, or floppy, you will need to have **grub-mkrescue** installed on your system. Once that is installed all you have to do is uncomment the last line in **build.sh**.

# BDOS
This is intended to be a highly efficient, powerful, lightweight console operating system. Although, it is certainly a work in progress.

## Compiling and Testing
*This OS is primarily being developed on Ubuntu, the makefile and this README don't have tested support for any other operating systems.*

Recommended packages to have installed on your development system:
* **gcc**
* **ld**
* **nasm**
* **make**
* **qemu**

After insuring that all of these packages are installed, you can **compile** the project by executing the following command in the project directory: `make compile`

To **test** the OS you can use the command: `make run`

Or, if you want to do it all in one command, just type: `make`

## Editing
The main file that we care about editing is the **kernel.c** file. This is where all the fun stuff happens.

In **kernel.c** we use the functions defined in the header and C files in the **include** directory.

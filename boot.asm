bits 32					; Set things in 32 bits mode

section .text
	align 	4 			; Align data to a 32 bit boundary, the following values are each 32 bits
	dd		0x1badb002	; Put 0x1badb002 on the stack at, we'll call it Stack Position 1
	dd		0x00000000	; Put 0x00000000 on the stack at the next address, Stack Position 2
	dd		0xe4524ffe	; Put -(0x1badb002 + 0x00) on the stack, Stack Position 3

global start			; Declare the start function
extern kmain			; Announce the presence of kmain, located in our c code (kernel.c)

start:					; Define the start function
	call kmain			; Send processor to continue execution from the kmain function
	hlt					; Halt the cpu (pause it from executing from this address)

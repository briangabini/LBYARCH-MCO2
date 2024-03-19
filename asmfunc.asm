
section .data
	msg db "Hello, World!", 13, 10, 0

section .text
bits 64
default rel

global asmfunc
extern printf

asmfunc: 
	sub rsp, 8*5	; caller
	mov rcx, msg
	call printf
	add rsp, 8*5
	ret

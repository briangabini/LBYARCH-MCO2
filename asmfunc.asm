section .text
bits 64
default rel

global asmfunc
asmfunc: 
mulsd xmm0, xmm1 ; A * B
addsd xmm0, xmm2 ; A * B + C
ret
%include "io64.inc"

section .text
bits 64
default rel

global dotProductx64
extern printf

dotProductx64:
    mov rax, rcx
    xorpd xmm1, xmm1
    xor rdx, rdx  

compute_product:
    movsd xmm0, [rdx + r8]  
    mulsd xmm0, [r10 + r9] 
    addsd xmm1, xmm0       
    add rdx, 8                
    cmp rdx, rax       
    jne compute_product          
                     
    movsd [rsi], xmm1          
    ret
    xor rax, rax
    ret
    
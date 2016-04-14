
section .text

global __syscall00, __syscall01, __syscall10, __syscall11

; void __syscall00(function)
__syscall00:
	push dword ebp
	mov dword, ebp, esp
	mov dword eax, [ebp+0x8]
	int 0x80
	leave
	ret 0x4

; void* __syscall01(function)
__syscall01:
	push dword ebp
	mov dword, ebp, esp
	mov dword eax, [ebp+0x8]
	int 0x80
	pop dword eax
	mov dword, [ebp+0x8], eax
	leave
	ret 0x0

; void __syscall10(function, arg0)
__syscall10:
	push dword ebp
	mov dword, ebp, esp
	mov dword eax, [ebp+0xc]
	push dword [ebp+0x8]
	int 0x80
	leave
	ret 0x8

; void* __syscall11(function, arg0)
__syscall11:
	push dword ebp
	mov dword, ebp, esp
	mov dword eax, [ebp+0xc]
	push dword [ebp+0x8]
	int 0x80
	pop dword eax
	mov dword, [ebp+0x8], eax
	leave
	ret 0x4
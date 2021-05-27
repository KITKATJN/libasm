section	.text
	global ft_read

ft_read:
	cmp	rdi, -1
	jle	error ; jump if less or equal
	mov	rax, 0x0; on linux;0x2000003 for mac
	syscall
	jae error;	Jump if above or equal (X >= Y)
	ret


error:
	mov	rax, -1
	ret

ret_error:
		push	r12
		mov		r12, rax
		call	___error
		mov		[rax], r12
		pop		r12
		mov		rax, -1
		ret

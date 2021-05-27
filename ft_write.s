;Аргументы идут в регистры RDI , RSI , RDX , R10 , R8 , и R9
section	.text
	global ft_write

ft_write:
	cmp	rdi, -1
	jle	error ; jump if less or equal
	mov	rax, 0x1; on linux;0x2000004 for mac
	syscall
	jae error;	Jump if above or equal (X >= Y)
	ret


error:
	mov	rax, -1
	ret

	

		section	.text
		extern	___error
		global	_ft_write


_ft_write:
		mov		rax, 0x2000004
		syscall
		jc ret_error
		ret

ret_error:
		push	r12
		mov		r12, rax
		call	___error
		mov		[rax], r12
		pop		r12
		mov		rax, -1
		ret

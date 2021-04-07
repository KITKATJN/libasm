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
	mov	rax, 0
	ret

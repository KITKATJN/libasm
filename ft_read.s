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
	mov	rax, 0
	ret

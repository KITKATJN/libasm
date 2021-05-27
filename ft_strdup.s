section	.text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	mov		rbx, rdi
	call	ft_strlen
	inc		rax
	mov		rdi, rax
	push	rdi
	call	malloc
	mov		rdi, rax
	mov		rsi, rbx
	call	ft_strcpy
	pop		rdi
	ret


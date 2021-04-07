section	.text
	global ft_strcmp

ft_strcmp:
	mov		R8, 0
	mov		R9, 0
	jmp		while

while:
	mov		al, BYTE[rdi + R8]
	mov		cl, BYTE[rsi + R9]
	cmp		al, 0
		je		exit
	cmp		cl, 0
		je		exit
	movzx	rax, al
	movzx	rbx, cl
	sub		rax, rbx
	cmp		rax, 0
		jne		exit2
	inc		R9
	inc		R8
	jmp		while

exit2:
	ret

exit:
	movzx	rax, al; копируем значение в больший регистр
	movzx	rbx, cl
	sub		rax, rbx
	ret

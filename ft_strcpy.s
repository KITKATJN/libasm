section	.text
	global ft_strcpy

ft_strcpy:
	cmp	rsi, 0
	je	exit
	mov	R9, 0
	jmp	while

while:
	cmp	BYTE[rsi + R9], 0
	je	exit
	mov	al, BYTE[rsi + R9]
	mov	BYTE[rdi + R9], al
	inc	R9
	jmp while

exit:
	mov	BYTE[rdi + R9], 0
	mov	rax, rdi
	ret

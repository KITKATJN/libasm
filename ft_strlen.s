
section	.text
	global ft_strlen

ft_strlen:
	mov	rax, 0; регистр int или u int eax в 32 битах был в 64 это rax
	jmp	while ;jump

while:
	cmp	BYTE[rdi + rax], 0; compare
	je	return ; если дошли до конца строки, то заканчиваем
	inc	rax ; провсто увеличиваем на 1
	jmp	while

return:
	ret

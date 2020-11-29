TITLE	codigo.c
.686
.XMM
.model 	flat
_DATA	SEGMENT
_DATA	ENDS
_CONST	SEGMENT
__real@00000000	DD	000000000r
_@4$	DB	'A', 00H
_CONST	ENDS
	mov	DWORD PTR _v$[ebp], 0
_TEXT	SEGMENT
_argc$ = 8
_argv$ = 12
_i$ = 0
_sum$ = 0
_@3$ = -4
_f$ = -12
_c$ = -13
_@7$ = -13
_@10$ = -13
_j$ = -13
_@8$ = -13
_main	PROC
	push	ebp
	mov		ebp, esp
	sub		esp, 76
	push	ebx	
	push	esi	
	push	edi	
	mov	eax, DWORD PTR _x$[ebp]
	mov	DWORD PTR _sum$[ebp], eax
	mov	eax, 0	add	eax, 2	mov	 DWORD PTR _@3$[ebp], eax
	movss	xmm0, DWORD PTR _@3$[ebp]
	movss	DWORD PTR _f$[ebp], xmm0
	mov	DWORD PTR _c$[ebp], 16777281
	mov	DWORD PTR _i$[ebp], 1
$LN7@main:
	cmp	DWORD PTR _i$[ebp], 20
	jle	SHORT $LN12@main
	jmp	SHORT $LN15@main
$LN9@main:
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR _@7$[ebp], eax
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	 DWORD PTR _i$[ebp], eax
	jmp	SHORT $LN7@main
$LN12@main:
	mov	eax, DWORD PTR _@8$[ebp]
	mov	DWORD PTR _sum$[ebp], eax
	jmp	SHORT $LN9@main
$LN15@main:
	jmp	SHORT $LN24@main
$LN16@main:
	mov	eax, DWORD PTR _sum$[ebp]
	mov	DWORD PTR _@10$[ebp], eax
	mov	eax, DWORD PTR _sum$[ebp]
	add	eax, 1
	mov	 DWORD PTR _sum$[ebp], eax
	jmp	SHORT $LN27@main
$LN19@main:
	mov	DWORD PTR _sum$[ebp], 0
	jmp	SHORT $LN27@main
$LN21@main:
	mov	DWORD PTR _sum$[ebp], 0
	jmp	SHORT $LN27@main
	jmp	SHORT $LN27@main
$LN24@main:
	cmp	DWORD PTR _sum$[ebp], 0
	jne	SHORT $LN16@main
	cmp	DWORD PTR _sum$[ebp], 1
	jne	SHORT $LN19@main
	jmp	SHORT $LN21@main
$LN27@main:
	jmp SHORT $exit@main
$exit@main:
	pop		edi
	pop		esi
	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret		0
_main	ENDP
_TEXT	ENDS
END


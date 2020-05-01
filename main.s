	.file	"main.c"
@ GNU C version 3.3.6 (arm-thumb-elf)
@	compiled by GNU C version 7.5.0.
@ GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
@ options passed:  -fpreprocessed -mthumb-interwork -mlong-calls
@ -auxbase-strip -O2 -Wall -fverbose-asm
@ options enabled:  -fdefer-pop -fomit-frame-pointer
@ -foptimize-sibling-calls -fcse-follow-jumps -fcse-skip-blocks
@ -fexpensive-optimizations -fthread-jumps -fstrength-reduce -fpeephole
@ -fforce-mem -ffunction-cse -fkeep-static-consts -fcaller-saves
@ -freg-struct-return -fgcse -fgcse-lm -fgcse-sm -floop-optimize
@ -fcrossjumping -fif-conversion -fif-conversion2 -frerun-cse-after-loop
@ -frerun-loop-opt -fdelete-null-pointer-checks -fschedule-insns
@ -fschedule-insns2 -fsched-interblock -fsched-spec -fbranch-count-reg
@ -freorder-blocks -freorder-functions -fcprop-registers -fcommon
@ -fverbose-asm -fgnu-linker -fregmove -foptimize-register-move
@ -fargument-alias -fstrict-aliasing -fmerge-constants
@ -fzero-initialized-in-bss -fident -fpeephole2 -fguess-branch-probability
@ -fmath-errno -ftrapping-math -mapcs -mapcs-frame -mapcs-32 -msoft-float
@ -mthumb-interwork -mlong-calls

	.text
	.align	2
	.global	drawRect
	.type	drawRect, %function
drawRect:
	@ Function supports interworking.
	@ args = 4, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	stmfd	sp!, {r4, r5, lr}
	mov	r4, #0	@  y
	cmp	r4, r3	@  y,  height
	mov	r5, r3	@  height
	ldrsh	lr, [sp, #12]	@  clr,  clr
	bge	.L13
	rsb	r1, r1, r1, asl #4	@  top,  top
.L11:
	cmp	r2, #0	@  width
	ble	.L15
	add	r3, r0, r1, asl #4	@  left
	mov	r3, r3, asl #1
	add	r3, r3, #100663296
	mov	ip, r2	@  x,  width
.L10:
	subs	ip, ip, #1	@  x,  x
	strh	lr, [r3], #2	@ movhi 	@  clr
	bne	.L10
.L15:
	add	r4, r4, #1	@  y,  y
	cmp	r4, r5	@  y,  height
	add	r1, r1, #15
	blt	.L11
.L13:
	ldmfd	sp!, {r4, r5, lr}
	bx	lr
	.size	drawRect, .-drawRect
	.align	2
	.global	main
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {r4, r5, r6, r7, fp, ip, lr, pc}
	mov	r3, #1024
	add	r3, r3, #3
	sub	fp, ip, #-4294967292
	sub	sp, sp, #4
	mov	r2, #67108864
	mov	r0, #38400	@  i
	str	r3, [r2, #0]
	mov	r3, #100663296
.L22:
	mov	r1, #0	@ movhi
	subs	r0, r0, #1	@  i,  i
	strh	r1, [r3], #2	@ movhi 
	bne	.L22
	mov	r5, #32512
	mov	r4, r0	@  x,  i
	mov	r6, #67108864
	mov	r7, r0	@  red,  x
	add	r5, r5, #255
.L40:
	ldrh	r3, [r6, #6]
	cmp	r3, #159
	bhi	.L40
	mov	r2, #67108864
.L29:
	ldrh	r3, [r2, #6]
	cmp	r3, #159
	bls	.L29
	cmp	r4, #5760	@  x
	movgt	r4, #0	@  x
	cmp	r4, #0	@  x
	bne	.L41
.L34:
	ldr	r2, .L42
	smull	r1, r3, r2, r4	@  x
	mov	r0, r4, asr #31	@  x
	add	r3, r3, r4	@  x
	rsb	r0, r0, r3, asr #7
	add	r1, r0, r0, asl #2
	mov	r2, #10
	rsb	r0, r0, r0, asl #4
	sub	r0, r4, r0, asl #4	@  x
	mov	r1, r1, asl #1
	mov	r3, r2
	str	r5, [sp, #0]
	bl	drawRect
	add	r4, r4, #10	@  x,  x
	b	.L40
.L41:
	ldr	r3, .L42
	sub	r0, r4, #10	@  last,  x
	smull	r1, r2, r3, r0	@  last
	mov	r3, r0, asr #31	@  last
	add	r2, r2, r0	@  last
	rsb	r3, r3, r2, asr #7
	add	r1, r3, r3, asl #2
	mov	r2, #10
	rsb	r3, r3, r3, asl #4
	sub	r0, r0, r3, asl #4	@  last
	mov	r1, r1, asl #1
	mov	r3, r2
	str	r7, [sp, #0]	@  red
	bl	drawRect
	b	.L34
.L43:
	.align	2
.L42:
	.word	-2004318071
	.size	main, .-main
	.align	2
	.global	MakeCol
	.type	MakeCol, %function
MakeCol:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	and	r1, r1, #255	@  green
	and	r0, r0, #255	@  red
	orr	r0, r0, r1, asl #5	@  red,  green
	mov	r0, r0, asl #16
	orr	r0, r0, r2, asl #26
	mov	r0, r0, lsr #16
	@ lr needed for prologue
	bx	lr
	.size	MakeCol, .-MakeCol
	.align	2
	.global	vsync
	.type	vsync, %function
vsync:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	@ lr needed for prologue
	mov	r2, #67108864
.L46:
	ldrh	r3, [r2, #6]
	cmp	r3, #159
	bhi	.L46
	mov	r2, #67108864
.L49:
	ldrh	r3, [r2, #6]
	cmp	r3, #159
	bls	.L49
	bx	lr
	.size	vsync, .-vsync
	.ident	"GCC: (GNU) 3.3.6"

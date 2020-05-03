	@ function signature:  void drawLevelTitle(int x, int y, int uniqueId)
	@ r0 --> x
	@ r1 --> y
	@ r2 --> uniqueId ==> in this case it'll be "LEVEL_TITLE_ID" from ./sprites_id.h)

	@ this function will draw 'LEVEL 1' in the game

.GLOBL	drawLevelTitle
drawLevelTitle:
	mov	ip, sp
	stmfd	sp!, {r4, r5, r6, r7, fp, ip, lr, pc}
	mov	r6, r1						@x-position 
	sub	fp, ip, #-4294967292
	mov	r5, r2						@ uniqueId
	ldr	r7, .drawSpriteFn			@ load label 'drawSprite' into r6
	mov	r4, r0						@ r4 = x
	mov	r1, r2						@ r1 = y
	mov	r3, r6						
	mov	r2, r0						
	mov	r0, #35						@ load the letter 'L' from sprites.h
	mov	lr, pc
	bx	r7							@ branch exchange to drawSprite function in "draw.h". comes back after here after execution
	
	add	r1, r5, #1					
	add	r2, r4, #16					@ add 16 to intial x to get new x position for next letter. since each sprite is 16x16
	mov	r3, r6						
	mov	r0, #31						@ load the letter 'E' from sprites.h
	mov	lr, pc
	bx	r7							@ branch exchange to drawSprite function

	add	r1, r5, #2					
	add	r2, r4, #32					@ add 32 to intial x position to get new x position for next letter
	mov	r3, r6						
	mov	r0, #36						@ load the letter 'V' from sprites.h
	mov	lr, pc
	bx	r7

	add	r1, r5, #3					
	add	r2, r4, #48					@ add 48 to intial x position to get new x position for next letter
	mov	r3, r6						
	add	r4, r4, #64					
	mov	r0, #31      				@ load the letter 'E' from sprites.h
	mov	lr, pc
	bx	r7							@drawSprite function

	add	r1, r5, #4	
	mov	r2, r4	
	mov	r3, r6	
	add	r5, r5, #5
	mov	r0, #35						@ load the letter 'L' from sprites.h
	mov	lr, pc
	bx	r7

	mov	r1, r5
	mov	r3, r6
	mov	r2, #86						@ here we add 84 to initial x position as we want to give a space between 'LEVEL' and '1'
	mov	r0, #37						@load the sprite '1' from sprites.h
	mov	lr, pc
	bx	r7							@drawSprite function

	ldmea	fp, {r4, r5, r6, r7, fp, sp, lr}
	bx	lr

.drawSpriteFn:
	.word	drawSprite
	

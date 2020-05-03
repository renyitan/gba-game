.GLOBL removeSprite
removeSprite:
    swp     r0, r0, [sp]			 @ pop last input argument from stack and put it in r4
    stmfd   sp!, {r0-r11, lr}     @ save content of r4-r11 and link register into the sp register
    @ Start your assembly code here
    @ Also, think about breaking the
    @ code into sub-macros you can branch
    @ to/from, and comment each line with
    @ the corresponding C instruction
    mov r1, 0x7000000
    mov r2, 0x7000002
    mov r0, r0, LSL, 3
    add r1, r1, r0
    add r2, r2, r0
    mov [r1], 0x2000000
    mov [r2], 0x4000000
    end

    @ Exit from function
	end: 
		ldmfd   sp!, {r0-r11, lr}     @ Recover past state of r4-r11 and link register from sp register
		swp     r0, r0, [sp]			 @ Restore state of r4
		mov     pc, lr					 @ Branch back to lr (go back to C code that called this function)
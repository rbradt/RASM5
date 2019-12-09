	.global aBubbleSort
	@ r0 = array size
	@ r1 = pointer to first element of integer array
	
aBubbleSort:
	push {r1-r11, lr}

	sub r2, r0, #1
	iloop:
		mov r3, #0
		jloop:
			// if the int at j is greater than the int at j+1 -> swap the two integers
			add r6, r1, r3, LSL #2	@ r6 = &array[j]
			ldr r4, [r6]			@ r4 = array[j]
			
			add r3, r3, #1			@ j++
			
			add r7, r1, r3, LSL #2	@ r7 = &array[j+1]
			ldr r5, [r7]			@ r5 = array[j+1]
			
			cmp r4, r5
			ble continue
			
			str r4, [r7]			@ array[j+1] = value at j
			str r5, [r6]			@ array[j] = value at j+1
			
			continue:
			cmp r3, r2
			blt jloop
	
		sub r2, r2, #1				@ i--
	
		cmp r2, #2
		bge iloop
		
return:
	pop {r1-r11, lr}
	bx lr
	.end

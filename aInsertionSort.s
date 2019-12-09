	.global aInsertionSort
	@ r0 = array size
	@ r1 = pointer to first element of integer array
	
aInsertionSort:	
	push {r1-r11, lr}
	
	@ for all integers in the array
	mov r2, #1 						@ i = 1
	iloop:
		cmp r2, r0 					@ end of the array has been reached
		bge return
		
		add r10, r1, r2, LSL #2		@ temp = array[i]
		ldr r10, [r10] 				
		
		@ for all integers to the left of array[i] that are greater than array[i] -> shift one to the right
		sub r3, r2, #1 				@ j = i - 1
		jloop:
			cmp r3, #0 				@ start of array has been reached
			blt jloopend
			
			add r9, r1, r3, LSL #2	@ current = array[j]
			ldr r9, [r9] 			
			
			cmp r10, r9 			@ temp < current
			bge jloopend
			
			add r8, r1, r3, LSL #2	@ shift to array[j+1]
			add r8, r8, #4 			
			str r9, [r8] 			@ array[j+1] = current
			
			sub r3, r3, #1 			@ j--
			
			b jloop
		
		@ after shifting all greater integers to the right -> store array[i] in the freed spot
		jloopend:	
			add r3, r3, #1			@ shift to array[j+1]
			add r8, r1, r3, LSL #2	
			str r10, [r8] 			@ array[j+1] = temp
			
			add r2, r2, #1 			@ i++
			
			b iloop

return:
	pop {r1-r11, lr}
	bx lr
	.end

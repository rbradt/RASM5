	.global aBubbleSort
	@ r0 = array size
	@ r1 = pointer to first element of integer array
	
aBubbleSort:
	push {r1-r11, lr}

	
	
return:
	pop {r1-r11, lr}
	bx lr
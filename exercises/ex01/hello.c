#include <stdio.h>

int main() {
    int x = 5;
    int y = x+1;
    printf("%d\n", y);
    return 0;
}

/*
1.When "int x =5" was added to the code,
		subq	$16, %rsp
		mov1 $5, -4(%rbp) were added in the assembly code.
* The lines stores variable into an address

2. When optimization using flag -O2 is turned on,the following lines
have been omitted from the assembly code:
    subq	$16, %rsp
    movl	$5, -4(%rbp)
    movl	$.LC0, %edi
    movl	$0, %eax.
* During optimization, the lines associated with the value x were unused and therefore deletd.

3. Without optimization, the lines associated with x appeared in multiple places before
the print function was called. However, when optimization was performed, the variable
x was only appeared right before the print function, since optimization disregards
variable that is never used, making the program faster.

4.The optimization simplifies the assembly code to
movl	$6, %eax
as it immediately stores the y value as six, ignoring x.
However, without optimization, x is also created and defined.

As a conclusion, optimization reduces memory space and speeds the program up
as it only stores variables that are used.
*/

/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
<<<<<<< HEAD
    static int array[SIZE]; // by making array a static variable, the variable remains
                            // in the diagram
=======
    int array[SIZE];

>>>>>>> 12d0788dab1ae56a12243b954a7877e1d69b91ef
    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/*
1. The stack.c file presents different ways in initalizing array size of 5.
The foo function sets every element in the array to be 42, {42,42,42,42,42}.
In bar function, the element increments by one, resulting {0,1,2,3,4}. In main
function, even through boo function is called, foo is called to be stored
in int pointer, array, and array is to be printed. Therefore, the main function
will result printing 42 five times.

2. When compiling, the following error has been reached:
stack.c:22:12: warning: function returns address of local variable [-Wreturn-local-addr]
     return array;
The warning indicates that the function is returning an address of local variable,
which would be removed from after foo function finishes running.

3. I received a "Segmentation fault (core dumped) " when I ran the code. It indicates
that the code tried to access memeory that I don't have access to, which is reasonable
since array is removed after foo function returns.

4. After un-commenting the print statement in foo and bar function, I have received
0x7fffb8a91a60
0x7fffb8a91a60
Segmentation fault (core dumped).


*/

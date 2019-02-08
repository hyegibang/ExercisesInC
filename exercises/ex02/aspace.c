/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_local(){
  int b = 22;
  printf ("Address of local variable, b,  is %p\n", &b);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";
    void *a = malloc(256);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("a points to %p\n", a);

    print_local();

    void *c1 = malloc(16);
    void *c2 = malloc(16);
    printf ("c1 points to %p\n", c1);
    printf ("c2 points to %p\n", c2);

    return 0;
}



/*
4. After adding second malloc function, the address of heap increase toward the
larger address. Before the address of p was originally 0x194c010, 26525712 in decimal,
when second malloc, a, is added the address of a resulted in 0x21f7010, 35614736 in
decimal.

5. The size of stack grew from 0x7ffcb122bc6c, 1.4072328e+14 in decimal, to
 0x7ffe5b65b164, 1.4073043e+14 in decimal, after adding a local variable.

 6.
"c1 points to 0xf935c0
 c2 points to 0xf935e0"

 The space between two variables is 32 bytes.
 */

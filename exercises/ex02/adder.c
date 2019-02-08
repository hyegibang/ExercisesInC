/*
Adder.c file written by Hyegi Bang for Software Systems class in Olin College
of Enginnering. The following code allows the user to enter integers, one per
line, until the user hits Control-D.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declare constant variable for array size*/
static int buffersize = 5;
static int arraysize = 5;

int main(){
  int sum = 0;
  int index = 0;
  int intarray[arraysize];

  while(1){
    char number[10];
    puts("Enter a number");
    /*Checks whether control+D is pressed */
    if (fgets(number, buffersize, stdin) == NULL){
      break;
    }

    /*Checks whether user inputted a value with greater buffersize */
    if (number[strlen(number)-1] != '\n'){
      printf("Error: Exceed Buffersize\n" );
      break;
    }

    /*Checks whether user inputted more than the arraysize */
    if(index >= arraysize){
      printf("Error: Exceed ArraySize\n");
      break;
    }

    /*Converts string to an integer */
    intarray[index] = atoi(number);
    index ++;
  }
  /* Calculates the sum of the user input */
  for (int i =0; i < index; i++){
    sum = sum + intarray[i];
  }

  printf("Sum is %i\n",sum );
  return 0;
}

/*
Adder.c file written by Hyegi Bang for Software Systems class in Olin College
of Enginnering. The following code allows the user to enter integers, one per
line, until the user hits Control-D
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 20
#define MAXIT 4

int str2int();
void user_enter();

int main(){
  char number[MAXIT];
  int numberarray[MAXIT];

  int sum = 0;
  int index = 0;

    do{
      user_enter(number);

    // char *fgets(char *str, int n, FILE *stream)
    if(fgets(number,11,stdin) != NULL){
      if(strlen(number) > 10){
        printf("Hello" );
      }else {
        if(index < MAXIT){
          numberarray[index] = str2int(number);
          index++;
        }else{
          printf("Exceed possible number of interation" );
        }
      }
    }
  } while(fgets(number,11,stdin) != NULL);
    for(int i =0; i <= index; i++){
      sum = sum + number[i];
      printf("%i\n", sum);
    }
    printf("Sum is %i\n",sum );
    return 0;
  }






int str2int(char *s){
  int val = atoi(s);
  printf("Val is %i\n", val);
  return val;

}

void user_enter(char *number){
  puts("Enter a number");
  scanf("%2s", number);
}

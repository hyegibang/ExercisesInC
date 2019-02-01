/* cards.c written by Hyegi Bang for Software Systems class
  in Olin College of Engineering.
  The following code resembles card counting system program.
  Based on user's input of the card value, the count increases
  by 1 if the value is between 3-6 and decreases by 1 if the value
  is J, Q, K , 10.
*/

#include <stdio.h>
#include <stdlib.h>

/* Main function of the program that performs card counting based
on user input. The program terminates when the user inputs the
character, 'x'.

*/


int main() {
  char card_name[3];
  int count = 0;
  int val = 0;
  char *promt = "Enter the card_name:";

  while (card_name[0] != 'X'){
    get_card_name(card_name);
    val = get_card_value(card_name);
    count = get_counter();
    printf("Current count: %i\n", count);
  }
  return 0;
}

/* Prompts the user for input and puts the reply in the given buffer.

       User input is truncated to the first two characters.

       prompt: string prompt to display
       card_name: buffer where result is stored
*/

void get_card_name(char *prompt, char *card_name){
  puts(prompt);
  scanf("%2s", card_name);
}

  /* Returns an integer value of a given card_name

    card_name: buffer where result is stored
    val: corresponding integer value of the given card_name
  */

void get_card_value(char *card_name){
  int val;

  switch (card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      break;
    default:
      return atoi(card_name);
}
}

/* Returns an integer value of a given card_name

  If the card value is between 2 and 7, the count increments by one.
  If the card value is 10, the count reduces by one.

  count: integer value that represents the current count
*/


int get_counter(int val){
  int count;
  if ((val < 1) || (val > 10)) {
    puts("I don't understand that value!");
  }

  if ((val > 2) && (val <7)) {
    count++;
  } else if (val ==10){
    count--;
  }
  return count;
}

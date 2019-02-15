/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>


#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[]){
    int    status;
    regex_t    re;

    // regcomp is used to compile the regular expression pattern,
    // not match it against the input string
    status = regcomp(&re, pattern, 0);

    if (status != 0){
      printf("Error on compiling regular expression\n");
      exit(1);
    }

    //regexec() compares the null-terminated string against the compiled
    // regular expressioin &re to find a match between the two
    for (int i = 0; i< NUM_TRACKS; i++){
      status = regexec(&re, tracks[i], 0, NULL, 0);
      if (status == 0){
        printf("Track %i: '%s'\n", i, tracks[i]);
      }
      else if (status != REG_NOMATCH){
        printf("Error on executing the regular experssion\n");
      }
    }

    //regfree() frees any memory that was allocated by regcomp()
    regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    find_track(search_for);
    //find_track_regex(search_for);

    return 0;
}

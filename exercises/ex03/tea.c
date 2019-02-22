#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// implementation of tee command
int main(int argc,char *argv[]){
  int i;
  char c;
  int flag;
  char intputbuffer[256];
  FILE *out;

// Error message
    if (argc<1){
     fprintf(stderr, "Invalid input\n");
       return 1;
        exit(1);
    }

// Checking input argument and updating based on the input
    while ((ch = getopt(argc, argv, "ai")) != -1){
  		switch((char)ch){
  		case 'a':
  			flag = 1;
  			break;
  		default:
  		    exit(1);
  		}
  	}

//HFC
argc -= optind;
argv += optind;

	while(fgets(in, 256, stdin)) {
		for (int i = 0; i < argc; j++) {
			if (!flag) {
				out = fopen(argv[i], "a");
			}
			else {
				out = fopen(argv[i], "w");
			}

			fprintf(stdout, "%s", intputbuffer);
			fputs(intputbuffer, out);
			fclose(out);
		}
  }
	return 0;
}


/*
1. What worked, what slowed you down? What would you do differently next time?
Understanding the overall concpet was rough for me. I had to do some online
research and ask friends to clarify the understanding. I found the documentations
linked in the readme file most helpful as it gave some example, which helped me
visualize the process. For next time, I would like to actually digest nexessary
fundamental knowledge in HFC before I start.

2.Compare your solution to this professional implementation or this one.
Comparing my solution with the professional code, I realized that I only
handel the most minimal errors whereas the professional code contains every
detailed possible error. For next time, I would also write more detailed
explanation of cause of the error.
*/

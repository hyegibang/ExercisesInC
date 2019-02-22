#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
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

    while ((ch = getopt(argc, argv, "ai")) != -1){
  		switch((char)ch){
  		case 'a':
  			flag = 1;
  			break;
  		default:
  		    exit(1);
  		}
  	}

int numFiles = argc - options - 1;
int fileIndex = options+1;


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
*/

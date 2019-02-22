#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
  int i; 
  char c;
  char intputbuffer[300];
  FILE *out;

//Returns an error if the user does not enter a file name
    if (argc<1){
     fprintf(stderr, "Enter Valid arguments\n");
       return 1;
        exit(1);
    }

    while ((ch = getopt(argc, argv, "ai")) != -1){
  		switch((char)ch){
  		case 'a':
  			append = 1;
  			break;
  		default:
  		    printf("Enter a valid option");
  		    return 1;
  		    exit(1);
  		}
  	}

int numFiles = argc - options - 1;
int fileIndex = options+1;


while (fgets(stdin,800,inputBuffer))
{
    while(numFiles>0)
    {
      if (append==0)
      {
        output = open(argv[fileIndex], "w");
        rewind(output);
      }
      else
      {
          output = open(argv[fileIndex], "a");
      }
      printf("%s\n", inputBuffer);
      frwite(inputBuffer,output);
      fileIndex += 1;
      numFiles-=1;
      fclose(output);
    }
}
    return 0;
}

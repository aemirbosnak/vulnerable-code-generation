//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h> 

#define MAX_LENGTH 80 // maximum length of a command
#define MAX_ARGS 10 // maximum number of arguments in a command

int main() { 

  char input[MAX_LENGTH+1]; // an array to hold the input command
  char *args[MAX_ARGS+1]; // an array of pointers to hold the arguments of the command
  int status, i, j; 
  pid_t pid; 

  while(1) { 

    printf(">> "); // prompt symbol 
    fflush(stdout); // flush output buffer 

    fgets(input, MAX_LENGTH, stdin); // read input from user
    input[strlen(input)-1] = '\0'; // replace newline character with a null character

    args[0] = strtok(input, " "); // tokenize the input command string
    for(i=1; i<MAX_ARGS && args[i-1]!=NULL; i++) { 
      args[i] = strtok(NULL, " "); 
    }
    args[i] = NULL; 

    if(strcmp(args[0], "exit")==0) { // check if user wants to exit the shell
      printf("Exiting shell...\n"); 
      break; 
    }

    if((pid=fork())==-1) { // fork a new process
      printf("Error: fork failed.\n"); 
      exit(1); 
    }

    if(pid==0) { // child process runs the command
      if(execvp(args[0], args)==-1) { // execute the command
        printf("Error: command not found.\n"); 
        exit(1); 
      }
    }
    else { // parent process waits for child process to complete
      waitpid(pid, &status, 0); 
      if(WIFEXITED(status)) { 
        printf("Command executed successfully.\n"); 
      }
    }
  }

  return 0; 
}
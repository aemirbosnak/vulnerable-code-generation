//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 100

char** get_args(char* input);

int main() {
  char input[MAX_COMMAND_LENGTH];
  char** args;

  while(1) {
    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    args = get_args(input);

    if(args[0] == NULL) continue;

    if(strcmp(args[0], "exit") == 0) {
      break;
    } 
    else {
      pid_t pid = fork();

      if(pid == 0) { // child process
        execvp(args[0], args);
        perror("execvp() failed"); // this line should never be reached unless there was an error
        exit(EXIT_FAILURE);
      } 
      else if(pid < 0) { // fork failed
        perror("fork() failed");
      } 
      else { // parent process
        int status;
        waitpid(pid, &status, 0);
      }
    }
  }

  // clean up and exit
  free(args);
  return 0;
}

char** get_args(char* input) {
  char** args = (char**) malloc(MAX_ARGS * sizeof(char*));
  char* arg;
  int i = 0;

  arg = strtok(input, " \n"); // split input by white space and newline
  while(arg != NULL && i < MAX_ARGS - 1) { // allocate memory for args
    args[i++] = strdup(arg);
    arg = strtok(NULL, " \n");
  }
  args[i] = NULL;

  return args;
}
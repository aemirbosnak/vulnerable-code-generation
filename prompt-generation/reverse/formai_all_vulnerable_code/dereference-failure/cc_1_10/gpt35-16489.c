//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 512
#define MAXARGS 20

int main() {
  char input[BUFSIZE];
  char *args[MAXARGS];
  pid_t pid;

  while(1) {
    printf("$ ");
    fgets(input, BUFSIZE, stdin);

    // remove trailing newline
    input[strcspn(input, "\n")] = 0;
    
    // Tokenize input
    char *token;
    int i = 0;
    token = strtok(input, " ");
    while(token != NULL && i < MAXARGS-1){
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if(strcmp(args[0], "exit") == 0) {
      break;
    }

    pid = fork();
    if(pid < 0) {
      fprintf(stderr, "fork failed");
      exit(1);
    }
    else if(pid == 0) {
      // Child process
      execvp(args[0], args);
      fprintf(stderr, "%s: command not found\n", args[0]);
      exit(1);
    }
    else {
      // Parent process
      waitpid(pid, NULL, 0);
    }
  }
  return 0;
}
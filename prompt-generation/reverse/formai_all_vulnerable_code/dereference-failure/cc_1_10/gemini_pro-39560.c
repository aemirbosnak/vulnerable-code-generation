//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length of a command line */
#define MAX_ARGS 20 /* The maximum number of arguments */

/* The main function */
int main() {
  char line[MAX_LINE]; /* The command line */
  char *args[MAX_ARGS]; /* The arguments */
  int pid; /* The process ID */
  int status; /* The process status */
  char cwd[200];

  while (1) {
    printf("\n%s@%s: ", getenv("USER"), getcwd(cwd, sizeof(cwd)));
    fgets(line, MAX_LINE, stdin);
    
    char *tok = line;
    int argc = 0;
    
    while(tok != NULL){
        args[argc] = strtok(tok, " ");
        tok = strtok(NULL, " ");
        argc++;
    }
    args[argc] = NULL;
    
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1] == NULL) {
        chdir(getenv("HOME"));
      } else {
        chdir(args[1]);
      }
    } else {
      pid = fork();
      if (pid < 0) {
        perror("fork");
        exit(1);
      } else if (pid == 0) {
        
        execvp(args[0], args);
      } else {
        waitpid(pid, &status, 0);
        printf("\nChild process terminated with status %d\n", status);
      }
    }
  }

  return 0;
}
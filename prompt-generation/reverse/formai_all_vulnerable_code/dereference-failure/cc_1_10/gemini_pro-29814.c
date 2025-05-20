//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 1024

int main(void) {

  char line[MAXLINE];
  char *args[MAXLINE/2 + 1]; /* command line (of arguments) */
  int should_run = 1; /* flag to determine when to exit program */

  while (should_run) {
    printf("> "); /* print prompt */

    /* read input from stdin */
    if (fgets(line, MAXLINE, stdin) == NULL) {
      break;
    }

    /* tokenize input into arguments */
    int num_args = 0;
    args[num_args++] = strtok(line, " ");

    while ((args[num_args++] = strtok(NULL, " ")) != NULL);

    /* check for special commands */
    if (strcmp(args[0], "exit") == 0) {
      should_run = 0;
      continue;
    }

    /* create a child process to execute the command */
    pid_t pid = fork();

    if (pid == 0) {
      /* child process */
      execvp(args[0], args);
      printf("Invalid command\n");
      exit(1);
    } else if (pid < 0) {
      /* error occurred */
      printf("Error creating child process\n");
    } else {
      /* parent process */
      int status;
      waitpid(pid, &status, 0);
    }
  }

  return 0;
}
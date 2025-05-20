//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* 80 characters per line, plus newline */

int main(void) {
  char line[MAX_LINE];
  char *args[MAX_LINE / 2 + 1]; /* command line (of arguments and terminated by NULL) */
  int should_run = 1; /* flag to determine when to exit program */

  while (should_run) {
    /* Print prompt */
    printf("osh> ");
    fflush(stdout);

    /* Read input */
    if (!fgets(line, sizeof(line), stdin)) {
      break; /* EOF */
    }

    /* Parse input */
    args[0] = strtok(line, " \t\n");
    int i = 1;
    while ((args[i] = strtok(NULL, " \t\n"))) {
      i++;
    }

    /* Check for special commands */
    if (strcmp(args[0], "exit") == 0) {
      should_run = 0;
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1]) {
        chdir(args[1]);
      }
    } else {
      /* Execute command */
      pid_t child_pid = fork();
      if (child_pid == 0) { /* Child process */
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
      } else { /* Parent process */
        int status;
        waitpid(child_pid, &status, 0);
      }
    }
  }

  return 0;
}
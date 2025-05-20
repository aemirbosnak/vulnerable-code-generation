//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  char line[MAX_LINE];
  char *args[MAX_LINE / 2 + 1];
  int status;
  int i;

  while (1) {
    printf("> ");
    fflush(stdout);

    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }

    line[strlen(line) - 1] = '\0';

    i = 0;
    args[i] = strtok(line, " ");
    while (args[i] != NULL) {
      i++;
      args[i] = strtok(NULL, " ");
    }

    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1] == NULL) {
        fprintf(stderr, "cd: no argument\n");
      } else {
        if (chdir(args[1]) != 0) {
          fprintf(stderr, "cd: %s: no such directory\n", args[1]);
        }
      }
    } else {
      pid_t pid = fork();

      if (pid < 0) {
        fprintf(stderr, "fork: failed\n");
      } else if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "%s: command not found\n", args[0]);
        exit(EXIT_FAILURE);
      } else {
        waitpid(pid, &status, 0);
      }
    }
  }

  return 0;
}
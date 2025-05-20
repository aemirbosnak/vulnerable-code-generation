//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int num_args;

  while (1) {
    printf("$ ");
    fflush(stdout);

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      break;
    }

    num_args = 0;
    args[num_args++] = strtok(line, " ");
    while ((args[num_args++] = strtok(NULL, " ")) != NULL) {
      if (num_args >= MAX_ARGS) {
        fprintf(stderr, "Too many arguments.\n");
        break;
      }
    }

    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) != 0) {
        fprintf(stderr, "Error changing directory.\n");
      }
    } else {
      pid_t pid = fork();
      if (pid == 0) {
        execvp(args[0], args);
        fprintf(stderr, "Error executing command.\n");
        exit(1);
      } else {
        waitpid(pid, NULL, 0);
      }
    }
  }

  return 0;
}
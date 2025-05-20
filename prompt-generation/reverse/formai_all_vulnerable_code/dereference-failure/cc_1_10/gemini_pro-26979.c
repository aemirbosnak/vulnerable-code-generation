//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

char **parse_args(char *line) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  char *arg;
  int i = 0;

  arg = strtok(line, " ");
  while (arg != NULL && i < MAX_ARGS) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }

  return args;
}

int main() {
  char line[MAX_LINE_LENGTH];
  char **args;
  int status;

  while (1) {
    printf("grateful-shell$ ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    args = parse_args(line);

    if (strcmp(args[0], "exit") == 0) {
      printf("Thank you for using the grateful shell!\n");
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1] != NULL) {
        if (chdir(args[1]) == -1) {
          perror("cd");
        }
      } else {
        printf("cd: missing argument\n");
      }
    } else {
      pid_t pid = fork();

      if (pid == 0) {
        if (execvp(args[0], args) == -1) {
          perror(args[0]);
          exit(1);
        }
      } else {
        wait(&status);
      }
    }

    free(args);
  }

  return 0;
}
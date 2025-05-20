//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 32

char **parse_input(char *input) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  char *arg;
  int i = 0;

  if (!args) {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  arg = strtok(input, " \t\n");
  while (arg != NULL && i < MAX_ARGS - 1) {
    args[i++] = arg;
    arg = strtok(NULL, " \t\n");
  }
  args[i] = NULL;  

  return args;
}

int main() {
  char input[MAX_INPUT_LENGTH];
  char **args;
  pid_t pid;

  while (1) {
    printf("> ");
    fflush(stdout);

    if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
      printf("\n");
      exit(EXIT_SUCCESS);
    }

    args = parse_input(input);

    if (!args[0]) {
      continue;
    }

    if (strcmp(args[0], "exit") == 0) {
      free(args);
      exit(EXIT_SUCCESS);
    }

    pid = fork();
    if (pid == -1) {
      perror("Fork failed");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      if (execvp(args[0], args) == -1) {
        perror("Command failed");
        exit(EXIT_FAILURE);
      }
    } else {
      wait(NULL);
    }

    free(args);
  }

  return EXIT_SUCCESS;
}
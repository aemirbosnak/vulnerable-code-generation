//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

void print_prompt() {
  printf("\n$ ");
}

char *read_line() {
  char *line = malloc(MAX_LINE_LENGTH);
  if (line == NULL) {
    perror("malloc");
    exit(1);
  }
  fgets(line, MAX_LINE_LENGTH, stdin);
  return line;
}

char **parse_args(char *line) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  if (args == NULL) {
    perror("malloc");
    exit(1);
  }
  int i = 0;
  char *arg = strtok(line, " ");
  while (arg != NULL && i < MAX_ARGS) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  return args;
}

int execute_command(char **args) {
  if (strcmp(args[0], "exit") == 0) {
    exit(0);
  } else {
    execvp(args[0], args);
    perror("execvp");
    return 1;
  }
}

int main() {
  while (1) {
    print_prompt();
    char *line = read_line();
    char **args = parse_args(line);
    execute_command(args);
    free(args);
    free(line);
  }
  return 0;
}
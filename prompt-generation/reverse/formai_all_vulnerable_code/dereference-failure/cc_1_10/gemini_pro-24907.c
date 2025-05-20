//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

char* read_line() {
  char* line = malloc(MAX_LINE);
  if (!line) {
    perror("malloc");
    exit(1);
  }
  if (!fgets(line, MAX_LINE, stdin)) {
    perror("fgets");
    exit(1);
  }
  return line;
}

char** split_line(char* line) {
  char** args = malloc(sizeof(char*) * MAX_ARGS);
  if (!args) {
    perror("malloc");
    exit(1);
  }
  int i = 0;
  char* arg = strtok(line, " ");
  while (arg) {
    args[i++] = arg;
    arg = strtok(NULL, " ");
  }
  args[i] = NULL;
  return args;
}

int execute_command(char** args) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("execvp");
      exit(1);
    }
  } else {
    int status;
    waitpid(pid, &status, 0);
    return status;
  }
  return 0;
}

int main() {
  while (1) {
    printf("> ");
    char* line = read_line();
    char** args = split_line(line);
    execute_command(args);
    free(line);
    free(args);
  }
  return 0;
}
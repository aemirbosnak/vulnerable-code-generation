//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define MAX_ARGS 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line) {
  char **args = malloc(MAX_ARGS * sizeof(char *));
  int argc = 0;
  char *token;

  token = strtok(line, DELIM);
  while (token!= NULL) {
    args[argc++] = strdup(token);
    token = strtok(NULL, DELIM);
  }
  args[argc] = NULL;

  return args;
}

int execute_command(char **args) {
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      fprintf(stderr, "Error executing command: %s\n", args[0]);
      exit(1);
    }
  } else if (pid < 0) {
    fprintf(stderr, "Error forking process\n");
    exit(1);
  } else {
    waitpid(pid, &status, 0);
  }

  return WEXITSTATUS(status);
}

int main() {
  char input[MAX_LINE];
  char **args;
  int bg = 0;
  int status;

  printf("Welcome to the Basic Unix-like Shell!\n");

  while (1) {
    printf("> ");
    fgets(input, MAX_LINE, stdin);

    args = split_line(input);

    if (args[0] == NULL)
      continue;

    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "bg") == 0) {
      bg = 1;
    } else if (strcmp(args[0], "fg") == 0) {
      bg = 0;
    } else if (strcmp(args[0], "jobs") == 0) {
      system("jobs");
    } else {
      status = execute_command(args);
    }
  }

  return 0;
}
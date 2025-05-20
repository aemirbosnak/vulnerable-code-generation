//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main() {
  char line[MAX_LINE];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("jsh> ");
    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }

    if (strcmp(line, "exit\n") == 0) {
      break;
    }

    // Parse the line into arguments
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
      args[i] = token;
      i++;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for built-in commands
    if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) != 0) {
        perror("cd");
      }
      continue;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
      perror("fork");
      exit(1);
    } else if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror(args[0]);
      exit(1);
    } else {
      // Parent process
      wait(&status);
    }
  }

  return 0;
}
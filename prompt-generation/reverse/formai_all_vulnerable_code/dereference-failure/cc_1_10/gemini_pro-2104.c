//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define MAX_LINE_LENGTH 1024

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("myshell> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the input line into arguments.
    int argc = 0;
    char *arg = strtok(line, " ");
    while (arg != NULL && argc < MAX_ARGS) {
      args[argc++] = arg;
      arg = strtok(NULL, " ");
    }

    // Check for special commands.
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (argc != 2) {
        printf("Usage: cd <directory>\n");
        continue;
      }
      if (chdir(args[1]) != 0) {
        printf("Error: could not change directory to '%s'\n", args[1]);
        continue;
      }
    }

    // Fork a child process to execute the command.
    pid_t pid = fork();
    if (pid == 0) {
      // Child process.
      execvp(args[0], args);
      printf("Error: could not execute command '%s'\n", args[0]);
      exit(1);
    } else if (pid > 0) {
      // Parent process.
      waitpid(pid, &status, 0);
    } else {
      // Error.
      printf("Error: could not fork child process\n");
    }
  }

  return 0;
}
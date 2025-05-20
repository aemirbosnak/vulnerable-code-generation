//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the line into arguments
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    // Handle special commands
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) != 0) {
        perror("chdir");
      }
    } else {
      // Create a child process
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(1);
      } else if (pid > 0) {
        // Parent process
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
          printf("Exit status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
          printf("Terminated by signal %d\n", WTERMSIG(status));
        }
      } else {
        // Error creating child process
        perror("fork");
      }
    }
  }

  return 0;
}
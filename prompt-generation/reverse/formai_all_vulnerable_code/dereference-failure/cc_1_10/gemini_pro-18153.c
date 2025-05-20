//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE 100

int main(int argc, char *argv[]) {
  char line[MAX_LINE];
  char *args[MAX_ARGS];
  int status;
  int pid;

  while (1) {
    printf("entropy> ");
    fflush(stdout);

    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }

    // Parse the line into arguments
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Fork a child process
    pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else if (pid > 0) {
      // Parent process
      wait(&status);
    } else {
      // Error
      perror("fork");
      exit(EXIT_FAILURE);
    }
  }

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  char *args[512];
  char *line;
  size_t line_size = 512;
  int status;

  while (1) {
    printf("$ ");
    if (getline(&line, &line_size, stdin) == -1) {
      perror("getline");
      exit(1);
    }

    // Parse the line into arguments.
    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[argc++] = token;
      token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    // Check if the command is built-in.
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) == -1) {
        perror("chdir");
      }
    } else {
      // Fork a child process to execute the command.
      pid_t pid = fork();
      if (pid == -1) {
        perror("fork");
        exit(1);
      } else if (pid == 0) {
        // Child process.
        execvp(args[0], args);
        perror("execvp");
        exit(1);
      } else {
        // Parent process.
        waitpid(pid, &status, 0);
      }
    }
  }

  return 0;
}
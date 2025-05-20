//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

int main() {
  char *args[MAX_ARGS];
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1) {
    printf("> ");
    read = getline(&line, &len, stdin);
    if (read == -1) {
      printf("Error reading input\n");
      break;
    }

    // Tokenize the input line
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL && i < MAX_ARGS) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }

    // Handle the built-in commands
    if (strcmp(args[0], "exit") == 0) {
      return 0;
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) == -1) {
        printf("Error changing directory\n");
      }
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == -1) {
      printf("Error forking process\n");
      break;
    } else if (pid == 0) {
      // Child process
      execvp(args[0], args);
      printf("Error executing command\n");
      exit(1);
    } else {
      // Parent process
      int status;
      waitpid(pid, &status, 0);
    }
  }

  free(line);
  return 0;
}
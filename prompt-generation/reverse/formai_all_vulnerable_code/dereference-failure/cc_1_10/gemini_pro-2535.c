//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10

int main() {
  char *args[MAX_ARGS];
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  while (1) {
    printf("> ");
    nread = getline(&line, &len, stdin);
    if (nread == -1) {
      perror("getline");
      break;
    }

    // Tokenize the input line
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL && num_args < MAX_ARGS) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    // Check for special commands
    if (!strcmp(args[0], "exit")) {
      break;
    } else if (!strcmp(args[0], "cd")) {
      if (chdir(args[1]) == -1) {
        perror("chdir");
      }
    } else {
      // Execute the command
      pid_t pid = fork();
      if (pid == -1) {
        perror("fork");
      } else if (pid == 0) {
        // Child process
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
      } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
      }
    }
  }

  free(line);
  return 0;
}
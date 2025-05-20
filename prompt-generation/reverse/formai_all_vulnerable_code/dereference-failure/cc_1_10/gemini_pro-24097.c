//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

char *args[MAX_ARGS];
char line[MAX_LINE];

int main() {
  while (1) {
    printf("> ");
    fgets(line, sizeof(line), stdin);

    // Parse the input line into arguments
    int num_args = 0;
    char *token = strtok(line, " \n");
    while (token != NULL && num_args < MAX_ARGS) {
      args[num_args++] = strdup(token);
      token = strtok(NULL, " \n");
    }

    // Check for special commands
    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "cd") == 0) {
      if (num_args < 2) {
        fprintf(stderr, "cd: missing argument\n");
      } else {
        chdir(args[1]);
      }
      continue;
    }

    // Fork a child process to execute the command
    int pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      perror("execvp");
      exit(1);
    } else if (pid > 0) {
      // Parent process
      int status;
      waitpid(pid, &status, 0);
    } else {
      perror("fork");
    }

    // Free the allocated memory
    for (int i = 0; i < num_args; i++) {
      free(args[i]);
    }
  }

  return 0;
}
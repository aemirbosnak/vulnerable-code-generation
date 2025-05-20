//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

char *args[MAX_ARGS];
char line[MAX_LINE_LENGTH];

int main(void) {
  while (1) {
    printf("> ");
    fflush(stdout);

    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      printf("EOF\n");
      exit(0);
    }

    // Parse the line into arguments
    int num_args = 0;
    char *arg = strtok(line, " ");
    while (arg != NULL && num_args < MAX_ARGS) {
      args[num_args++] = arg;
      arg = strtok(NULL, " ");
    }

    // Check for special commands
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) != 0) {
        perror("chdir");
      }
      continue;
    }

    // Fork a child process
    pid_t pid = fork();
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
      // Fork failed
      perror("fork");
    }
  }

  return 0;
}
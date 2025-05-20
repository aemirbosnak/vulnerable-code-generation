//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  while (1) {
    printf("shell> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the command line
    int num_args = 0;
    char *ptr = strtok(line, " ");
    while (ptr != NULL && num_args < MAX_ARGS) {
      args[num_args++] = ptr;
      ptr = strtok(NULL, " ");
    }
    args[num_args] = NULL;

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      break;
    } else if (strcmp(args[0], "cd") == 0) {
      if (num_args < 2) {
        fprintf(stderr, "cd: missing argument\n");
      } else {
        if (chdir(args[1]) != 0) {
          fprintf(stderr, "cd: failed to change directory\n");
        }
      }
      continue;
    }

    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
      fprintf(stderr, "fork() failed\n");
      exit(EXIT_FAILURE);
    }

    if (pid == 0) {
      // Child process
      execvp(args[0], args);
      fprintf(stderr, "execvp() failed\n");
      exit(EXIT_FAILURE);
    } else {
      // Parent process
      wait(&status);
    }
  }

  return 0;
}
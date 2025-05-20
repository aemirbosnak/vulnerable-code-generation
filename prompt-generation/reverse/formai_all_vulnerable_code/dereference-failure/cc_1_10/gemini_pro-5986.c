//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARGS 64

char *args[MAX_ARGS];

int main(int argc, char *argv[])
{
  char line[MAX_LINE_LENGTH];
  int status;
  pid_t pid;

  while (1) {
    printf("Enter a command: ");
    fflush(stdout);
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      perror("fgets");
      exit(EXIT_FAILURE);
    }

    // Parse the line into arguments.
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL && num_args < MAX_ARGS) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    // Check for special commands.
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (chdir(args[1]) == -1) {
        perror("chdir");
      }
      continue;
    }

    // Fork a child process.
    pid = fork();
    if (pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
    } else if (pid == 0) {
      // Child process.
      execvp(args[0], args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else {
      // Parent process.
      wait(&status);
    }
  }

  return 0;
}
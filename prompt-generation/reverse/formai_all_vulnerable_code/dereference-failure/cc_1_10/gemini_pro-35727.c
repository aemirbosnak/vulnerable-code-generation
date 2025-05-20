//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

void execute_command(char *args[]) {
  pid_t pid;

  pid = fork();
  if (pid == 0) {
    // Child process
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  } else if (pid > 0) {
    // Parent process
    wait(NULL);
  } else {
    // Error
    perror("fork");
    exit(1);
  }
}

int main() {
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int num_args;

  while (1) {
    printf("osh> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the command line into arguments
    num_args = 0;
    args[num_args++] = strtok(line, " ");
    while ((args[num_args++] = strtok(NULL, " ")) != NULL) {
      if (num_args >= MAX_ARGS) {
        fprintf(stderr, "Too many arguments\n");
        break;
      }
    }

    // Check for special commands
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (args[1] == NULL) {
        fprintf(stderr, "cd: no directory specified\n");
      } else {
        if (chdir(args[1]) != 0) {
          perror("cd");
        }
      }
    } else {
      // Execute the command
      execute_command(args);
    }
  }

  return 0;
}
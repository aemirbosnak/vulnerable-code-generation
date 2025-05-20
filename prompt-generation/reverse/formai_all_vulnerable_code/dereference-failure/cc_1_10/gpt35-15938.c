//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_INPUT 100

int main() {
  char input[MAX_INPUT]; // User input
  char *args[MAX_ARGS]; // Arguments parsed from input
  int status; // Status of child process
  pid_t pid; // Process ID of child process

  while(1) {
    // Print prompt and get user input
    printf("myshell $ ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    // Parse input into arguments
    int arg_count = 0;
    char *arg = strtok(input, " ");
    while (arg != NULL && arg_count < MAX_ARGS) {
      args[arg_count] = arg;
      arg = strtok(NULL, " ");
      arg_count++;
    }
    args[arg_count] = NULL; // Set last argument to NULL for execvp()

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    }

    // Fork and execute command
    pid = fork();
    if (pid == 0) { // Child process
      execvp(args[0], args);
      fprintf(stderr, "Error: %s not found\n", args[0]);
      exit(1);
    } else if (pid > 0) { // Parent process
      waitpid(pid, &status, 0);
    } else { // Fork error
      fprintf(stderr, "Error: fork failed");
      exit(1);
    }
  }

  return 0;
}
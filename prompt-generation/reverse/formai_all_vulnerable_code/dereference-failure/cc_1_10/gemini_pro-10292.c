//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum number of arguments
#define MAX_ARGS 10

// Define the maximum size of a command line
#define MAX_LINE_SIZE 1024

// Main function
int main() {
  // Loop forever
  while (1) {
    // Print the prompt
    printf("myshell> ");

    // Get the command line
    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, stdin);

    // Parse the command line
    char *args[MAX_ARGS];
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[num_args++] = token;
      token = strtok(NULL, " ");
    }

    // Check for built-in commands
    if (strcmp(args[0], "exit") == 0) {
      // Exit the shell
      return 0;
    } else if (strcmp(args[0], "cd") == 0) {
      // Change the current directory
      if (num_args < 2) {
        // No directory specified, so go to home directory
        chdir(getenv("HOME"));
      } else {
        // Change to the specified directory
        chdir(args[1]);
      }
    } else {
      // Not a built-in command, so fork a new process
      pid_t pid = fork();
      if (pid == 0) {
        // Child process
        execvp(args[0], args);
        // If execvp returns, then there was an error
        perror("execvp");
        exit(1);
      } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
      }
    }
  }

  return 0;
}
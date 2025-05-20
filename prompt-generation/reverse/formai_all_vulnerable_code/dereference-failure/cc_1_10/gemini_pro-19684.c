//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
// C Basic Unix-like Shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the maximum length of a command line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of arguments in a command line
#define MAX_ARGS 16

// Main function
int main() {
  // Declare variables
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;

  // Loop until the user enters "exit"
  while (1) {
    // Prompt the user for input
    printf("osh> ");

    // Read the user's input
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the user's input into arguments
    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Check if the user entered "exit"
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid == 0) {
      // Child process
      execvp(args[0], args);

      // If execvp() fails, print an error message and exit
      perror("execvp");
      exit(1);
    } else {
      // Parent process
      wait(&status);
    }
  }

  return 0;
}
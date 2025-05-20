//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

// Define some constants
#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

// Define the main function
int main() {
  // Declare some variables
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int num_args;

  // Loop forever until the user enters "exit"
  while (1) {
    // Prompt the user for a command
    printf("myshell$ ");

    // Read the user's input
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Parse the user's input into arguments
    num_args = parse_args(line, args);

    // Check if the user entered "exit"
    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    // Fork a new process to execute the command
    pid_t pid = fork();

    if (pid == 0) {
      // This is the child process
      execvp(args[0], args);

      // If execvp() fails, print an error message and exit
      perror("execvp");
      exit(1);
    } else {
      // This is the parent process
      wait(NULL);
    }
  }

  // Return 0 to indicate that the program ran successfully
  return 0;
}

// Parse the user's input into arguments
int parse_args(char *line, char *args[]) {
  // Tokenize the line into arguments
  char *token = strtok(line, " ");

  // Store the arguments in the args array
  int i = 0;
  while (token != NULL) {
    args[i] = token;
    i++;
    token = strtok(NULL, " ");
  }

  // Return the number of arguments
  return i;
}
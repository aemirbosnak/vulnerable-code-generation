//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 1024

// Declare the main function
int main(int argc, char *argv[]) {
  // Declare the necessary variables
  char line[MAX_LINE_LENGTH];
  char *args[MAX_ARGS];
  int status;
  int i;

  // Create a loop to get user input
  while (1) {
    // Prompt the user for input
    printf("jsh> ");

    // Get the user input
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the input
    line[strlen(line) - 1] = '\0';

    // Parse the input into arguments
    i = 0;
    args[i] = strtok(line, " ");
    while (args[i] != NULL) {
      i++;
      args[i] = strtok(NULL, " ");
    }

    // Check if the user entered the exit command
    if (strcmp(args[0], "exit") == 0) {
      // Exit the shell
      exit(0);
    }

    // Create a child process to run the command
    pid_t pid = fork();

    // Check if the fork failed
    if (pid == -1) {
      // Print an error message
      perror("fork");

      // Exit the shell
      exit(1);
    }

    // Check if the child process is the child
    if (pid == 0) {
      // Execute the command
      execvp(args[0], args);

      // Check if the execvp failed
      perror("execvp");

      // Exit the child process
      exit(1);
    }

    // Wait for the child process to finish
    wait(&status);

    // Check if the child process exited with an error
    if (WIFEXITED(status)) {
      // Get the exit status of the child process
      int exit_status = WEXITSTATUS(status);

      // Print the exit status of the child process
      printf("Exit status: %d\n", exit_status);
    }
  }

  // Return 0 to indicate that the program ran successfully
  return 0;
}
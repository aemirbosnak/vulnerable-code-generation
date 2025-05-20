//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: funny
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *args[100]; // Assuming a maximum of 100 arguments
  char line[1024]; // Assuming a maximum of 1024 characters per line

  // Print a funny welcome message
  printf("Welcome to the Not-So-Serious Shell!\n");

  // Loop forever until the user enters "exit"
  while (1) {
    // Prompt the user for input
    printf("\n>> ");

    // Get the user's input
    fgets(line, sizeof(line), stdin);

    // Parse the user's input into arguments
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      args[num_args] = token;
      num_args++;
      token = strtok(NULL, " ");
    }

    // Check if the user entered "exit"
    if (strcmp(args[0], "exit") == 0) {
      // Print a funny goodbye message
      printf("Later, dude!\n");
      exit(0);
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if (pid < 0) {
      // Fork failed, print an error message
      perror("Fork failed");
      exit(1);
    } else if (pid == 0) {
      // Child process, execute the command
      execvp(args[0], args);

      // If execvp fails, print an error message and exit
      perror("Execvp failed");
      exit(1);
    } else {
      // Parent process, wait for the child process to finish
      wait(NULL);
    }
  }

  return 0;
}
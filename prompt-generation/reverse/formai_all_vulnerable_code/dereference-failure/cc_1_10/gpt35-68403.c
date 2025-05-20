//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command

int main(void) {
  char *args[MAX_LINE/2+1]; // Command line arguments
  int should_run = 1; // Flag to determine when to exit program

  while (should_run) {
    printf("osh> ");
    fflush(stdout);

    char command[MAX_LINE];
    fgets(command, MAX_LINE, stdin); // Read user input

    int num_args = 0;
    char *token = strtok(command, " \n"); // Tokenize command
    while (token != NULL) {
      args[num_args++] = token;
      token = strtok(NULL, " \n");
    }
    args[num_args] = NULL; // Null-terminate array

    if (strcmp(args[0], "exit") == 0) {
      should_run = 0; // Exit program
    } else {
      pid_t pid = fork(); // Create child process

      if (pid < 0) {
        printf("Failed to create child process.\n");
        exit(1);
      } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) < 0) { // Execute command
          printf("Invalid command.\n");
          exit(1);
        }
      } else {
        // Parent process
        wait(NULL); // Wait for child to complete
      }
    }
  }

  return 0;
}
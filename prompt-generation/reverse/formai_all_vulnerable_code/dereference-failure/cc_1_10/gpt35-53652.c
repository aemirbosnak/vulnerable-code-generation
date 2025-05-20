//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGUMENTS 10 // Maximum number of arguments
#define MAX_LINE_LENGTH 50 // Maximum length of input line

char **get_command(char *input) {
  char **command = (char **)malloc(MAX_ARGUMENTS * sizeof(char *)); // Allocate memory for command
  char *argument; // Current argument
  int count = 0; // Argument counter

  argument = strtok(input, " \n"); // Get first argument

  while (argument != NULL) { // Iterate through all arguments
    command[count] = argument; // Add argument to command
    count++; // Increment argument counter
    argument = strtok(NULL, " \n"); // Get next argument
  }

  command[count] = NULL; // Set last argument to NULL
  return command; // Return command
}

int main() {
  char input[MAX_LINE_LENGTH]; // Input line from user
  pid_t pid; // Process ID
  int status; // Process status

  while (1) { // Loop until user exits
    printf(">> "); // Prompt user for input
    fgets(input, MAX_LINE_LENGTH, stdin); // Get input from user

    if (strcmp(input, "exit\n") == 0) { // Check for exit command
      break; // Exit program
    }

    pid = fork(); // Create child process

    if (pid < 0) { // Check for fork error
      printf("Error: Fork failed.\n");
    } else if (pid == 0) { // Child process
      char **command = get_command(input); // Get command

      if (execvp(command[0], command) < 0) { // Execute command
        printf("Error: Failed to execute command.\n");
      }

      exit(0); // Exit child process
    } else { // Parent process
      waitpid(pid, &status, 0); // Wait for child process

      if (WIFEXITED(status)) { // Check if child process exited normally
        printf("Exited with status %d.\n", WEXITSTATUS(status));
      }
    }
  }

  return 0;
}
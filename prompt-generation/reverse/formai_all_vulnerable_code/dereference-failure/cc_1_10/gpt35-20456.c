//FormAI DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Set the maximum buffer size for reading from standard input (keyboard)
#define MAX_BUFFER_SIZE 1024

int main() {
  char buffer[MAX_BUFFER_SIZE];
  char input[MAX_BUFFER_SIZE];
  int num_commands = 0;
  int running = 1;

  // Loop until the user types "exit"
  while (running) {
    // Print the command prompt and read the user's input
    printf(">> ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Remove the newline character at the end of the input
    input[strcspn(input, "\n")] = 0;

    // Count the number of commands entered
    num_commands++;

    // Split the input into tokens using the space as a delimiter
    char *token = strtok(input, " ");

    // Check if the command is "exit"
    if (strcmp(token, "exit") == 0) {
      printf("Goodbye!\n");
      running = 0; // Set the running flag to false to exit the loop
    }
    // Check if the command is "help"
    else if (strcmp(token, "help") == 0) {
      printf("Available commands:\n");
      printf("  exit - Quit the program\n");
      printf("  help - Display this list of commands\n");
      printf("  info - Display system information\n");
      printf("  status - Display the status of running services\n");
    }
    // Check if the command is "info"
    else if (strcmp(token, "info") == 0) {
      printf("System Information:\n");
      printf("  Number of commands entered: %d\n", num_commands);
      printf("  Size of input buffer: %d\n", MAX_BUFFER_SIZE);
    }
    // Check if the command is "status"
    else if (strcmp(token, "status") == 0) {
      printf("Service Status:\n");
      printf("  httpd - Running\n");
      printf("  ssh - Running\n");
      printf("  ftp - Stopped\n");
      printf("  nfs - Running\n");
    }
    // Check if the command is invalid
    else {
      printf("Invalid command. Type 'help' for a list of available commands.\n");
    }
  }

  return 0; // Exit the program with no errors
}
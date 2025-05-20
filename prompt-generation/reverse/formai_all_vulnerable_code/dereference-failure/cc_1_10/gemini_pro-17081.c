//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
// Hello, world in C!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Our own custom shell function.
int our_shell(char *input) {
  char *argv[100]; // Array of arguments.
  char *delim = " "; // Delimiter for splitting the input.
  int argc = 0; // Number of arguments.
  char *token = strtok(input, delim); // Get the first argument.
  while (token != NULL) {
    argv[argc++] = token; // Add the argument to the array.
    token = strtok(NULL, delim); // Get the next argument.
  }
  argv[argc] = NULL; // Null-terminate the array of arguments.
  
  // Check if the user wants to exit the shell.
  if (strcmp(argv[0], "exit") == 0) {
    return 0; 
  }

  // Execute the command.
  if (execvp(argv[0], argv) == -1) {
    perror("Error executing command"); // Print an error message if the command fails.
    return 1; // Return an error code.
  }
  
  // We should never reach this point.
  return 0;
}

// Main function.
int main() {
  char input[100]; // Buffer for user input.
  
  // Welcome message.
  printf("Welcome to our custom shell!\n");
  printf("Type 'exit' to quit the shell.\n");
  
  // Main loop.
  while (1) {
    printf("> "); // Print the prompt.
    fgets(input, 100, stdin); // Get user input.
    
    // Remove the newline character from the input.
    input[strlen(input) - 1] = '\0';
    
    // Call the shell function.
    if (our_shell(input) == 0) {
      break; // Exit the shell if the user wants to exit.
    }
  }
  
  // Goodbye message.
  printf("Goodbye!\n");
  
  return 0;
}
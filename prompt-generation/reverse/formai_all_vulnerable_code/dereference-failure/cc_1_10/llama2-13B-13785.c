//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_LENGTH 1024
#define MAX_ATTEMPTS 5

// Declare a global variable to store the error message
char error_message[MAX_LENGTH];

// Function to handle errors
void handle_error(const char* message) {
  // Print the error message in red
  fprintf(stderr, "\033[31m%s\033[0m", message);
  // Increment the number of attempts
  int attempt = 0;
  while (attempt < MAX_ATTEMPTS) {
    // Get the user's input again
    char input = getchar();
    // If the input is a valid character, break out of the loop
    if (input != EOF && input != '\n') break;
    // If the input is a newline, increment the attempt count
    else attempt++;
  }
  // If the user has reached the maximum number of attempts, exit the program
  if (attempt == MAX_ATTEMPTS) {
    fprintf(stderr, "\033[31mError: Maximum number of attempts reached! Exiting...\033[0m\n");
    exit(1);
  }
  // Otherwise, clear the error message and continue executing
  else {
    memset(error_message, 0, MAX_LENGTH);
  }
}

int main() {
  // Declare a variable to store the user's input
  char input;

  // Prompt the user to enter a string
  printf("Enter a string: ");

  // Read the user's input
  input = getchar();

  // Check if the input is a valid string
  if (input == EOF || input == '\n') {
    // If the input is not a valid string, print an error message
    strcpy(error_message, "Error: Invalid input. Please enter a string again.");
    handle_error(error_message);
  }

  // Check if the input is too long
  else if (strlen(input) > MAX_LENGTH) {
    // If the input is too long, print an error message
    strcpy(error_message, "Error: Input too long. Please enter a shorter string.");
    handle_error(error_message);
  }

  // Otherwise, print a success message
  else {
    printf("Success! You entered: %s\n", input);
  }

  return 0;
}
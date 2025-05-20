//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_NUMBER_OF_ARGS 64

// Function to handle errors
void handle_error(const char *msg) {
  printf("Error: %s\n", msg);
  if (errno != 0) {
    printf("Error code: %d\n", errno);
  }
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  // Check if the user provided too many arguments
  if (argc > MAX_NUMBER_OF_ARGS) {
    handle_error("Too many arguments");
  }

  // Check if the input length is too long
  char input[MAX_INPUT_LENGTH];
  if (scanf("%s", input) != 1) {
    handle_error("Input length exceeds maximum limit");
  }

  // Check if the input is a valid integer
  int input_int;
  if (sscanf(input, "%d", &input_int) != 1) {
    handle_error("Invalid input");
  }

  // Check if the input is negative
  if (input_int < 0) {
    handle_error("Input must be non-negative");
  }

  // Perform some computation
  int result = input_int * 2;

  // Check if the computation failed
  if (result == -1) {
    handle_error("Computation failed");
  }

  // Print the result
  printf("Result: %d\n", result);

  return 0;
}
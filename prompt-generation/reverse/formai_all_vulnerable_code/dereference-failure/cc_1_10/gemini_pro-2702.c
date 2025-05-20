//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the maximum number of tokens that can be parsed from the input string.
#define MAX_TOKENS 100

// Define the maximum length of a token.
#define MAX_TOKEN_LENGTH 64

// Define the delimiter that separates tokens in the input string.
#define DELIMITER ','

// Define the number of performance-critical components.
#define NUM_COMPONENTS 10

// Define the structure of a performance-critical component.
typedef struct {
  char name[MAX_TOKEN_LENGTH];
  uint64_t value;
} PerformanceCriticalComponent;

// Define the array of performance-critical components.
PerformanceCriticalComponent components[NUM_COMPONENTS];

// Define the function to parse the input string and populate the array of performance-critical components.
int parse_input(char *input) {
  // Initialize the number of tokens to zero.
  int num_tokens = 0;

  // Split the input string into tokens.
  char *token = strtok(input, DELIMITER);
  while (token != NULL && num_tokens < MAX_TOKENS) {
    // Copy the token into the array of performance-critical components.
    strcpy(components[num_tokens].name, token);

    // Convert the token to an integer and store it in the array of performance-critical components.
    components[num_tokens].value = atoi(token);

    // Increment the number of tokens.
    num_tokens++;

    // Get the next token.
    token = strtok(NULL, DELIMITER);
  }

  // Return the number of tokens.
  return num_tokens;
}

// Define the function to print the array of performance-critical components.
void print_components(int num_components) {
  for (int i = 0; i < num_components; i++) {
    printf("%s: %llu\n", components[i].name, components[i].value);
  }
}

// Define the main function.
int main(int argc, char **argv) {
  // Check if the user has provided an input string.
  if (argc != 2) {
    printf("Usage: %s <input string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the input string and populate the array of performance-critical components.
  int num_components = parse_input(argv[1]);

  // Print the array of performance-critical components.
  print_components(num_components);

  return EXIT_SUCCESS;
}
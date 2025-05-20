//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the buffer
#define MAX_BUFFER_SIZE 1024

// Define the maximum number of tokens
#define MAX_TOKENS 100

// Define the maximum length of a token
#define MAX_TOKEN_LENGTH 100

// Define the delimiter characters
#define DELIMITERS " \t\n"

// Define the function to tokenize a string
char **tokenize(char *str) {
  // Allocate memory for the tokens
  char **tokens = malloc(MAX_TOKENS * sizeof(char *));

  // Initialize the number of tokens
  int num_tokens = 0;

  // Get the first token
  char *token = strtok(str, DELIMITERS);

  // While there are more tokens
  while (token) {
    // Allocate memory for the token
    tokens[num_tokens] = malloc(MAX_TOKEN_LENGTH * sizeof(char));

    // Copy the token into the array
    strcpy(tokens[num_tokens], token);

    // Increment the number of tokens
    num_tokens++;

    // Get the next token
    token = strtok(NULL, DELIMITERS);
  }

  // Return the tokens
  return tokens;
}

// Define the function to free the tokens
void free_tokens(char **tokens, int num_tokens) {
  // Free each token
  for (int i = 0; i < num_tokens; i++) {
    free(tokens[i]);
  }

  // Free the tokens array
  free(tokens);
}

// Define the main function
int main() {
  // Get the input string
  char str[MAX_BUFFER_SIZE];
  printf("Enter a string: ");
  fgets(str, MAX_BUFFER_SIZE, stdin);

  // Tokenize the string
  char **tokens = tokenize(str);

  // Print the tokens
  printf("Tokens:\n");
  for (int i = 0; i < MAX_TOKENS; i++) {
    if (tokens[i]) {
      printf("%s\n", tokens[i]);
    }
  }

  // Free the tokens
  free_tokens(tokens, MAX_TOKENS);

  return 0;
}
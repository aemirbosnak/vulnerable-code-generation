//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the maximum number of tokens in the input string
#define MAX_TOKENS 100

// Define the maximum size of a token
#define MAX_TOKEN_SIZE 100

// Define the delimiter used to tokenize the input string
#define DELIMITER " "

// Get the next token from the input string
char *get_next_token(char **input_string) {
  char *token;

  // Advance the input string pointer to the next character
  *input_string = strchr(*input_string, DELIMITER[0]) + 1;

  // If the input string pointer is NULL, then there are no more tokens
  if (*input_string == NULL) {
    return NULL;
  }

  // Find the end of the token
  token = strchr(*input_string, DELIMITER[0]);

  // If the token is NULL, then the token is the rest of the input string
  if (token == NULL) {
    token = *input_string + strlen(*input_string);
  }

  // Terminate the token
  *token = '\0';

  // Return the token
  return *input_string;
}

// Tokenize the input string
char **tokenize(char *input_string, int *num_tokens) {
  char **tokens;
  char *token;
  int i;

  // Allocate memory for the tokens
  tokens = malloc(MAX_TOKENS * sizeof(char *));

  // Tokenize the input string
  i = 0;
  while ((token = get_next_token(&input_string)) != NULL) {
    tokens[i++] = token;
  }

  // Store the number of tokens
  *num_tokens = i;

  // Return the tokens
  return tokens;
}

// Free the memory allocated for the tokens
void free_tokens(char **tokens, int num_tokens) {
  int i;

  // Free the memory allocated for each token
  for (i = 0; i < num_tokens; i++) {
    free(tokens[i]);
  }

  // Free the memory allocated for the array of tokens
  free(tokens);
}

// Main function
int main(int argc, char *argv[]) {
  char input_string[MAX_INPUT_SIZE];
  char **tokens;
  int num_tokens;
  int i;

  // Get the input string from the user
  printf("Enter a string: ");
  fgets(input_string, MAX_INPUT_SIZE, stdin);

  // Tokenize the input string
  tokens = tokenize(input_string, &num_tokens);

  // Print the tokens
  printf("Tokens: ");
  for (i = 0; i < num_tokens; i++) {
    printf("%s ", tokens[i]);
  }

  printf("\n");

  // Free the memory allocated for the tokens
  free_tokens(tokens, num_tokens);

  return 0;
}
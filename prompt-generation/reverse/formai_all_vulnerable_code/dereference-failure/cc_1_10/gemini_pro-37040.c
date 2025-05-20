//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
  // Open the input file
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  // Read the input file into a string
  char *input = malloc(MAX_LEN);
  if (input == NULL) {
    perror("Error allocating memory for input");
    return EXIT_FAILURE;
  }
  size_t len = fread(input, 1, MAX_LEN, fp);
  if (len == 0) {
    perror("Error reading input file");
    return EXIT_FAILURE;
  }

  // Close the input file
  fclose(fp);

  // Tokenize the input string
  char *tokens[MAX_LEN];
  int num_tokens = 0;
  char *token = strtok(input, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Print the tokens
  for (int i = 0; i < num_tokens; i++) {
    printf("%s\n", tokens[i]);
  }

  // Free the allocated memory
  free(input);
  for (int i = 0; i < num_tokens; i++) {
    free(tokens[i]);
  }

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: creative
// The Grand C Syntax Symphony

#include <stdio.h>
#include <stdlib.h>

// A crescendo of declarations
int main(int argc, char *argv[]);
void parse(char *input);

// The overture: main()
int main(int argc, char *argv[]) {
  // Allegro: Check for input
  if (argc != 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Andante: Open the input file
  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  // The main performance: Parse the file
  char *input = malloc(1024);
  while (fgets(input, 1024, file) != NULL) {
    parse(input);
  }

  // Coda: Close the file
  fclose(file);
  free(input);
  return EXIT_SUCCESS;
}

// The heart of the symphony: parse()
void parse(char *input) {
  // Allegro: Tokenize the input
  char *token = strtok(input, " \n\t");
  while (token != NULL) {
    // Andante: Identify the token type
    if (strcmp(token, "int") == 0) {
      // Handle int declarations
      printf("Found int declaration: %s\n", token);
    } else if (strcmp(token, "char") == 0) {
      // Handle char declarations
      printf("Found char declaration: %s\n", token);
    } else if (strcmp(token, "float") == 0) {
      // Handle float declarations
      printf("Found float declaration: %s\n", token);
    } else if (token[0] == '"') {
      // Handle string literals
      printf("Found string literal: %s\n", token);
    } else {
      // Handle identifiers and other tokens
      printf("Found token: %s\n", token);
    }

    // Get the next token
    token = strtok(NULL, " \n\t");
  }
}
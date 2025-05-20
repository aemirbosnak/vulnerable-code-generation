//GEMINI-pro DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function, which is the entry point of the program.
int main(int argc, char *argv[]) {
  // Check if the user has provided a filename.
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // Open the file for reading.
  FILE *fp = fopen(argv[1], "r");

  // Check if the file was opened successfully.
  if (fp == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  // Read the file contents into a buffer.
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  char *buffer = malloc(size + 1);
  fread(buffer, 1, size, fp);
  buffer[size] = '\0';

  // Close the file.
  fclose(fp);

  // Tokenize the file contents into words.
  char *token;
  char *tokens[100];
  int num_tokens = 0;
  token = strtok(buffer, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Print the number of words in the file.
  printf("The file %s contains %d words.\n", argv[1], num_tokens);

  // Print the first 10 words in the file.
  printf("The first 10 words in the file are:\n");
  for (int i = 0; i < 10 && i < num_tokens; i++) {
    printf("%s\n", tokens[i]);
  }

  // Free the allocated memory.
  free(buffer);

  return 0;
}
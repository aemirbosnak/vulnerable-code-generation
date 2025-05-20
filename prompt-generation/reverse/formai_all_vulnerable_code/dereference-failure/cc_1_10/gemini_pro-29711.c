//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <key> <input file> <output file>\n", argv[0]);
    return 1;
  }

  // Get the key
  char *key = argv[1];
  if (strlen(key) != KEY_SIZE) {
    printf("Error: Key must be %d characters long.\n", KEY_SIZE);
    return 1;
  }

  // Get the input and output files
  FILE *input = fopen(argv[2], "rb");
  if (input == NULL) {
    printf("Error: Cannot open input file.\n");
    return 1;
  }
  FILE *output = fopen(argv[3], "wb");
  if (output == NULL) {
    printf("Error: Cannot open output file.\n");
    return 1;
  }

  // Get the file size
  fseek(input, 0, SEEK_END);
  long size = ftell(input);
  rewind(input);

  // Allocate a buffer for the file
  char *buffer = malloc(size);
  if (buffer == NULL) {
    printf("Error: Cannot allocate memory for buffer.\n");
    return 1;
  }

  // Read the file into the buffer
  fread(buffer, 1, size, input);

  // Encrypt the file
  for (long i = 0; i < size; i++) {
    buffer[i] ^= key[i % KEY_SIZE];
  }

  // Write the encrypted file to the output file
  fwrite(buffer, 1, size, output);

  // Free the buffer
  free(buffer);

  // Close the files
  fclose(input);
  fclose(output);

  return 0;
}
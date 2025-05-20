//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_SIZE 1024

// Define the compression and decompression functions
char* compress(char* input);
char* decompress(char* input);

// Main function
int main() {
  // Get the input string from the user
  char input[MAX_SIZE];
  printf("Enter the string to be compressed: ");
  gets(input);

  // Compress the input string
  char* compressed = compress(input);
  printf("\nCompressed string: %s\n", compressed);

  // Decompress the compressed string
  char* decompressed = decompress(compressed);
  printf("\nDecompressed string: %s\n", decompressed);

  // Free the memory allocated for the compressed and decompressed strings
  free(compressed);
  free(decompressed);

  return 0;
}

// Function to compress the input string
char* compress(char* input) {
  // Get the length of the input string
  int length = strlen(input);

  // Allocate memory for the compressed string
  char* compressed = malloc(length + 1);

  // Initialize the compressed string
  compressed[0] = '\0';

  // Compress the input string
  int count = 1;
  for (int i = 0; i < length; i++) {
    // If the current character is the same as the previous character, increment the count
    if (input[i] == input[i + 1]) {
      count++;
    }
    // If the current character is different from the previous character, add the count and the character to the compressed string
    else {
      char buffer[10];
      sprintf(buffer, "%d%c", count, input[i]);
      strcat(compressed, buffer);
      count = 1;
    }
  }

  // Return the compressed string
  return compressed;
}

// Function to decompress the compressed string
char* decompress(char* input) {
  // Get the length of the compressed string
  int length = strlen(input);

  // Allocate memory for the decompressed string
  char* decompressed = malloc(length * 2 + 1);

  // Initialize the decompressed string
  decompressed[0] = '\0';

  // Decompress the compressed string
  int count = 0;
  int i = 0;
  while (i < length) {
    // Get the count from the compressed string
    while (input[i] >= '0' && input[i] <= '9') {
      count = count * 10 + input[i] - '0';
      i++;
    }

    // Get the character from the compressed string
    char character = input[i];
    i++;

    // Repeat the character count times in the decompressed string
    for (int j = 0; j < count; j++) {
      decompressed[strlen(decompressed)] = character;
    }

    // Reset the count
    count = 0;
  }

  // Return the decompressed string
  return decompressed;
}
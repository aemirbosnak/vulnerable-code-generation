//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
char *compress(char *str) {
  // Initialize the compressed string
  char *compressed = malloc(strlen(str) + 1);
  int compressed_index = 0;

  // Iterate over the input string
  int i = 0;
  while (str[i] != '\0') {
    // Count the number of consecutive occurrences of the current character
    int count = 1;
    while (str[i] == str[i + 1]) {
      count++;
      i++;
    }

    // Append the character and its count to the compressed string
    compressed[compressed_index++] = str[i];
    compressed[compressed_index++] = count + '0';

    // Move to the next character in the input string
    i++;
  }

  // Terminate the compressed string
  compressed[compressed_index] = '\0';

  // Return the compressed string
  return compressed;
}

// Function to decompress a string compressed using run-length encoding
char *decompress(char *compressed) {
  // Initialize the decompressed string
  char *decompressed = malloc(strlen(compressed) * 2 + 1);
  int decompressed_index = 0;

  // Iterate over the compressed string
  int i = 0;
  while (compressed[i] != '\0') {
    // Get the character to be repeated
    char character = compressed[i++];

    // Get the number of times the character should be repeated
    int count = compressed[i++] - '0';

    // Append the character to the decompressed string the specified number of times
    for (int j = 0; j < count; j++) {
      decompressed[decompressed_index++] = character;
    }
  }

  // Terminate the decompressed string
  decompressed[decompressed_index] = '\0';

  // Return the decompressed string
  return decompressed;
}

// Main function
int main() {
  // Get the input string from the user
  char input[100];
  printf("Enter a string to compress: ");
  gets(input);

  // Compress the input string
  char *compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string
  char *decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(compressed);
  free(decompressed);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style compression algorithm

// Compress a string using the Linus Torvalds style compression algorithm
char *compress(char *str) {
  // Allocate memory for the compressed string
  char *compressed = malloc(strlen(str) + 1);

  // Initialize the compressed string
  compressed[0] = '\0';

  // Iterate over the input string
  int i = 0;
  while (str[i] != '\0') {
    // Get the current character
    char c = str[i];

    // If the current character is the same as the previous character,
    // increment the count
    if (compressed[strlen(compressed) - 1] == c) {
      compressed[strlen(compressed) - 1]++;
    }
    // Otherwise, append the current character to the compressed string
    else {
      strcat(compressed, &c);
    }

    // Increment the index
    i++;
  }

  // Return the compressed string
  return compressed;
}

// Decompress a string using the Linus Torvalds style compression algorithm
char *decompress(char *str) {
  // Allocate memory for the decompressed string
  char *decompressed = malloc(strlen(str) + 1);

  // Initialize the decompressed string
  decompressed[0] = '\0';

  // Iterate over the compressed string
  int i = 0;
  while (str[i] != '\0') {
    // Get the current character
    char c = str[i];

    // If the current character is a number, repeat the previous character
    // that many times
    if (c >= '0' && c <= '9') {
      int count = c - '0';
      for (int j = 0; j < count; j++) {
        strcat(decompressed, &str[i - 1]);
      }
    }
    // Otherwise, append the current character to the decompressed string
    else {
      strcat(decompressed, &c);
    }

    // Increment the index
    i++;
  }

  // Return the decompressed string
  return decompressed;
}

// Print the usage of the program
void usage() {
  printf("Usage: compress [string]\n");
  printf("Example: compress \"Hello, world!\"\n");
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a string
  if (argc != 2) {
    usage();
    return 1;
  }

  // Compress the string
  char *compressed = compress(argv[1]);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the string
  char *decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the memory allocated for the compressed and decompressed strings
  free(compressed);
  free(decompressed);

  return 0;
}
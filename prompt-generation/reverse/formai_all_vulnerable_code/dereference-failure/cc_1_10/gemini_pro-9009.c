//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
char *compress(char *str) {
  // Allocate memory for the compressed string
  char *compressed = malloc(strlen(str) + 1);

  // Initialize the compressed string
  compressed[0] = '\0';

  // Keep track of the current character and its count
  char current = str[0];
  int count = 1;

  // Iterate over the input string
  for (int i = 1; str[i] != '\0'; i++) {
    // If the current character is the same as the previous character, increment the count
    if (str[i] == current) {
      count++;
    }
    // If the current character is different from the previous character, append the count and character to the compressed string and reset the count
    else {
      sprintf(compressed, "%s%d%c", compressed, count, current);
      current = str[i];
      count = 1;
    }
  }

  // Append the count and character for the last character
  sprintf(compressed, "%s%d%c", compressed, count, current);

  // Return the compressed string
  return compressed;
}

// Function to decompress a string using run-length encoding
char *decompress(char *str) {
  // Allocate memory for the decompressed string
  char *decompressed = malloc(strlen(str) * 2);

  // Initialize the decompressed string
  decompressed[0] = '\0';

  // Keep track of the current character and its count
  char current;
  int count;

  // Iterate over the compressed string
  for (int i = 0; str[i] != '\0'; i++) {
    // If the current character is a digit, parse the count
    if (isdigit(str[i])) {
      count = atoi(&str[i]);
      i++;
    }
    // If the current character is not a digit, it is the current character
    else {
      current = str[i];
    }

    // Append the current character to the decompressed string the specified number of times
    for (int j = 0; j < count; j++) {
      strcat(decompressed, &current);
    }
  }

  // Return the decompressed string
  return decompressed;
}

int main() {
  // Get the input string from the user
  char *input = malloc(100);
  printf("Enter a string to compress: ");
  scanf("%s", input);

  // Compress the input string
  char *compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string
  char *decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(input);
  free(compressed);
  free(decompressed);

  return 0;
}
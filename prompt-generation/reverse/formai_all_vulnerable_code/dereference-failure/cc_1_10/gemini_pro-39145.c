//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) ((a)<(b)?(a):(b))

// The surrealist compression algorithm
char* compress(char* input) {
  // Create a new string to store the compressed data
  char* output = malloc(strlen(input) / 2 + 1);

  // Initialize the output string
  int j = 0;

  // Iterate over the input string
  for (int i = 0; input[i] != '\0'; i++) {
    // If the current character is the same as the previous character, increment the counter
    if (input[i] == input[i - 1]) {
      j++;
    } else {
      // If the current character is different from the previous character, write the counter and the character to the output string
      output[j++] = j;
      output[j++] = input[i];

      // Reset the counter
      j = 0;
    }
  }

  // Terminate the output string
  output[j] = '\0';

  // Return the compressed string
  return output;
}

// The surrealist decompression algorithm
char* decompress(char* input) {
  // Create a new string to store the decompressed data
  char* output = malloc(strlen(input) * 2 + 1);

  // Initialize the output string
  int j = 0;

  // Iterate over the input string
  for (int i = 0; input[i] != '\0'; i += 2) {
    // Write the character to the output string the number of times specified by the counter
    for (int k = 0; k < input[i]; k++) {
      output[j++] = input[i + 1];
    }
  }

  // Terminate the output string
  output[j] = '\0';

  // Return the decompressed string
  return output;
}

int main() {
  // Get the input string from the user
  char* input = malloc(100);
  printf("Enter the input string: ");
  scanf("%s", input);

  // Compress the input string
  char* compressed = compress(input);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string
  char* decompressed = decompress(compressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the memory allocated for the strings
  free(input);
  free(compressed);
  free(decompressed);

  return 0;
}
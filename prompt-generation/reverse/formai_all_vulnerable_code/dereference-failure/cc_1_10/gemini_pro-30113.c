//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the compressed string
#define MAX_COMPRESSED_SIZE (MAX_INPUT_SIZE + (MAX_INPUT_SIZE / 10))

// Function to compress a string using a simple run-length encoding algorithm
char *compress_string(char *input_string) {
  // Allocate memory for the compressed string
  char *compressed_string = malloc(MAX_COMPRESSED_SIZE);

  // Initialize the compressed string to empty
  compressed_string[0] = '\0';

  // Initialize the current character and the count of consecutive occurrences
  char current_char = input_string[0];
  int count = 1;

  // Iterate over the input string
  for (int i = 1; i < strlen(input_string); i++) {
    // If the current character is the same as the previous character, increment the count
    if (input_string[i] == current_char) {
      count++;
    } else {
      // If the current character is different from the previous character, append the count and the character to the compressed string
      sprintf(compressed_string, "%s%d%c", compressed_string, count, current_char);

      // Reset the count and update the current character
      count = 1;
      current_char = input_string[i];
    }
  }

  // Append the count and the character to the compressed string
  sprintf(compressed_string, "%s%d%c", compressed_string, count, current_char);

  // Return the compressed string
  return compressed_string;
}

// Function to decompress a string using the same run-length encoding algorithm
char *decompress_string(char *compressed_string) {
  // Allocate memory for the decompressed string
  char *decompressed_string = malloc(MAX_INPUT_SIZE);

  // Initialize the decompressed string to empty
  decompressed_string[0] = '\0';

  // Initialize the current character and the count of consecutive occurrences
  char current_char;
  int count;

  // Iterate over the compressed string
  for (int i = 0; i < strlen(compressed_string); i++) {
    // If the current character is a digit, parse the count
    if (isdigit(compressed_string[i])) {
      count = atoi(&compressed_string[i]);

      // Advance the pointer to the next character
      i++;
    } else {
      // If the current character is not a digit, it is the character to be repeated
      current_char = compressed_string[i];

      // Append the character to the decompressed string the specified number of times
      for (int j = 0; j < count; j++) {
        sprintf(decompressed_string, "%s%c", decompressed_string, current_char);
      }
    }
  }

  // Return the decompressed string
  return decompressed_string;
}

// Main function
int main() {
  // Get the input string from the user
  char input_string[MAX_INPUT_SIZE];
  printf("Enter the string to be compressed: ");
  scanf("%s", input_string);

  // Compress the string
  char *compressed_string = compress_string(input_string);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed_string);

  // Decompress the string
  char *decompressed_string = decompress_string(compressed_string);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed_string);

  // Free the allocated memory
  free(compressed_string);
  free(decompressed_string);

  return 0;
}
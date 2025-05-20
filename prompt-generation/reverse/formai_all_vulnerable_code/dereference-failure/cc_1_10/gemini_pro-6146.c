//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output buffers
#define MAX_BUF_SIZE 1024

// Define the compression ratio
#define COMPRESSION_RATIO 0.5

// Define the number of iterations for the compression algorithm
#define NUM_ITERATIONS 10

// Define the function to compress the input buffer
char *compress(char *input, int input_size) {
  // Allocate memory for the output buffer
  char *output = malloc(MAX_BUF_SIZE);

  // Initialize the output buffer
  memset(output, 0, MAX_BUF_SIZE);

  // Initialize the compression ratio
  float compression_ratio = COMPRESSION_RATIO;

  // Iterate over the input buffer
  for (int i = 0; i < input_size; i++) {
    // Add the current character to the output buffer
    output[i] = input[i];

    // Check if the compression ratio has been reached
    if (i % NUM_ITERATIONS == 0) {
      // If the compression ratio has been reached, remove the last character from the output buffer
      output[i - 1] = '\0';

      // Update the compression ratio
      compression_ratio *= COMPRESSION_RATIO;
    }
  }

  // Return the output buffer
  return output;
}

// Define the function to decompress the input buffer
char *decompress(char *input, int input_size) {
  // Allocate memory for the output buffer
  char *output = malloc(MAX_BUF_SIZE);

  // Initialize the output buffer
  memset(output, 0, MAX_BUF_SIZE);

  // Initialize the compression ratio
  float compression_ratio = COMPRESSION_RATIO;

  // Iterate over the input buffer
  for (int i = 0; i < input_size; i++) {
    // Add the current character to the output buffer
    output[i] = input[i];

    // Check if the compression ratio has been reached
    if (i % NUM_ITERATIONS == 0) {
      // If the compression ratio has been reached, repeat the last character in the output buffer
      output[i - 1] = output[i - 2];

      // Update the compression ratio
      compression_ratio *= COMPRESSION_RATIO;
    }
  }

  // Return the output buffer
  return output;
}

// Define the main function
int main() {
  // Get the input from the user
  char *input = malloc(MAX_BUF_SIZE);
  printf("Enter the input string: ");
  scanf("%s", input);

  // Get the input size
  int input_size = strlen(input);

  // Compress the input
  char *compressed = compress(input, input_size);

  // Get the compressed size
  int compressed_size = strlen(compressed);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  // Decompress the compressed string
  char *decompressed = decompress(compressed, compressed_size);

  // Get the decompressed size
  int decompressed_size = strlen(decompressed);

  // Print the decompressed string
  printf("Decompressed string: %s\n", decompressed);

  // Free the allocated memory
  free(input);
  free(compressed);
  free(decompressed);

  return 0;
}
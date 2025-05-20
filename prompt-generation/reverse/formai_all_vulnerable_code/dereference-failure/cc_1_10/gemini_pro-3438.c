//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the input and output buffers
#define MAX_SIZE 1024

// Create a function to compress the input buffer
char *compress(char *input) {
  // Allocate memory for the output buffer
  char *output = malloc(MAX_SIZE);

  // Initialize the output buffer
  int output_index = 0;

  // Iterate over the input buffer
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Get the current character
    char current_char = input[input_index];

    // Get the count of consecutive occurrences of the current character
    int count = 1;
    while (input[input_index + count] == current_char) {
      count++;
    }

    // Append the current character and its count to the output buffer
    output[output_index++] = current_char;
    output[output_index++] = count;

    // Increment the input index
    input_index += count;
  }

  // Append a null terminator to the output buffer
  output[output_index] = '\0';

  // Return the output buffer
  return output;
}

// Create a function to decompress the output buffer
char *decompress(char *output) {
  // Allocate memory for the input buffer
  char *input = malloc(MAX_SIZE);

  // Initialize the input buffer
  int input_index = 0;

  // Iterate over the output buffer
  int output_index = 0;
  while (output[output_index] != '\0') {
    // Get the current character
    char current_char = output[output_index++];

    // Get the count of consecutive occurrences of the current character
    int count = output[output_index++];

    // Append the current character to the input buffer
    for (int i = 0; i < count; i++) {
      input[input_index++] = current_char;
    }
  }

  // Append a null terminator to the input buffer
  input[input_index] = '\0';

  // Return the input buffer
  return input;
}

// Create a function to test the compression and decompression algorithms
void test() {
  // Create an input string
  char *input = "AAAAABBBCCCDDEEEE";

  // Compress the input string
  char *compressed = compress(input);

  // Decompress the compressed string
  char *decompressed = decompress(compressed);

  // Print the input, compressed, and decompressed strings
  printf("Input: %s\n", input);
  printf("Compressed: %s\n", compressed);
  printf("Decompressed: %s\n", decompressed);
}

// Main function
int main() {
  // Test the compression and decompression algorithms
  test();

  return 0;
}
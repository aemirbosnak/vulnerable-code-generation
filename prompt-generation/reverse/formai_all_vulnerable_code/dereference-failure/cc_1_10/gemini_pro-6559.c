//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output strings
#define MAX_STR_SIZE 1024

// Define the maximum number of characters that can be repeated in a row
#define MAX_REPEAT_COUNT 9

// Function to compress a string using run-length encoding
char* compress(char* input) {
  // Allocate memory for the output string
  char* output = malloc(MAX_STR_SIZE);

  // Initialize the output string
  int output_index = 0;

  // Iterate over the input string
  int input_index = 0;
  while (input[input_index] != '\0') {
    // Count the number of consecutive occurrences of the current character
    int repeat_count = 1;
    while (input[input_index] == input[input_index + 1]) {
      repeat_count++;
      input_index++;
    }

    // If the number of consecutive occurrences is greater than 1, encode it using run-length encoding
    if (repeat_count > 1) {
      output[output_index++] = input[input_index];
      output[output_index++] = repeat_count + '0';
    } else {
      // Otherwise, just copy the character to the output string
      output[output_index++] = input[input_index++];
    }
  }

  // Add a null terminator to the end of the output string
  output[output_index] = '\0';

  // Return the compressed string
  return output;
}

// Function to decompress a string that was compressed using run-length encoding
char* decompress(char* input) {
  // Allocate memory for the output string
  char* output = malloc(MAX_STR_SIZE);

  // Initialize the output string
  int output_index = 0;

  // Iterate over the input string
  int input_index = 0;
  while (input[input_index] != '\0') {
    // If the current character is a digit, it represents the number of times the previous character should be repeated
    if (input[input_index] >= '0' && input[input_index] <= '9') {
      int repeat_count = input[input_index] - '0';
      for (int i = 0; i < repeat_count; i++) {
        output[output_index++] = input[input_index - 1];
      }
      input_index++;
    } else {
      // Otherwise, just copy the character to the output string
      output[output_index++] = input[input_index++];
    }
  }

  // Add a null terminator to the end of the output string
  output[output_index] = '\0';

  // Return the decompressed string
  return output;
}

// Function to test the compression and decompression algorithms
void test() {
  // Define a test string
  char* test_string = "aabcccccaaa";

  // Compress the test string
  char* compressed_string = compress(test_string);

  // Decompress the compressed string
  char* decompressed_string = decompress(compressed_string);

  // Print the original, compressed, and decompressed strings
  printf("Original string: %s\n", test_string);
  printf("Compressed string: %s\n", compressed_string);
  printf("Decompressed string: %s\n", decompressed_string);
}

// Main function
int main() {
  // Test the compression and decompression algorithms
  test();

  return 0;
}
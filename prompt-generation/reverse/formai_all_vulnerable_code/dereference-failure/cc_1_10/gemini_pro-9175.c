//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input and output buffers.
#define MAX_BUFFER_SIZE 1024

// Define the compression ratio.
#define COMPRESSION_RATIO 0.5

// Define the number of iterations for the compression algorithm.
#define NUM_ITERATIONS 10

// Define the input and output buffers.
char input_buffer[MAX_BUFFER_SIZE];
char output_buffer[MAX_BUFFER_SIZE];

// Define the compression and decompression functions.
void compress(char *input_buffer, int input_length, char *output_buffer, int *output_length);
void decompress(char *input_buffer, int input_length, char *output_buffer, int *output_length);

// Define the main function.
int main(int argc, char *argv[]) {
  
  // Get the input string from the user.
  char *input_string = argv[1];
  
  // Compress the input string.
  int input_length = strlen(input_string);
  int output_length;
  compress(input_string, input_length, output_buffer, &output_length);
  
  // Print the compressed string.
  printf("Compressed string: %s\n", output_buffer);
  
  // Decompress the compressed string.
  int decompressed_length;
  decompress(output_buffer, output_length, input_buffer, &decompressed_length);
  
  // Print the decompressed string.
  printf("Decompressed string: %s\n", input_buffer);
  
  return 0;
}

// Define the compression function.
void compress(char *input_buffer, int input_length, char *output_buffer, int *output_length) {
  int i, j, k;
  *output_length = 0;
  for (i = 0; i < input_length; i++) {
    for (j = i + 1; j < input_length; j++) {
      for (k = j + 1; k < input_length; k++) {
        if (input_buffer[i] == input_buffer[j] && input_buffer[i] == input_buffer[k]) {
          output_buffer[(*output_length)++] = input_buffer[i];
          output_buffer[(*output_length)++] = j - i;
          output_buffer[(*output_length)++] = k - j;
          i = k;
          break;
        }
      }
    }
    if (i < input_length) {
      output_buffer[(*output_length)++] = input_buffer[i];
    }
  }
}

// Define the decompression function.
void decompress(char *input_buffer, int input_length, char *output_buffer, int *output_length) {
  int i, j, k;
  *output_length = 0;
  for (i = 0; i < input_length; i++) {
    output_buffer[(*output_length)++] = input_buffer[i];
    for (j = i + 1; j < input_length; j++) {
      if (input_buffer[j] == input_buffer[i]) {
        for (k = j + 1; k < input_length; k++) {
          if (input_buffer[k] == input_buffer[i]) {
            output_buffer[(*output_length)++] = input_buffer[i];
            output_buffer[(*output_length)++] = input_buffer[j] - input_buffer[i];
            output_buffer[(*output_length)++] = input_buffer[k] - input_buffer[j];
            i = k;
            break;
          }
        }
        break;
      }
    }
  }
}
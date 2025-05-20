//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
unsigned char *input_buffer;
unsigned char *output_buffer;
unsigned int input_size;
unsigned int output_size;

// Function prototypes
void compress(unsigned char *input, unsigned int input_size, unsigned char **output, unsigned int *output_size);
void decompress(unsigned char *input, unsigned int input_size, unsigned char **output, unsigned int *output_size);
unsigned int get_compressed_size(unsigned int input_size);

// Main function
int main(int argc, char **argv) {
  // Check for correct number of arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    return 1;
  }

  // Read input file into memory
  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    fprintf(stderr, "Error opening input file: %s\n", argv[1]);
    return 1;
  }
  fseek(input_file, 0, SEEK_END);
  input_size = ftell(input_file);
  rewind(input_file);
  input_buffer = malloc(input_size);
  if (input_buffer == NULL) {
    fprintf(stderr, "Error allocating memory for input buffer\n");
    fclose(input_file);
    return 1;
  }
  fread(input_buffer, 1, input_size, input_file);
  fclose(input_file);

  // Allocate memory for output buffer
  output_size = get_compressed_size(input_size);
  output_buffer = malloc(output_size);
  if (output_buffer == NULL) {
    fprintf(stderr, "Error allocating memory for output buffer\n");
    free(input_buffer);
    return 1;
  }

  // Compress input data
  compress(input_buffer, input_size, &output_buffer, &output_size);

  // Write compressed data to output file
  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    fprintf(stderr, "Error opening output file: %s\n", argv[2]);
    free(input_buffer);
    free(output_buffer);
    return 1;
  }
  fwrite(output_buffer, 1, output_size, output_file);
  fclose(output_file);

  // Free allocated memory
  free(input_buffer);
  free(output_buffer);

  return 0;
}

// Get the compressed size of the input data
unsigned int get_compressed_size(unsigned int input_size) {
  return input_size + (input_size / 10) + 1;
}

// Compress the input data
void compress(unsigned char *input, unsigned int input_size, unsigned char **output, unsigned int *output_size) {
  unsigned char *output_ptr = *output;
  unsigned char *input_ptr = input;
  unsigned int count = 0;

  while (input_ptr < input + input_size) {
    if (*input_ptr == *(input_ptr + 1)) {
      count++;
    } else {
      if (count > 0) {
        *output_ptr++ = count;
      }
      *output_ptr++ = *input_ptr;
      count = 0;
    }
    input_ptr++;
  }

  if (count > 0) {
    *output_ptr++ = count;
  }

  *output_size = output_ptr - *output;
}

// Decompress the input data
void decompress(unsigned char *input, unsigned int input_size, unsigned char **output, unsigned int *output_size) {
  unsigned char *output_ptr = *output;
  unsigned char *input_ptr = input;
  unsigned int count;

  while (input_ptr < input + input_size) {
    count = *input_ptr++;
    if (count > 0) {
      while (count--)
        *output_ptr++ = *input_ptr;
    } else {
      *output_ptr++ = *input_ptr++;
    }
  }

  *output_size = output_ptr - *output;
}
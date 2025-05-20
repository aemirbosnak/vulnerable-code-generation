//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the maximum size of the input buffer.
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the output buffer.
#define MAX_OUTPUT_SIZE (MAX_INPUT_SIZE * 2)

// Define the maximum number of bits that can be stored in a single byte.
#define BITS_PER_BYTE 8

// Define the maximum number of bytes that can be stored in a single word.
#define BYTES_PER_WORD (sizeof(uint32_t))

// Define the maximum number of bits that can be stored in a single word.
#define BITS_PER_WORD (BYTES_PER_WORD * BITS_PER_BYTE)

// Define the maximum number of words that can be stored in a single block.
#define WORDS_PER_BLOCK (MAX_OUTPUT_SIZE / BYTES_PER_WORD)

// Define the maximum number of bits that can be stored in a single block.
#define BITS_PER_BLOCK (WORDS_PER_BLOCK * BITS_PER_WORD)

// Define the maximum number of blocks that can be stored in a single file.
#define BLOCKS_PER_FILE 1024

// Define the maximum size of a single file.
#define MAX_FILE_SIZE (BLOCKS_PER_FILE * MAX_OUTPUT_SIZE)

// Read the input file into a buffer.
int read_file(const char *filename, uint8_t *buffer, size_t *size) {
  // Open the input file.
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    return 1;
  }

  // Get the size of the input file.
  fseek(file, 0, SEEK_END);
  *size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Read the input file into the buffer.
  if (*size > MAX_INPUT_SIZE) {
    return 1;
  }
  fread(buffer, *size, 1, file);

  // Close the input file.
  fclose(file);

  return 0;
}

// Write the output file from a buffer.
int write_file(const char *filename, uint8_t *buffer, size_t size) {
  // Open the output file.
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    return 1;
  }

  // Write the output file from the buffer.
  fwrite(buffer, size, 1, file);

  // Close the output file.
  fclose(file);

  return 0;
}

// Compress the input buffer into the output buffer.
int compress(uint8_t *input, size_t input_size, uint8_t *output, size_t *output_size) {
  // Initialize the output buffer.
  uint32_t *output_words = (uint32_t *)output;
  for (size_t i = 0; i < WORDS_PER_BLOCK; i++) {
    output_words[i] = 0;
  }

  // Initialize the input buffer.
  uint8_t *input_bytes = input;

  // Initialize the output buffer.
  uint32_t *output_bytes = (uint32_t *)output;

  // Initialize the output size.
  *output_size = 0;

  // Initialize the current bit.
  uint32_t current_bit = 0;

  // Loop over the input buffer.
  for (size_t i = 0; i < input_size; i++) {
    // Get the current byte.
    uint8_t current_byte = input_bytes[i];

    // Loop over the bits in the current byte.
    for (size_t j = 0; j < BITS_PER_BYTE; j++) {
      // Get the current bit.
      uint32_t current_bit = (current_byte >> j) & 1;

      // Set the current bit in the output buffer.
      output_bytes[current_bit / BITS_PER_WORD] |= (current_bit << (current_bit % BITS_PER_WORD));

      // Increment the current bit.
      current_bit++;
    }
  }

  // Flush the remaining bits in the output buffer.
  if (current_bit % BITS_PER_WORD != 0) {
    output_bytes[current_bit / BITS_PER_WORD] |= (0xffffffffffffffff << (current_bit % BITS_PER_WORD));
  }

  // Update the output size.
  *output_size = current_bit / BITS_PER_BYTE;

  return 0;
}

// Decompress the input buffer into the output buffer.
int decompress(uint8_t *input, size_t input_size, uint8_t *output, size_t *output_size) {
  // Initialize the output buffer.
  uint8_t *output_bytes = output;

  // Initialize the input buffer.
  uint32_t *input_words = (uint32_t *)input;

  // Initialize the output size.
  *output_size = 0;

  // Initialize the current bit.
  uint32_t current_bit = 0;

  // Loop over the input buffer.
  for (size_t i = 0; i < input_size; i++) {
    // Get the current word.
    uint32_t current_word = input_words[i];

    // Loop over the bits in the current word.
    for (size_t j = 0; j < BITS_PER_WORD; j++) {
      // Get the current bit.
      uint32_t current_bit = (current_word >> j) & 1;

      // Set the current bit in the output buffer.
      output_bytes[current_bit / BITS_PER_BYTE] |= (current_bit << (current_bit % BITS_PER_BYTE));

      // Increment the current bit.
      current_bit++;
    }
  }

  // Update the output size.
  *output_size = current_bit / BITS_PER_BYTE;

  return 0;
}

// Main function.
int main(int argc, char **argv) {
  // Check the number of arguments.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input file> <output file> <compress|decompress>\n", argv[0]);
    return 1;
  }

  // Get the input file name.
  const char *input_file = argv[1];

  // Get the output file name.
  const char *output_file = argv[2];

  // Get the operation.
  const char *operation = argv[3];

  // Read the input file.
  uint8_t input[MAX_INPUT_SIZE];
  size_t input_size;
  if (read_file(input_file, input, &input_size)) {
    fprintf(stderr, "Error reading input file.\n");
    return 1;
  }

  // Create the output buffer.
  uint8_t output[MAX_OUTPUT_SIZE];
  size_t output_size;

  // Compress or decompress the input buffer.
  if (!strcmp(operation, "compress")) {
    if (compress(input, input_size, output, &output_size)) {
      fprintf(stderr, "Error compressing input file.\n");
      return 1;
    }
  } else if (!strcmp(operation, "decompress")) {
    if (decompress(input, input_size, output, &output_size)) {
      fprintf(stderr, "Error decompressing input file.\n");
      return 1;
    }
  } else {
    fprintf(stderr, "Invalid operation.\n");
    return 1;
  }

  // Write the output file.
  if (write_file(output_file, output, output_size)) {
    fprintf(stderr, "Error writing output file.\n");
    return 1;
  }

  return 0;
}
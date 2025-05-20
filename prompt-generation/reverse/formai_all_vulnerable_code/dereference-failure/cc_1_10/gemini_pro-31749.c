//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum size of the input string
#define MAX_INPUT_SIZE 1024

// The maximum size of the compressed string
#define MAX_COMPRESSED_SIZE (MAX_INPUT_SIZE * 2)

// The compression ratio
#define COMPRESSION_RATIO 0.5

// The magic number that identifies a compressed string
#define MAGIC_NUMBER 0xCAFE

// The compression algorithm
unsigned char *compress(const unsigned char *input, size_t input_size, size_t *compressed_size) {
  // Allocate memory for the compressed string
  unsigned char *compressed = malloc(MAX_COMPRESSED_SIZE);
  if (compressed == NULL) {
    return NULL; // Error: out of memory
  }

  // Initialize the compressed string
  *compressed_size = 0;

  // Iterate over the input string
  for (size_t i = 0; i < input_size; i++) {
    // Get the current character
    unsigned char c = input[i];

    // If the current character is the same as the previous character, increment the repetition count
    if (i > 0 && c == input[i - 1]) {
      compressed[*compressed_size - 1]++;
      continue;
    }

    // Otherwise, write the character and its repetition count to the compressed string
    compressed[*compressed_size++] = c;
    compressed[*compressed_size++] = 1;
  }

  // Return the compressed string
  return compressed;
}

// The decompression algorithm
unsigned char *decompress(const unsigned char *compressed, size_t compressed_size, size_t *decompressed_size) {
  // Allocate memory for the decompressed string
  unsigned char *decompressed = malloc(MAX_INPUT_SIZE);
  if (decompressed == NULL) {
    return NULL; // Error: out of memory
  }

  // Initialize the decompressed string
  *decompressed_size = 0;

  // Iterate over the compressed string
  for (size_t i = 0; i < compressed_size;) {
    // Get the current character
    unsigned char c = compressed[i++];

    // Get the repetition count
    unsigned char count = compressed[i++];

    // Write the character to the decompressed string count times
    for (size_t j = 0; j < count; j++) {
      decompressed[(*decompressed_size)++] = c;
    }
  }

  // Return the decompressed string
  return decompressed;
}

int main(void) {
  // Get the input string from the user
  printf("Enter the string to be compressed:\n");
  char input[MAX_INPUT_SIZE];
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Compress the input string
  size_t compressed_size;
  unsigned char *compressed = compress(input, strlen(input), &compressed_size);
  if (compressed == NULL) {
    printf("Error: could not compress the string\n");
    return EXIT_FAILURE;
  }

  // Print the compressed string
  printf("Compressed string:\n");
  for (size_t i = 0; i < compressed_size; i++) {
    printf("%02X ", compressed[i]);
  }
  printf("\n");

  // Decompress the compressed string
  size_t decompressed_size;
  unsigned char *decompressed = decompress(compressed, compressed_size, &decompressed_size);
  if (decompressed == NULL) {
    printf("Error: could not decompress the string\n");
    return EXIT_FAILURE;
  }

  // Print the decompressed string
  printf("Decompressed string:\n%s\n", decompressed);

  // Free the memory allocated for the compressed and decompressed strings
  free(compressed);
  free(decompressed);

  return EXIT_SUCCESS;
}
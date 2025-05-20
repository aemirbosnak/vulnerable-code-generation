//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum size of the input string.
#define MAX_INPUT_SIZE 100

// The maximum size of the compressed string.
#define MAX_COMPRESSED_SIZE (MAX_INPUT_SIZE * 2)

// Compresses the input string using the LZ77 algorithm.
//
// The input string is specified by the `input` parameter. The compressed string is
// returned in the `compressed` parameter. The maximum size of the compressed
// string is specified by the `max_compressed_size` parameter.
//
// Returns the size of the compressed string, or -1 if the compression failed.
int compress_lz77(const char *input, char *compressed, size_t max_compressed_size) {
  // Check if the input string is valid.
  if (input == NULL || strlen(input) == 0) {
    return -1;
  }

  // Initialize the compressed string.
  memset(compressed, 0, max_compressed_size);

  // Iterate over the input string.
  size_t input_index = 0;
  while (input_index < strlen(input)) {
    // Find the longest matching substring in the compressed string.
    size_t match_length = 0;
    size_t match_offset = 0;
    for (size_t i = 0; i < input_index; i++) {
      size_t j = input_index;
      while (input[j] == compressed[i + j - input_index] && j < strlen(input)) {
        j++;
      }
      if (j - input_index > match_length) {
        match_length = j - input_index;
        match_offset = i;
      }
    }

    // If a match was found, encode it in the compressed string.
    if (match_length > 0) {
      compressed[input_index] = (match_offset >> 8) & 0xFF;
      compressed[input_index + 1] = match_offset & 0xFF;
      compressed[input_index + 2] = match_length;
      input_index += match_length;
    } else {
      // If no match was found, encode the character directly in the compressed string.
      compressed[input_index] = input[input_index];
      input_index++;
    }
  }

  // Return the size of the compressed string.
  return strlen(compressed);
}

// Decompresses the compressed string using the LZ77 algorithm.
//
// The compressed string is specified by the `compressed` parameter. The
// decompressed string is returned in the `decompressed` parameter. The maximum
// size of the decompressed string is specified by the `max_decompressed_size`
// parameter.
//
// Returns the size of the decompressed string, or -1 if the decompression failed.
int decompress_lz77(const char *compressed, char *decompressed, size_t max_decompressed_size) {
  // Check if the compressed string is valid.
  if (compressed == NULL || strlen(compressed) == 0) {
    return -1;
  }

  // Initialize the decompressed string.
  memset(decompressed, 0, max_decompressed_size);

  // Iterate over the compressed string.
  size_t compressed_index = 0;
  while (compressed_index < strlen(compressed)) {
    // Decode the next character or substring from the compressed string.
    if ((compressed[compressed_index] & 0x80) == 0) {
      // The next character is encoded directly.
      decompressed[compressed_index] = compressed[compressed_index];
      compressed_index++;
    } else {
      // The next substring is encoded as a match.
      size_t match_offset = (compressed[compressed_index] << 8) | compressed[compressed_index + 1];
      size_t match_length = compressed[compressed_index + 2];
      for (size_t i = 0; i < match_length; i++) {
        decompressed[compressed_index + i] = decompressed[compressed_index + i - match_length];
      }
      compressed_index += 3;
    }
  }

  // Return the size of the decompressed string.
  return strlen(decompressed);
}

// Prints the usage information for this program.
void print_usage(const char *program_name) {
  printf("Usage: %s <input_file> <output_file>\n", program_name);
  printf("Compresses the input file using the LZ77 algorithm and writes the compressed data to the output file.\n");
}

// Main function.
int main(int argc, char **argv) {
  // Check if the command-line arguments are valid.
  if (argc != 3) {
    print_usage(argv[0]);
    return EXIT_FAILURE;
  }

  // Read the input file.
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }
  fseek(input_file, 0, SEEK_END);
  size_t input_size = ftell(input_file);
  fseek(input_file, 0, SEEK_SET);
  char *input = (char *)malloc(input_size + 1);
  if (input == NULL) {
    perror("Error allocating memory for input string");
    fclose(input_file);
    return EXIT_FAILURE;
  }
  fread(input, 1, input_size, input_file);
  fclose(input_file);

  // Compress the input string.
  char compressed[MAX_COMPRESSED_SIZE];
  int compressed_size = compress_lz77(input, compressed, MAX_COMPRESSED_SIZE);
  if (compressed_size == -1) {
    perror("Error compressing input string");
    free(input);
    return EXIT_FAILURE;
  }

  // Write the compressed data to the output file.
  FILE *output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    perror("Error opening output file");
    free(input);
    return EXIT_FAILURE;
  }
  fwrite(compressed, 1, compressed_size, output_file);
  fclose(output_file);

  // Decompress the compressed data.
  char decompressed[input_size + 1];
  int decompressed_size = decompress_lz77(compressed, decompressed, input_size + 1);
  if (decompressed_size == -1) {
    perror("Error decompressing input string");
    free(input);
    return EXIT_FAILURE;
  }

  // Check if the decompressed string matches the original input string.
  if (strcmp(input, decompressed) != 0) {
    printf("Error: Decompressed string does not match original input string.\n");
    free(input);
    return EXIT_FAILURE;
  }

  // Clean up.
  free(input);

  // Success.
  return EXIT_SUCCESS;
}
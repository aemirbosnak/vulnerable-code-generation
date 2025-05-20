//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Linus Torvalds style:
#define LINUS_STYLE

#ifdef LINUS_STYLE
#define DEBUG(fmt, ...)                                    \
  do {                                                       \
    printf("Linus says: " fmt, ##__VA_ARGS__);               \
    printf("\n");                                           \
  } while (0)
#else
#define DEBUG(...)
#endif

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 3) {
    printf("Usage: %s <input_image> <output_image>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Open input and output files
  FILE *input_file = fopen(argv[1], "rb");
  if (!input_file) {
    printf("Error opening input image file: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  FILE *output_file = fopen(argv[2], "wb");
  if (!output_file) {
    printf("Error opening output image file: %s\n", argv[2]);
    fclose(input_file);
    return EXIT_FAILURE;
  }

  // Read input image headers
  uint16_t bf_type;
  uint32_t bf_size;
  uint16_t bf_reserved1;
  uint16_t bf_reserved2;
  uint32_t bf_offbits;
  fread(&bf_type, sizeof(bf_type), 1, input_file);
  fread(&bf_size, sizeof(bf_size), 1, input_file);
  fread(&bf_reserved1, sizeof(bf_reserved1), 1, input_file);
  fread(&bf_reserved2, sizeof(bf_reserved2), 1, input_file);
  fread(&bf_offbits, sizeof(bf_offbits), 1, input_file);

  // Check if the input file is a BMP image
  if (bf_type != 0x4D42) {
    printf("Error: Input file is not a BMP image\n");
    fclose(input_file);
    fclose(output_file);
    return EXIT_FAILURE;
  }

  // Copy input image headers to output image
  fwrite(&bf_type, sizeof(bf_type), 1, output_file);
  fwrite(&bf_size, sizeof(bf_size), 1, output_file);
  fwrite(&bf_reserved1, sizeof(bf_reserved1), 1, output_file);
  fwrite(&bf_reserved2, sizeof(bf_reserved2), 1, output_file);
  fwrite(&bf_offbits, sizeof(bf_offbits), 1, output_file);

  // Read input image data
  fseek(input_file, bf_offbits, SEEK_SET);
  unsigned char *input_data = (unsigned char *)malloc(bf_size - bf_offbits);
  fread(input_data, 1, bf_size - bf_offbits, input_file);

  // Encode message in input image data
  char *message = "Hello, world!";
  size_t message_len = strlen(message);
  for (size_t i = 0; i < message_len; i++) {
    for (size_t j = 0; j < 8; j++) {
      // Get the bit from the message character
      unsigned char bit = (message[i] >> j) & 1;

DEBUG("Encoding bit %d of character %c (%d) into byte %d", j, message[i], message[i], i + j);
      // Set the corresponding bit in the input image data
      input_data[i + j] = (input_data[i + j] & 0xFE) | bit;
    }
  }

  // Write encoded image data to output file
  fwrite(input_data, 1, bf_size - bf_offbits, output_file);

  // Free allocated memory
  free(input_data);

  // Close input and output files
  fclose(input_file);
  fclose(output_file);

  printf("Message encoded successfully!\n");
  return EXIT_SUCCESS;
}
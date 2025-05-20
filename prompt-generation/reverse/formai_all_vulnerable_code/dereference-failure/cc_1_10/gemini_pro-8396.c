//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bmp_header {
  char bm[2];
  int size;
  int reserved;
  int offset;
  int dib_header_size;
  int width;
  int height;
  short planes;
  short bits_per_pixel;
  int compression;
  int image_size;
  int x_resolution;
  int y_resolution;
  int num_colors;
  int important_colors;
};

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <message>\n", argv[0]);
    return 1;
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    perror("Error opening input file");
    return 2;
  }

  FILE *output = fopen(argv[2], "wb");
  if (!output) {
    perror("Error opening output file");
    return 3;
  }

  struct bmp_header header;
  fread(&header, sizeof(header), 1, input);

  // Check if the file is a valid BMP file
  if (header.bm[0] != 'B' || header.bm[1] != 'M') {
    fprintf(stderr, "Error: Invalid BMP file\n");
    return 4;
  }

  // Check if the file is 24-bit color depth
  if (header.bits_per_pixel != 24) {
    fprintf(stderr, "Error: Only 24-bit color depth is supported\n");
    return 5;
  }

  // Get the size of the image data
  int image_size = header.image_size;

  // Allocate memory for the image data
  unsigned char *image_data = malloc(image_size);
  if (!image_data) {
    perror("Error allocating memory for image data");
    return 6;
  }

  // Read the image data from the input file
  fread(image_data, image_size, 1, input);

  // Encode the message into the image data
  int message_length = strlen(argv[3]);
  for (int i = 0; i < message_length; i++) {
    // Get the binary representation of the character
    int c = argv[3][i];
    for (int j = 0; j < 8; j++) {
      // Set the least significant bit of the current pixel to the corresponding bit of the character
      image_data[i * 3 + j / 3] &= ~(1 << (7 - j));
      image_data[i * 3 + j / 3] |= (c >> j) & 1;
    }
  }

  // Write the modified image data to the output file
  fwrite(&header, sizeof(header), 1, output);
  fwrite(image_data, image_size, 1, output);

  // Free the allocated memory
  free(image_data);

  // Close the files
  fclose(input);
  fclose(output);

  return 0;
}
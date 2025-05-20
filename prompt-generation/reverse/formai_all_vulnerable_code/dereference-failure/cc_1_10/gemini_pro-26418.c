//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8

int main() {
  // Read the input image
  FILE *input_image = fopen("input.bmp", "rb");
  if (input_image == NULL) {
    perror("Error opening the input image");
    return EXIT_FAILURE;
  }

  // Get the width and height of the input image
  int width, height;
  fread(&width, sizeof(int), 1, input_image);
  fread(&height, sizeof(int), 1, input_image);

  // Read the input watermark
  FILE *input_watermark = fopen("watermark.bmp", "rb");
  if (input_watermark == NULL) {
    perror("Error opening the input watermark");
    return EXIT_FAILURE;
  }

  // Get the width and height of the input watermark
  int watermark_width, watermark_height;
  fread(&watermark_width, sizeof(int), 1, input_watermark);
  fread(&watermark_height, sizeof(int), 1, input_watermark);

  // Check if the watermark is smaller than the input image
  if (watermark_width > width || watermark_height > height) {
    fprintf(stderr, "The watermark is larger than the input image\n");
    return EXIT_FAILURE;
  }

  // Create the output image
  FILE *output_image = fopen("output.bmp", "wb");
  if (output_image == NULL) {
    perror("Error opening the output image");
    return EXIT_FAILURE;
  }

  // Write the header of the output image
  fwrite(&width, sizeof(int), 1, output_image);
  fwrite(&height, sizeof(int), 1, output_image);

  // Embed the watermark in the output image
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Read the pixel from the input image
      unsigned char pixel[BYTES_PER_PIXEL];
      fread(pixel, BYTES_PER_PIXEL, 1, input_image);

      // Read the bit from the watermark
      unsigned char bit;
      fread(&bit, sizeof(unsigned char), 1, input_watermark);

      // Embed the bit in the pixel
      for (int i = 0; i < BYTES_PER_PIXEL; i++) {
        pixel[i] = (pixel[i] & 0xfe) | (bit & 0x01);
        bit >>= 1;
      }

      // Write the pixel to the output image
      fwrite(pixel, BYTES_PER_PIXEL, 1, output_image);
    }
  }

  // Close the files
  fclose(input_image);
  fclose(input_watermark);
  fclose(output_image);

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the image
#define WIDTH 512
#define HEIGHT 512

// Define the watermark
#define WATERMARK "Hello, world!"

// Embed the watermark in the image
void embed_watermark(unsigned char *image, const char *watermark) {
  // Convert the watermark to a bitstream
  int bitstream_length = strlen(watermark) * 8;
  unsigned char *bitstream = malloc(bitstream_length);
  for (int i = 0; i < strlen(watermark); i++) {
    for (int j = 0; j < 8; j++) {
      bitstream[i * 8 + j] = (watermark[i] >> j) & 1;
    }
  }

  // Embed the bitstream in the image
  int bitstream_index = 0;
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // Get the least significant bit of the pixel
      unsigned char lsb = image[i * WIDTH + j] & 1;

      // Replace the least significant bit of the pixel with the next bit in the bitstream
      image[i * WIDTH + j] = (image[i * WIDTH + j] & ~1) | (bitstream[bitstream_index++] & 1);

      // If we have reached the end of the bitstream, stop embedding
      if (bitstream_index == bitstream_length) {
        break;
      }
    }

    // If we have reached the end of the bitstream, stop embedding
    if (bitstream_index == bitstream_length) {
      break;
    }
  }

  // Free the bitstream
  free(bitstream);
}

// Extract the watermark from the image
char *extract_watermark(unsigned char *image) {
  // Create a buffer to store the extracted watermark
  int watermark_length = strlen(WATERMARK);
  char *watermark = malloc(watermark_length + 1);

  // Extract the bitstream from the image
  int bitstream_length = watermark_length * 8;
  unsigned char *bitstream = malloc(bitstream_length);
  for (int i = 0; i < bitstream_length; i++) {
    // Get the least significant bit of the pixel
    unsigned char lsb = image[i / 8 * WIDTH + i % 8] & 1;

    // Add the least significant bit of the pixel to the bitstream
    bitstream[i] = lsb;
  }

  // Convert the bitstream to a string
  for (int i = 0; i < watermark_length; i++) {
    unsigned char byte = 0;
    for (int j = 0; j < 8; j++) {
      byte |= (bitstream[i * 8 + j] << j);
    }
    watermark[i] = byte;
  }

  // Add a null terminator to the watermark
  watermark[watermark_length] = '\0';

  // Free the bitstream
  free(bitstream);

  // Return the watermark
  return watermark;
}

// Main function
int main() {
  // Load the image
  unsigned char *image = malloc(WIDTH * HEIGHT);
  FILE *image_file = fopen("image.bmp", "rb");
  fread(image, WIDTH * HEIGHT, 1, image_file);
  fclose(image_file);

  // Embed the watermark in the image
  embed_watermark(image, WATERMARK);

  // Save the watermarked image
  image_file = fopen("watermarked_image.bmp", "wb");
  fwrite(image, WIDTH * HEIGHT, 1, image_file);
  fclose(image_file);

  // Extract the watermark from the watermarked image
  char *extracted_watermark = extract_watermark(image);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extracted_watermark);

  // Free the extracted watermark
  free(extracted_watermark);

  // Free the image
  free(image);

  return 0;
}
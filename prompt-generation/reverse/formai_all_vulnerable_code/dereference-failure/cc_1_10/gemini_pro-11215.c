//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// This function takes an input image, a watermark image, and an output image.
// It embeds the watermark into the input image and saves the result to the output image.
int embed_watermark(unsigned char *input_image, unsigned char *watermark_image, unsigned char *output_image, int width, int height) {
  // Check if the input image is large enough to hold the watermark.
  if (width < 8 || height < 8) {
    return -1;
  }

  // Initialize the output image to the input image.
  memcpy(output_image, input_image, width * height);

  // Embed the watermark into the output image.
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      // Get the pixel value from the input image.
      unsigned char pixel = input_image[i + j * width];

      // Get the watermark pixel value.
      unsigned char watermark_pixel = watermark_image[i % 8 + (j % 8) * 8];

      // Embed the watermark pixel into the input pixel.
      output_image[i + j * width] = pixel + (watermark_pixel >> 4);
    }
  }

  // Return success.
  return 0;
}

// This function takes an input image and a watermark image, and extracts the watermark from the input image.
int extract_watermark(unsigned char *input_image, unsigned char *watermark_image, int width, int height) {
  // Check if the input image is large enough to contain the watermark.
  if (width < 8 || height < 8) {
    return -1;
  }

  // Initialize the watermark image to zero.
  memset(watermark_image, 0, 8 * 8);

  // Extract the watermark from the input image.
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      // Get the pixel value from the input image.
      unsigned char pixel = input_image[i + j * width];

      // Extract the watermark pixel from the input pixel.
      watermark_image[i % 8 + (j % 8) * 8] |= ((pixel & 0x0F) << 4);
    }
  }

  // Return success.
  return 0;
}

// This function takes an input image and a watermark image, and prints the watermark to the console.
int print_watermark(unsigned char *watermark_image) {
  // Print the watermark to the console.
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%c", watermark_image[i + j * 8] ? '1' : '0');
    }
    printf("\n");
  }

  // Return success.
  return 0;
}

int main() {
  // Define the width and height of the images.
  int width = 512;
  int height = 512;

  // Allocate memory for the input, watermark, and output images.
  unsigned char *input_image = (unsigned char *)malloc(width * height);
  unsigned char *watermark_image = (unsigned char *)malloc(8 * 8);
  unsigned char *output_image = (unsigned char *)malloc(width * height);

  // Generate a random input image.
  for (int i = 0; i < width * height; i++) {
    input_image[i] = rand() % 256;
  }

  // Generate a random watermark image.
  for (int i = 0; i < 8 * 8; i++) {
    watermark_image[i] = rand() % 256;
  }

  // Embed the watermark into the input image.
  embed_watermark(input_image, watermark_image, output_image, width, height);

  // Extract the watermark from the output image.
  extract_watermark(output_image, watermark_image, width, height);

  // Print the watermark to the console.
  print_watermark(watermark_image);

  // Free the memory allocated for the images.
  free(input_image);
  free(watermark_image);
  free(output_image);

  // Return success.
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

// Function to embed a watermark in an image
void embedWatermark(unsigned char *image, unsigned char *watermark, int watermarkSize) {
  int i, j, k;

  // Iterate over the pixels of the image
  for (i = 0; i < IMAGE_HEIGHT; i++) {
    for (j = 0; j < IMAGE_WIDTH; j++) {

      // Get the pixel value
      unsigned char pixelValue = image[i * IMAGE_WIDTH + j];

      // Embed the watermark bit in the least significant bit of the pixel value
      if (k < watermarkSize) {
        pixelValue = pixelValue & 0xFE | (watermark[k] >> 7);
        k++;
      }

      // Set the pixel value
      image[i * IMAGE_WIDTH + j] = pixelValue;
    }
  }
}

// Function to extract a watermark from an image
void extractWatermark(unsigned char *image, unsigned char *watermark, int watermarkSize) {
  int i, j, k;

  // Iterate over the pixels of the image
  for (i = 0; i < IMAGE_HEIGHT; i++) {
    for (j = 0; j < IMAGE_WIDTH; j++) {

      // Get the pixel value
      unsigned char pixelValue = image[i * IMAGE_WIDTH + j];

      // Extract the watermark bit from the least significant bit of the pixel value
      if (k < watermarkSize) {
        watermark[k] = (pixelValue & 0x01) << 7;
        k++;
      }
    }
  }
}

// Main function
int main() {
  // Create an image
  unsigned char image[IMAGE_HEIGHT * IMAGE_WIDTH];

  // Create a watermark
  unsigned char watermark[] = "Hello, world!";
  int watermarkSize = strlen(watermark) * 8;

  // Embed the watermark in the image
  embedWatermark(image, watermark, watermarkSize);

  // Extract the watermark from the image
  unsigned char extractedWatermark[watermarkSize];
  extractWatermark(image, extractedWatermark, watermarkSize);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extractedWatermark);

  return 0;
}
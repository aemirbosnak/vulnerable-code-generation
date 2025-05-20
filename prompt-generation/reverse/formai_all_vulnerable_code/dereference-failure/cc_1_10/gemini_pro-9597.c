//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 512
#define IMG_HEIGHT 512

// Function to embed the watermark into the image
void embed_watermark(unsigned char *image, unsigned char *watermark, int size) {
  int i, j, k;

  // Iterate over the image pixels
  for (i = 0; i < IMG_HEIGHT; i++) {
    for (j = 0; j < IMG_WIDTH; j++) {
      // Get the pixel value
      int pixel = image[i * IMG_WIDTH + j];

      // Embed the watermark bit into the least significant bit of the pixel
      if (k < size && watermark[k] == '1') {
        pixel |= 1;
      } else {
        pixel &= ~1;
      }

      // Update the pixel value
      image[i * IMG_WIDTH + j] = pixel;

      // Increment the watermark bit counter
      k++;
    }
  }
}

// Function to extract the watermark from the image
void extract_watermark(unsigned char *image, unsigned char *watermark, int size) {
  int i, j, k;

  // Iterate over the image pixels
  for (i = 0; i < IMG_HEIGHT; i++) {
    for (j = 0; j < IMG_WIDTH; j++) {
      // Get the pixel value
      int pixel = image[i * IMG_WIDTH + j];

      // Extract the watermark bit from the least significant bit of the pixel
      if (pixel & 1) {
        watermark[k] = '1';
      } else {
        watermark[k] = '0';
      }

      // Increment the watermark bit counter
      k++;
    }
  }
}

int main() {
  // Load the image
  FILE *image_file = fopen("image.bmp", "rb");
  if (image_file == NULL) {
    printf("Error opening image file.\n");
    return -1;
  }

  unsigned char image[IMG_HEIGHT * IMG_WIDTH];
  fread(image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, image_file);
  fclose(image_file);

  // Load the watermark
  FILE *watermark_file = fopen("watermark.txt", "rb");
  if (watermark_file == NULL) {
    printf("Error opening watermark file.\n");
    return -1;
  }

  char watermark[1024];
  fread(watermark, sizeof(char), 1024, watermark_file);
  fclose(watermark_file);

  // Embed the watermark into the image
  embed_watermark(image, watermark, strlen(watermark));

  // Save the watermarked image
  FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
  if (watermarked_image_file == NULL) {
    printf("Error opening watermarked image file.\n");
    return -1;
  }

  fwrite(image, sizeof(unsigned char), IMG_HEIGHT * IMG_WIDTH, watermarked_image_file);
  fclose(watermarked_image_file);

  // Extract the watermark from the image
  unsigned char extracted_watermark[1024];
  extract_watermark(image, extracted_watermark, strlen(watermark));

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extracted_watermark);

  return 0;
}
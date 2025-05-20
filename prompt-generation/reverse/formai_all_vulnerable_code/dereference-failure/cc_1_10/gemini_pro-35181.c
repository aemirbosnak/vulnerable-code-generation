//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

// Function to embed a watermark into an image
void embed_watermark(unsigned char *image, char *watermark, int watermark_length) {
  // Convert the watermark to a binary string
  char *binary_watermark = malloc(watermark_length * 8 + 1);
  for (int i = 0; i < watermark_length; i++) {
    for (int j = 0; j < 8; j++) {
      binary_watermark[i * 8 + j] = (watermark[i] & (1 << (7 - j))) ? '1' : '0';
    }
  }
  binary_watermark[watermark_length * 8] = '\0';

  // Embed the watermark into the image
  int watermark_index = 0;
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      // Get the least significant bit of the pixel
      int lsb = image[i * IMAGE_WIDTH + j] & 1;

      // Replace the least significant bit of the pixel with the current bit of the watermark
      image[i * IMAGE_WIDTH + j] &= ~1;
      image[i * IMAGE_WIDTH + j] |= binary_watermark[watermark_index++]-'0';

      // Increment the watermark index
      if (watermark_index >= watermark_length * 8) {
        watermark_index = 0;
      }
    }
  }

  // Free the binary watermark string
  free(binary_watermark);
}

// Function to extract a watermark from an image
char *extract_watermark(unsigned char *image) {
  // Allocate memory for the extracted watermark
  char *watermark = malloc(1024);
  int watermark_index = 0;

  // Extract the watermark from the image
  for (int i = 0; i < IMAGE_HEIGHT; i++) {
    for (int j = 0; j < IMAGE_WIDTH; j++) {
      // Get the least significant bit of the pixel
      int lsb = image[i * IMAGE_WIDTH + j] & 1;

      // Append the least significant bit of the pixel to the watermark
      watermark[watermark_index++] = lsb + '0';

      // If the watermark index is a multiple of 8, convert the 8 bits to a character
      if (watermark_index % 8 == 0) {
        watermark[watermark_index - 1] = '\0';
        int character = 0;
        for (int k = 0; k < 8; k++) {
          character |= (watermark[watermark_index - 8 + k] - '0') << (7 - k);
        }
        watermark[watermark_index++] = character;
      }
    }
  }

  // Terminate the watermark string
  watermark[watermark_index] = '\0';

  // Return the extracted watermark
  return watermark;
}

// Main function
int main() {
  // Load the image from a file
  unsigned char image[IMAGE_HEIGHT * IMAGE_WIDTH];
  FILE *image_file = fopen("image.bmp", "rb");
  fread(image, sizeof(unsigned char), IMAGE_HEIGHT * IMAGE_WIDTH, image_file);
  fclose(image_file);

  // Embed a watermark into the image
  char *watermark = "This is a watermark";
  embed_watermark(image, watermark, strlen(watermark));

  // Save the watermarked image to a file
  FILE *watermarked_image_file = fopen("watermarked_image.bmp", "wb");
  fwrite(image, sizeof(unsigned char), IMAGE_HEIGHT * IMAGE_WIDTH, watermarked_image_file);
  fclose(watermarked_image_file);

  // Extract the watermark from the watermarked image
  char *extracted_watermark = extract_watermark(image);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extracted_watermark);

  // Free the extracted watermark string
  free(extracted_watermark);

  return 0;
}
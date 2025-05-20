//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The watermark to embed into the image
#define WATERMARK "SECRET"

// The length of the watermark in bytes
#define WATERMARK_LENGTH (sizeof(WATERMARK) - 1)

// The size of the image in bytes
#define IMAGE_SIZE 1024 * 1024

// The number of bits to use for the watermark
#define WATERMARK_BITS 8

// The spread of the watermark bits across the image
#define WATERMARK_SPREAD 16

// Embed the watermark into the image
void embed_watermark(unsigned char *image, const unsigned char *watermark) {
  for (int i = 0; i < WATERMARK_LENGTH; i++) {
    for (int j = 0; j < WATERMARK_BITS; j++) {
      int bit = (watermark[i] >> j) & 1;
      int index = i * WATERMARK_SPREAD + j;
      image[index] = (image[index] & 0xFE) | bit;
    }
  }
}

// Extract the watermark from the image
unsigned char *extract_watermark(const unsigned char *image) {
  unsigned char *watermark = malloc(WATERMARK_LENGTH);
  for (int i = 0; i < WATERMARK_LENGTH; i++) {
    for (int j = 0; j < WATERMARK_BITS; j++) {
      int index = i * WATERMARK_SPREAD + j;
      int bit = image[index] & 1;
      watermark[i] |= bit << j;
    }
  }
  return watermark;
}

// Save the image to a file
void save_image(const unsigned char *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  fwrite(image, IMAGE_SIZE, 1, fp);
  fclose(fp);
}

// Load the image from a file
unsigned char *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  unsigned char *image = malloc(IMAGE_SIZE);
  fread(image, IMAGE_SIZE, 1, fp);
  fclose(fp);
  return image;
}

// Print the watermark
void print_watermark(const unsigned char *watermark) {
  for (int i = 0; i < WATERMARK_LENGTH; i++) {
    printf("%c", watermark[i]);
  }
  printf("\n");
}

int main() {
  // Load the image
  unsigned char *image = load_image("image.bmp");

  // Embed the watermark
  embed_watermark(image, WATERMARK);

  // Save the watermarked image
  save_image(image, "watermarked_image.bmp");

  // Extract the watermark
  unsigned char *watermark = extract_watermark(image);

  // Print the watermark
  print_watermark(watermark);

  // Free the memory allocated for the image and watermark
  free(image);
  free(watermark);

  return 0;
}
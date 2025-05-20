//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned char byte;

#define MAX_IMAGE_SIZE 1000000

// Embed a watermark into an image.
void embed_watermark(byte *image, int image_size, byte *watermark, int watermark_size) {
  // Check if the watermark is too large for the image.
  if (watermark_size > image_size) {
    printf("Watermark is too large for image.\n");
    return;
  }

  // Embed the watermark into the image.
  for (int i = 0; i < watermark_size; i++) {
    image[i] = image[i] ^ watermark[i];
  }
}

// Extract a watermark from an image.
void extract_watermark(byte *image, int image_size, byte *watermark, int watermark_size) {
  // Check if the watermark is too large for the image.
  if (watermark_size > image_size) {
    printf("Watermark is too large for image.\n");
    return;
  }

  // Extract the watermark from the image.
  for (int i = 0; i < watermark_size; i++) {
    watermark[i] = image[i] ^ watermark[i];
  }
}

// Test the watermarking algorithm.
int main(int argc, char *argv[]) {
  // Read the image from a file.
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    printf("Error opening image file.\n");
    return 1;
  }
  fseek(image_file, 0, SEEK_END);
  int image_size = ftell(image_file);
  rewind(image_file);
  byte *image = malloc(image_size);
  fread(image, 1, image_size, image_file);
  fclose(image_file);

  // Read the watermark from a file.
  FILE *watermark_file = fopen(argv[2], "rb");
  if (watermark_file == NULL) {
    printf("Error opening watermark file.\n");
    return 1;
  }
  fseek(watermark_file, 0, SEEK_END);
  int watermark_size = ftell(watermark_file);
  rewind(watermark_file);
  byte *watermark = malloc(watermark_size);
  fread(watermark, 1, watermark_size, watermark_file);
  fclose(watermark_file);

  // Embed the watermark into the image.
  embed_watermark(image, image_size, watermark, watermark_size);

  // Extract the watermark from the image.
  byte *extracted_watermark = malloc(watermark_size);
  extract_watermark(image, image_size, extracted_watermark, watermark_size);

  // Compare the extracted watermark to the original watermark.
  int correct = 1;
  for (int i = 0; i < watermark_size; i++) {
    if (extracted_watermark[i] != watermark[i]) {
      correct = 0;
      break;
    }
  }

  // Print the result.
  if (correct) {
    printf("Watermark extracted successfully.\n");
  } else {
    printf("Watermark extraction failed.\n");
  }

  // Free the allocated memory.
  free(image);
  free(watermark);
  free(extracted_watermark);

  return 0;
}
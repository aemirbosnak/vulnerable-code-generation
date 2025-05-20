//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
// Linus Torvalds style Digital Watermarking example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed the watermark in the image
void embed_watermark(char *image, char *watermark) {
  // Get the length of the image and the watermark
  int image_len = strlen(image);
  int watermark_len = strlen(watermark);

  // Check if the watermark is too long
  if (watermark_len > image_len) {
    printf("Watermark is too long!\n");
    return;
  }

  // Embed the watermark in the image
  for (int i = 0; i < watermark_len; i++) {
    image[i] ^= watermark[i];
  }
}

// Extract the watermark from the image
void extract_watermark(char *image, char *watermark) {
  // Get the length of the image and the watermark
  int image_len = strlen(image);
  int watermark_len = strlen(watermark);

  // Check if the watermark is too long
  if (watermark_len > image_len) {
    printf("Watermark is too long!\n");
    return;
  }

  // Extract the watermark from the image
  for (int i = 0; i < watermark_len; i++) {
    watermark[i] ^= image[i];
  }
}

// Main function
int main() {
  // Define the image and the watermark
  char image[] = "This is an image.";
  char watermark[] = "This is a watermark.";

  // Embed the watermark in the image
  embed_watermark(image, watermark);

  // Extract the watermark from the image
  char extracted_watermark[strlen(watermark)];
  extract_watermark(image, extracted_watermark);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", extracted_watermark);

  return 0;
}
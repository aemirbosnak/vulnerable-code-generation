//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the watermark.
const char *watermark = "Copyright © 2023 by the Surrealist Software Society";

// Embed the watermark into the image.
void embed_watermark(unsigned char *image, int width, int height) {
  // Get the current time.
  time_t t = time(NULL);

  // Create a random number generator.
  srand(t);

  // Embed the watermark into the image.
  for (int i = 0; i < width * height; i++) {
    // Get a random number between 0 and 255.
    int r = rand() % 256;

    // If the random number is greater than 127, embed the watermark.
    if (r > 127) {
      image[i] = watermark[i % strlen(watermark)];
    }
  }
}

// Extract the watermark from the image.
char *extract_watermark(unsigned char *image, int width, int height) {
  // Allocate a buffer for the watermark.
  char *watermark = malloc(width * height);

  // Extract the watermark from the image.
  for (int i = 0; i < width * height; i++) {
    // If the pixel is greater than 127, extract the watermark.
    if (image[i] > 127) {
      watermark[i] = image[i];
    }
  }

  // Return the watermark.
  return watermark;
}

// Main function.
int main(int argc, char *argv[]) {
  // Check if the user specified an image file.
  if (argc < 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Open the image file.
  FILE *image_file = fopen(argv[1], "rb");
  if (image_file == NULL) {
    perror("Error opening image file");
    return 1;
  }

  // Get the image's width and height.
  int width, height;
  fread(&width, sizeof(int), 1, image_file);
  fread(&height, sizeof(int), 1, image_file);

  // Allocate a buffer for the image data.
  unsigned char *image = malloc(width * height);

  // Read the image data from the file.
  fread(image, sizeof(unsigned char), width * height, image_file);

  // Close the image file.
  fclose(image_file);

  // Embed the watermark into the image.
  embed_watermark(image, width, height);

  // Open the watermarked image file.
  FILE *watermarked_image_file = fopen("watermarked.bmp", "wb");
  if (watermarked_image_file == NULL) {
    perror("Error opening watermarked image file");
    return 1;
  }

  // Write the watermarked image data to the file.
  fwrite(&width, sizeof(int), 1, watermarked_image_file);
  fwrite(&height, sizeof(int), 1, watermarked_image_file);
  fwrite(image, sizeof(unsigned char), width * height, watermarked_image_file);

  // Close the watermarked image file.
  fclose(watermarked_image_file);

  // Free the image data buffer.
  free(image);

  // Extract the watermark from the watermarked image.
  char *watermark = extract_watermark(image, width, height);

  // Print the watermark.
  printf("Watermark: %s\n", watermark);

  // Free the watermark buffer.
  free(watermark);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
// Post-Apocalyptic Image Processor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions
void flip_image(unsigned char *data, int width, int height);
void adjust_brightness(unsigned char *data, int width, int height, int delta);
void adjust_contrast(unsigned char *data, int width, int height, double factor);

int main() {
  // Load image data from file
  FILE *fp = fopen("apocalypse.raw", "rb");
  if (!fp) {
    fprintf(stderr, "Failed to open image file.\n");
    return EXIT_FAILURE;
  }

  // Read image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for image data
  unsigned char *data = malloc(width * height);
  if (!data) {
    fprintf(stderr, "Failed to allocate memory for image data.\n");
    fclose(fp);
    return EXIT_FAILURE;
  }

  // Read pixel data
  fread(data, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Perform image processing
  flip_image(data, width, height);
  adjust_brightness(data, width, height, 100);
  adjust_contrast(data, width, height, 1.5);

  // Save processed image to file
  fp = fopen("processed_apocalypse.raw", "wb");
  if (!fp) {
    fprintf(stderr, "Failed to open output image file.\n");
    free(data);
    return EXIT_FAILURE;
  }

  // Write processed image data
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);
  fwrite(data, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Free memory
  free(data);

  return EXIT_SUCCESS;
}

// Flip image data vertically
void flip_image(unsigned char *data, int width, int height) {
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char temp = data[i * width + j];
      data[i * width + j] = data[(height - i - 1) * width + j];
      data[(height - i - 1) * width + j] = temp;
    }
  }
}

// Adjust image brightness by adding a delta value
void adjust_brightness(unsigned char *data, int width, int height, int delta) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = data[i * width + j] + delta;
      if (value < 0) value = 0;
      if (value > 255) value = 255;
      data[i * width + j] = value;
    }
  }
}

// Adjust image contrast by multiplying by a factor
void adjust_contrast(unsigned char *data, int width, int height, double factor) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int value = (data[i * width + j] - 128) * factor + 128;
      if (value < 0) value = 0;
      if (value > 255) value = 255;
      data[i * width + j] = value;
    }
  }
}
//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[y * width + width - x - 1];
      image[y * width + width - x - 1] = temp;
    }
  }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      unsigned char temp = image[y * width + x];
      image[y * width + x] = image[(height - y - 1) * width + x];
      image[(height - y - 1) * width + x] = temp;
    }
  }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int new_value = image[y * width + x] + brightness;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[y * width + x] = new_value;
    }
  }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int new_value = (image[y * width + x] - 128) * contrast + 128;
      if (new_value > 255) {
        new_value = 255;
      } else if (new_value < 0) {
        new_value = 0;
      }
      image[y * width + x] = new_value;
    }
  }
}

int main() {
  // Read the image from a file
  FILE *file = fopen("image.bmp", "rb");
  if (file == NULL) {
    printf("Error opening file\n");
    return -1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  // Allocate memory for the image data
  unsigned char *image = malloc(width * height);

  // Read the image data from the file
  fread(image, sizeof(unsigned char), width * height, file);

  // Close the file
  fclose(file);

  // Flip the image horizontally
  flip_horizontal(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 2);

  // Write the modified image to a file
  file = fopen("modified_image.bmp", "wb");
  if (file == NULL) {
    printf("Error opening file\n");
    return -1;
  }

  // Write the image dimensions to the file
  fwrite(&width, sizeof(int), 1, file);
  fwrite(&height, sizeof(int), 1, file);

  // Write the image data to the file
  fwrite(image, sizeof(unsigned char), width * height, file);

  // Close the file
  fclose(file);

  // Free the memory allocated for the image data
  free(image);

  return 0;
}
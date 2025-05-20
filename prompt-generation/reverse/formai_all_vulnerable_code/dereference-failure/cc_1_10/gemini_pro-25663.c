//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
  int i, j;
  unsigned char temp;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width / 2; j++) {
      temp = image[i * width + j];
      image[i * width + j] = image[i * width + (width - 1 - j)];
      image[i * width + (width - 1 - j)] = temp;
    }
  }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
  int i, j;
  unsigned char temp;

  for (i = 0; i < height / 2; i++) {
    for (j = 0; j < width; j++) {
      temp = image[i * width + j];
      image[i * width + j] = image[(height - 1 - i) * width + j];
      image[(height - 1 - i) * width + j] = temp;
    }
  }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
  int i, j;

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      image[i * width + j] += brightness;

      // Clamp the pixel value to the range [0, 255]
      if (image[i * width + j] < 0) image[i * width + j] = 0;
      if (image[i * width + j] > 255) image[i * width + j] = 255;
    }
  }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
  int i, j;
  float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      image[i * width + j] = (unsigned char)((image[i * width + j] - 128) * factor + 128);

      // Clamp the pixel value to the range [0, 255]
      if (image[i * width + j] < 0) image[i * width + j] = 0;
      if (image[i * width + j] > 255) image[i * width + j] = 255;
    }
  }
}

int main() {
  // Read the image from a file
  FILE *fp = fopen("image.bmp", "rb");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Get the image dimensions
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for the image data
  unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
  if (image == NULL) {
    perror("Error allocating memory");
    return 1;
  }

  // Read the image data from the file
  fread(image, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Flip the image horizontally
  flip_horizontal(image, width, height);

  // Flip the image vertically
  flip_vertical(image, width, height);

  // Change the brightness of the image
  change_brightness(image, width, height, 50);

  // Change the contrast of the image
  change_contrast(image, width, height, 2.0);

  // Write the image to a file
  fp = fopen("output.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Write the image dimensions to the file
  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);

  // Write the image data to the file
  fwrite(image, sizeof(unsigned char), width * height, fp);
  fclose(fp);

  // Free the memory allocated for the image data
  free(image);

  return 0;
}
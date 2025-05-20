//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

int main() {
  // Read the input image
  FILE *fp = fopen("input.bmp", "rb");
  if (fp == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  // Get the dimensions of the image
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  // Allocate memory for the image data
  pixel **image = malloc(sizeof(pixel *) * height);
  for (int i = 0; i < height; i++) {
    image[i] = malloc(sizeof(pixel) * width);
  }

  // Read the image data
  fread(image[0], sizeof(pixel), width * height, fp);
  fclose(fp);

  // Flip the image vertically
  for (int i = 0; i < height / 2; i++) {
    for (int j = 0; j < width; j++) {
      pixel temp = image[i][j];
      image[i][j] = image[height - i - 1][j];
      image[height - i - 1][j] = temp;
    }
  }

  // Change the brightness and contrast of the image
  float brightness = 1.2;
  float contrast = 1.5;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j].r = (image[i][j].r - 128) * contrast + 128;
      image[i][j].g = (image[i][j].g - 128) * contrast + 128;
      image[i][j].b = (image[i][j].b - 128) * contrast + 128;
      image[i][j].r = fmax(0, fmin(255, image[i][j].r * brightness));
      image[i][j].g = fmax(0, fmin(255, image[i][j].g * brightness));
      image[i][j].b = fmax(0, fmin(255, image[i][j].b * brightness));
    }
  }

  // Write the output image
  fp = fopen("output.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  fwrite(&width, sizeof(int), 1, fp);
  fwrite(&height, sizeof(int), 1, fp);
  fwrite(image[0], sizeof(pixel), width * height, fp);
  fclose(fp);

  // Free the memory allocated for the image data
  for (int i = 0; i < height; i++) {
    free(image[i]);
  }
  free(image);

  return 0;
}
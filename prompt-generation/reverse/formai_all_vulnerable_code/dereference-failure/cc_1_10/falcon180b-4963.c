//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_WIDTH 500
#define MAX_HEIGHT 500
#define MAX_VALUE 255
#define MIN_VALUE 0

// Function to read image from file
void readImage(char *filename, int **data, int *width, int *height) {
  FILE *fp;
  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error: Could not open file '%s'\n", filename);
    exit(1);
  }
  fseek(fp, 18, SEEK_SET); // Skip header
  fread(data, sizeof(int), *width * *height, fp);
  fclose(fp);
}

// Function to write image to file
void writeImage(char *filename, int **data, int width, int height) {
  FILE *fp;
  fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error: Could not open file '%s'\n", filename);
    exit(1);
  }
  fwrite(data, sizeof(int), width * height, fp);
  fclose(fp);
}

// Function to flip image horizontally
void flipImageHorizontally(int **data, int width, int height) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width / 2; j++) {
      int temp = data[i][j];
      data[i][j] = data[i][width - j - 1];
      data[i][width - j - 1] = temp;
    }
  }
}

// Function to change brightness and contrast of image
void changeBrightnessContrast(int **data, int width, int height, float brightness, float contrast) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      int value = data[i][j];
      value = (int) ((value - MIN_VALUE) * contrast + MIN_VALUE);
      value = (int) (value + (MAX_VALUE - MIN_VALUE) * brightness);
      value = (value > MAX_VALUE)? MAX_VALUE : (value < MIN_VALUE)? MIN_VALUE : value;
      data[i][j] = value;
    }
  }
}

// Main function to read, process and write image
int main(int argc, char **argv) {
  if (argc!= 6) {
    printf("Usage: %s input_file output_file brightness contrast flip\n", argv[0]);
    return 1;
  }
  char *input_file = argv[1];
  char *output_file = argv[2];
  float brightness = atof(argv[3]);
  float contrast = atof(argv[4]);
  int flip = atoi(argv[5]);
  int **data;
  int width, height;
  readImage(input_file, &data, &width, &height);
  if (flip) {
    flipImageHorizontally(data, width, height);
  }
  changeBrightnessContrast(data, width, height, brightness, contrast);
  writeImage(output_file, data, width, height);
  return 0;
}
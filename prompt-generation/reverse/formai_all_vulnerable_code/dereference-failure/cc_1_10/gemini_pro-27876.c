//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet style image processing functions
void flipImage(unsigned char *image, int width, int height) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width / 2; j++) {
      unsigned char temp = image[i * width + j];
      image[i * width + j] = image[i * width + width - j - 1];
      image[i * width + width - j - 1] = temp;
    }
  }
}

void changeBrightness(unsigned char *image, int width, int height, int brightness) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      int newBrightness = (int)image[i * width + j] + brightness;
      if (newBrightness > 255) {
        newBrightness = 255;
      } else if (newBrightness < 0) {
        newBrightness = 0;
      }
      image[i * width + j] = (unsigned char)newBrightness;
    }
  }
}

void changeContrast(unsigned char *image, int width, int height, int contrast) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      int newContrast = (int)image[i * width + j] * contrast / 100;
      if (newContrast > 255) {
        newContrast = 255;
      } else if (newContrast < 0) {
        newContrast = 0;
      }
      image[i * width + j] = (unsigned char)newContrast;
    }
  }
}

int main() {
  // Romeo and Juliet image declaration
  unsigned char romeo[512][512];
  unsigned char juliet[512][512];

  // Load Romeo and Juliet images
  FILE *romeoFile = fopen("romeo.bmp", "rb");
  FILE *julietFile = fopen("juliet.bmp", "rb");
  if (romeoFile == NULL || julietFile == NULL) {
    printf("Error opening image files.");
    return 1;
  }

  fread(romeo, 512 * 512, 1, romeoFile);
  fread(juliet, 512 * 512, 1, julietFile);

  fclose(romeoFile);
  fclose(julietFile);

  // Flip Juliet's image
  flipImage(juliet, 512, 512);

  // Change Romeo's image brightness
  changeBrightness(romeo, 512, 512, 50);

  // Change Juliet's image contrast
  changeContrast(juliet, 512, 512, 120);

  // Save the processed images
  FILE *romeoProcessedFile = fopen("romeo_processed.bmp", "wb");
  FILE *julietProcessedFile = fopen("juliet_processed.bmp", "wb");
  if (romeoProcessedFile == NULL || julietProcessedFile == NULL) {
    printf("Error saving processed image files.");
    return 1;
  }

  fwrite(romeo, 512 * 512, 1, romeoProcessedFile);
  fwrite(juliet, 512 * 512, 1, julietProcessedFile);

  fclose(romeoProcessedFile);
  fclose(julietProcessedFile);

  printf("Romeo and Juliet images processed and saved successfully.");

  return 0;
}
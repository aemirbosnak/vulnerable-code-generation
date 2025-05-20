//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width;
  int height;
  char *pixels;
} Image;

Image *createImage(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(height * width * sizeof(char));
  return image;
}

void setImagePixel(Image *image, int x, int y, char value) {
  image->pixels[y * image->width + x] = value;
}

char getImagePixel(Image *image, int x, int y) {
  return image->pixels[y * image->width + x];
}

void convertImageToASCII(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      char pixelValue = getImagePixel(image, x, y);
      switch (pixelValue) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf("·");
          break;
        case 2:
          printf(":");
          break;
        case 3:
          printf("#");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  Image *image = createImage(8, 8);
  setImagePixel(image, 0, 0, 2);
  setImagePixel(image, 1, 0, 1);
  setImagePixel(image, 2, 0, 3);
  setImagePixel(image, 3, 0, 2);
  setImagePixel(image, 4, 0, 1);
  setImagePixel(image, 5, 0, 2);
  setImagePixel(image, 6, 0, 3);
  setImagePixel(image, 7, 0, 2);
  setImagePixel(image, 7, 1, 1);

  convertImageToASCII(image);

  free(image->pixels);
  free(image);

  return 0;
}
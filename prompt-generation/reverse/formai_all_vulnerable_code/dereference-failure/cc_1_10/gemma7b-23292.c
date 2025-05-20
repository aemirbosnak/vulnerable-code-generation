//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

typedef struct Image {
  int width;
  int height;
  int *pixels;
} Image;

Image *createImage(int w, int h) {
  Image *image = malloc(sizeof(Image));
  image->width = w;
  image->height = h;
  image->pixels = malloc(w * h * sizeof(int));
  return image;
}

void setImagePixel(Image *image, int x, int y, int r, int g, int b) {
  image->pixels[x + image->width * y] = (r << 16) | (g << 8) | b;
}

void displayImage(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int pixel = image->pixels[x + image->width * y];
      printf("%d ", pixel);
    }
    printf("\n");
  }
}

int main() {
  Image *image = createImage(IMAGE_WIDTH, IMAGE_HEIGHT);
  setImagePixel(image, 100, 100, RED_COLOR, GREEN_COLOR, BLUE_COLOR);
  setImagePixel(image, 200, 200, RED_COLOR, GREEN_COLOR, BLUE_COLOR);
  displayImage(image);

  free(image->pixels);
  free(image);

  return 0;
}
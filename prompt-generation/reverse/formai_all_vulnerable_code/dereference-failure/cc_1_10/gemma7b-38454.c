//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width;
  int height;
  char **pixels;
} Image;

Image *image_create(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(height * sizeof(char *) * width);
  for (int y = 0; y < height; y++) {
    image->pixels[y] = malloc(width * sizeof(char));
  }
  return image;
}

void image_destroy(Image *image) {
  free(image->pixels);
  free(image);
}

void image_set_pixel(Image *image, int x, int y, char value) {
  image->pixels[y][x] = value;
}

char image_get_pixel(Image *image, int x, int y) {
  return image->pixels[y][x];
}

int main() {
  Image *image = image_create(8, 8);
  image_set_pixel(image, 2, 2, 'X');
  image_set_pixel(image, 4, 4, 'O');
  image_set_pixel(image, 6, 6, 'A');

  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      char pixel = image_get_pixel(image, x, y);
      printf("%c ", pixel);
    }
    printf("\n");
  }

  image_destroy(image);

  return 0;
}
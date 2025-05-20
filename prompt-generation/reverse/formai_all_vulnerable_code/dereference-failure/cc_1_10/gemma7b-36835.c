//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

typedef struct Image {
  unsigned int width;
  unsigned int height;
  char **pixels;
} Image;

Image *load_image(const char *filename) {
  Image *image = malloc(sizeof(Image));

  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }

  image->width = 0;
  image->height = 0;
  image->pixels = NULL;

  // Read image data
  fscanf(file, "%d %d", &image->width, &image->height);
  image->pixels = malloc(image->height * image->width * sizeof(char *));
  for (unsigned int y = 0; y < image->height; y++) {
    image->pixels[y] = malloc(image->width * sizeof(char));
    for (unsigned int x = 0; x < image->width; x++) {
      fscanf(file, "%c ", &image->pixels[y][x]);
    }
  }

  fclose(file);

  return image;
}

void convert_image_to_ascii(Image *image) {
  for (unsigned int y = 0; y < image->height; y++) {
    for (unsigned int x = 0; x < image->width; x++) {
      int pixel_value = image->pixels[y][x];
      switch (pixel_value) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf(",");
          break;
        case 3:
          printf("*");
          break;
        case 4:
          printf("#");
          break;
        default:
          printf("!");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  Image *image = load_image("image.jpg");
  convert_image_to_ascii(image);
  free(image);

  return 0;
}
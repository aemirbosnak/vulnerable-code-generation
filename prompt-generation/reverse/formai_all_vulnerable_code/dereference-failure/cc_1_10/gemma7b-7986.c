//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width;
  int height;
  char **pixels;
} Image;

Image *load_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  image->pixels = malloc(MAX_IMAGE_SIZE * sizeof(char *));
  image->width = 0;
  image->height = 0;

  // Load image data from file
  FILE *fp = fopen(filename, "r");
  if (fp) {
    // Get image dimensions
    fscanf(fp, "%d %d", &image->width, &image->height);

    // Allocate pixels
    image->pixels = malloc(image->height * sizeof(char *));
    for (int h = 0; h < image->height; h++) {
      image->pixels[h] = malloc(image->width * sizeof(char));
    }

    // Read image data
    for (int h = 0; h < image->height; h++) {
      for (int w = 0; w < image->width; w++) {
        fscanf(fp, "%c ", &image->pixels[h][w]);
      }
    }

    fclose(fp);
  } else {
    free(image);
    return NULL;
  }

  return image;
}

void convert_image_to_ascii(Image *image) {
  for (int h = 0; h < image->height; h++) {
    for (int w = 0; w < image->width; w++) {
      int pixel_value = image->pixels[h][w];
      switch (pixel_value) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(". ");
          break;
        case 2:
          printf("o ");
          break;
        case 3:
          printf("* ");
          break;
        default:
          printf("X ");
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
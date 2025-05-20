//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width;
  int height;
  unsigned char *data;
} Image;

Image *load_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  image->width = 0;
  image->height = 0;
  image->data = NULL;

  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }

  image->width = fscanf(file, "%d", image->width);
  image->height = fscanf(file, "%d", image->height);
  image->data = malloc(image->width * image->height);
  fread(image->data, image->width * image->height, 1, file);
  fclose(file);

  return image;
}

void convert_image_to_ascii(Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int pixel_value = image->data[y * image->width + x];
      switch (pixel_value) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(". ");
          break;
        case 2:
          printf("* ");
          break;
        case 3:
          printf("# ");
          break;
        default:
          printf("Error!");
          break;
      }
    }
    printf("\n");
  }
}

int main() {
  Image *image = load_image("image.bmp");
  convert_image_to_ascii(image);
  free(image);

  return 0;
}
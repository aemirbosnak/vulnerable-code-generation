//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width, height;
  unsigned char *data;
} Image;

Image *load_image(char *filename) {
  Image *image = malloc(sizeof(Image));
  image->width = image->height = 0;
  image->data = NULL;

  FILE *file = fopen(filename, "rb");
  if (!file) {
    return NULL;
  }

  // Read image size
  image->width = fread(image, sizeof(int), 1, file);
  image->height = fread(image, sizeof(int), 1, file);

  // Allocate image data
  image->data = malloc(image->width * image->height * 3);

  // Read image data
  fread(image->data, image->width * image->height * 3, 1, file);

  fclose(file);

  return image;
}

void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    return;
  }

  // Write image size
  fwrite(&image->width, sizeof(int), 1, file);
  fwrite(&image->height, sizeof(int), 1, file);

  // Write image data
  fwrite(image->data, image->width * image->height * 3, 1, file);

  fclose(file);
}

int main() {
  Image *image = load_image("image.jpg");
  save_image(image, "image_edited.jpg");

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData {
  unsigned char *data;
  int width;
  int height;
} ImageData;

ImageData *readImage(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  // Determine image size
  int width = 0;
  int height = 0;
  fscanf(fp, "width %d height %d", &width, &height);

  // Allocate image data
  ImageData *image = malloc(sizeof(ImageData));
  image->data = malloc(MAX_IMAGE_SIZE);
  image->width = width;
  image->height = height;

  // Read image data
  fread(image->data, MAX_IMAGE_SIZE, 1, fp);

  fclose(fp);
  return image;
}

void convertImageToAscii(ImageData *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int pixelValue = image->data[y * image->width + x];
      switch (pixelValue) {
        case 0:
          printf(" ");
          break;
        case 1:
          printf(".");
          break;
        case 2:
          printf("=");
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
  ImageData *image = readImage("image.jpg");
  convertImageToAscii(image);
  free(image->data);
  free(image);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define PIXEL_SIZE 3
#define ERROR_INVALID_ARGUMENT -1
#define ERROR_CANNOT_OPEN_FILE -2

typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned char *data;
} Image;

int readImage(Image *image, const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    return ERROR_CANNOT_OPEN_FILE;
  }
  fread(&image->width, sizeof(unsigned int), 1, file);
  fread(&image->height, sizeof(unsigned int), 1, file);
  image->data = malloc(image->width * image->height * PIXEL_SIZE);
  fread(image->data, PIXEL_SIZE, image->width * image->height, file);
  fclose(file);
  return 0;
}

void writeImage(Image *image, const char *filename) {
  FILE *file = fopen(filename, "wb");
  fwrite(&image->width, sizeof(unsigned int), 1, file);
  fwrite(&image->height, sizeof(unsigned int), 1, file);
  fwrite(image->data, PIXEL_SIZE, image->width * image->height, file);
  fclose(file);
}

void flipImage(Image *image) {
  unsigned char *temp = malloc(image->width * PIXEL_SIZE);
  for (unsigned int i = 0; i < image->height; i++) {
    memcpy(temp, image->data + i * image->width * PIXEL_SIZE,
           image->width * PIXEL_SIZE);
    memcpy(image->data + i * image->width * PIXEL_SIZE,
           image->data + (image->height - i - 1) * image->width * PIXEL_SIZE,
           image->width * PIXEL_SIZE);
    memcpy(image->data + (image->height - i - 1) * image->width * PIXEL_SIZE, temp,
           image->width * PIXEL_SIZE);
  }
  free(temp);
}

void changeBrightness(Image *image, int amount) {
  for (unsigned int i = 0; i < image->width * image->height * PIXEL_SIZE; i++) {
    image->data[i] += amount;
    if (image->data[i] > 255) {
      image->data[i] = 255;
    } else if (image->data[i] < 0) {
      image->data[i] = 0;
    }
  }
}

void changeContrast(Image *image, int amount) {
  int midpoint = 128;
  for (unsigned int i = 0; i < image->width * image->height * PIXEL_SIZE; i++) {
    image->data[i] = (image->data[i] - midpoint) * amount / 128 + midpoint;
    if (image->data[i] > 255) {
      image->data[i] = 255;
    } else if (image->data[i] < 0) {
      image->data[i] = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return ERROR_INVALID_ARGUMENT;
  }
  Image image;
  if (readImage(&image, argv[1]) != 0) {
    printf("Error: cannot open file %s\n", argv[1]);
    return ERROR_CANNOT_OPEN_FILE;
  }
  flipImage(&image);
  changeBrightness(&image, 50);
  changeContrast(&image, 50);
  writeImage(&image, argv[2]);
  free(image.data);
  return 0;
}
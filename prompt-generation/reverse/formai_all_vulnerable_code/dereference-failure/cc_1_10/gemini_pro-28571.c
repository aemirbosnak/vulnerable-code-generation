//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef unsigned char byte;

typedef unsigned int uint;

typedef struct {
  uint width;
  uint height;
  byte *pixels;
} Image;

Image *read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return NULL;
  }

  Image *image = malloc(sizeof(Image));
  if (image == NULL) {
    fclose(fp);
    return NULL;
  }

  fread(&image->width, sizeof(uint), 1, fp);
  fread(&image->height, sizeof(uint), 1, fp);

  image->pixels = malloc(image->width * image->height * sizeof(byte));
  if (image->pixels == NULL) {
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->pixels, sizeof(byte), image->width * image->height, fp);
  fclose(fp);

  return image;
}

void write_image(const char *filename, Image *image) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    return;
  }

  fwrite(&image->width, sizeof(uint), 1, fp);
  fwrite(&image->height, sizeof(uint), 1, fp);

  fwrite(image->pixels, sizeof(byte), image->width * image->height, fp);
  fclose(fp);
}

void flip_image(Image *image) {
  for (uint y = 0; y < image->height / 2; y++) {
    for (uint x = 0; x < image->width; x++) {
      byte temp = image->pixels[y * image->width + x];
      image->pixels[y * image->width + x] =
          image->pixels[(image->height - 1 - y) * image->width + x];
      image->pixels[(image->height - 1 - y) * image->width + x] = temp;
    }
  }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
  for (uint y = 0; y < image->height; y++) {
    for (uint x = 0; x < image->width; x++) {
      image->pixels[y * image->width + x] =
          (byte)fmin(255,
                      fmax(0, brightness + contrast * image->pixels[y * image->width + x]));
    }
  }
}

int main() {
  Image *image = read_image("input.bmp");
  if (image == NULL) {
    return 1;
  }

  flip_image(image);
  change_brightness_contrast(image, 50, 1.5);
  write_image("output.bmp", image);

  free(image->pixels);
  free(image);

  return 0;
}
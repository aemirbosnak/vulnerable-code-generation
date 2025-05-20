//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned char *data;
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

  fread(&image->width, sizeof(unsigned int), 1, fp);
  fread(&image->height, sizeof(unsigned int), 1, fp);

  image->data = malloc(image->width * image->height * sizeof(unsigned char));
  if (image->data == NULL) {
    free(image);
    fclose(fp);
    return NULL;
  }

  fread(image->data, sizeof(unsigned char), image->width * image->height, fp);

  fclose(fp);

  return image;
}

void write_image(const Image *image, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    return;
  }

  fwrite(&image->width, sizeof(unsigned int), 1, fp);
  fwrite(&image->height, sizeof(unsigned int), 1, fp);

  fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

  fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
  int i, j, k;

  unsigned char w, r, g, b;

  for (i = 0; i < image->width; i++) {
    for (j = 0; j < image->height; j++) {
      w = watermark[i % strlen(watermark)];

      r = image->data[(i * image->width + j) * 3 + 0];
      g = image->data[(i * image->width + j) * 3 + 1];
      b = image->data[(i * image->width + j) * 3 + 2];

      image->data[(i * image->width + j) * 3 + 0] = r + (w & 0b111);
      image->data[(i * image->width + j) * 3 + 1] = g + ((w >> 3) & 0b111);
      image->data[(i * image->width + j) * 3 + 2] = b + ((w >> 6) & 0b111);
    }
  }
}

char *extract_watermark(const Image *image) {
  int i, j, k;

  unsigned char w, r, g, b;

  char *watermark = malloc(image->width * sizeof(char));
  if (watermark == NULL) {
    return NULL;
  }

  for (i = 0; i < image->width; i++) {
    for (j = 0; j < image->height; j++) {
      w = 0;

      r = image->data[(i * image->width + j) * 3 + 0];
      g = image->data[(i * image->width + j) * 3 + 1];
      b = image->data[(i * image->width + j) * 3 + 2];

      w |= (r & 0b111);
      w |= ((g & 0b111) << 3);
      w |= ((b & 0b111) << 6);

      watermark[i] = w;
    }
  }

  return watermark;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <image> <watermark> <output>\n", argv[0]);
    return 1;
  }

  Image *image = read_image(argv[1]);
  if (image == NULL) {
    fprintf(stderr, "Error: could not read image '%s'\n", argv[1]);
    return 1;
  }

  embed_watermark(image, argv[2]);

  write_image(image, argv[3]);

  free(image->data);
  free(image);

  return 0;
}
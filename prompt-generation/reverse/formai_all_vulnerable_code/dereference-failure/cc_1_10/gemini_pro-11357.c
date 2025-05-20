//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  unsigned char r, g, b;
  unsigned char a;
} pixel_t;

typedef struct {
  unsigned int width, height;
  pixel_t *data;
} image_t;

void read_image(image_t *img, const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  if (size % (sizeof(pixel_t))) {
    fprintf(stderr, "Error reading file: invalid file size\n");
    exit(1);
  }
  img->width = size / sizeof(pixel_t);
  img->height = 1;
  img->data = malloc(size);
  if (!img->data) {
    fprintf(stderr, "Error allocating memory for image data\n");
    exit(1);
  }
  fread(img->data, sizeof(pixel_t), img->width, fp);
  fclose(fp);
}

void write_image(const image_t *img, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }
  fwrite(img->data, sizeof(pixel_t), img->width, fp);
  fclose(fp);
}

void invert_image(image_t *img) {
  for (unsigned int i = 0; i < img->width; i++) {
    pixel_t *p = &img->data[i];
    p->r = 255 - p->r;
    p->g = 255 - p->g;
    p->b = 255 - p->b;
  }
}

void grayscale_image(image_t *img) {
  for (unsigned int i = 0; i < img->width; i++) {
    pixel_t *p = &img->data[i];
    unsigned char avg = (p->r + p->g + p->b) / 3;
    p->r = avg;
    p->g = avg;
    p->b = avg;
  }
}

void rotate_image(image_t *img) {
  unsigned int width = img->width;
  unsigned int height = img->height;
  pixel_t *rotated_data = malloc(width * height * sizeof(pixel_t));
  if (!rotated_data) {
    fprintf(stderr, "Error allocating memory for rotated image data\n");
    exit(1);
  }
  for (unsigned int i = 0; i < width; i++) {
    for (unsigned int j = 0; j < height; j++) {
      rotated_data[j * width + i] = img->data[i * height + j];
    }
  }
  free(img->data);
  img->data = rotated_data;
  img->width = height;
  img->height = width;
}

void flip_image(image_t *img) {
  unsigned int width = img->width;
  unsigned int height = img->height;
  pixel_t *flipped_data = malloc(width * height * sizeof(pixel_t));
  if (!flipped_data) {
    fprintf(stderr, "Error allocating memory for flipped image data\n");
    exit(1);
  }
  for (unsigned int i = 0; i < width; i++) {
    for (unsigned int j = 0; j < height; j++) {
      flipped_data[i * height + j] = img->data[(width - 1 - i) * height + j];
    }
  }
  free(img->data);
  img->data = flipped_data;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    exit(1);
  }
  image_t img;
  read_image(&img, argv[1]);
  invert_image(&img);
  grayscale_image(&img);
  rotate_image(&img);
  flip_image(&img);
  write_image(&img, "edited_image.ppm");
  free(img.data);
  return 0;
}
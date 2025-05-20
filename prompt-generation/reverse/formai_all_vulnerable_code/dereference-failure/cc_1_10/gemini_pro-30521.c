//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

unsigned char clamp(float color) {
  if (color < 0)
    return 0;
  if (color > 255)
    return 255;
  return (unsigned char)color;
}

pixel *read_image(char *filename, int *width, int *height) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    return NULL;
  }
  char header[54];
  fread(header, sizeof(header), 1, fp);
  *width = *(int *)&header[18];
  *height = *(int *)&header[22];
  int size = *width * *height * 3;
  pixel *data = malloc(size);
  if (!data) {
    perror("malloc");
    fclose(fp);
    return NULL;
  }
  fread(data, size, 1, fp);
  fclose(fp);
  return data;
}

void write_image(char *filename, pixel *data, int width, int height) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) {
    perror("fopen");
    return;
  }
  char header[54] = {
      0x42, 0x4D, 0x36, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x04, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
      width & 0xFF, (width >> 8) & 0xFF, (width >> 16) & 0xFF, (width >> 24) & 0xFF, height & 0xFF, (height >> 8) & 0xFF,
      (height >> 16) & 0xFF, (height >> 24) & 0xFF, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x3C,
      0x00, 0x00, 0xC0, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  fwrite(header, sizeof(header), 1, fp);
  fwrite(data, width * height * 3, 1, fp);
  fclose(fp);
}

void flip_horizontal(pixel *data, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width / 2; x++) {
      int i1 = y * width + x;
      int i2 = y * width + (width - x - 1);
      pixel tmp = data[i1];
      data[i1] = data[i2];
      data[i2] = tmp;
    }
  }
}

void flip_vertical(pixel *data, int width, int height) {
  for (int y = 0; y < height / 2; y++) {
    for (int x = 0; x < width; x++) {
      int i1 = y * width + x;
      int i2 = (height - y - 1) * width + x;
      pixel tmp = data[i1];
      data[i1] = data[i2];
      data[i2] = tmp;
    }
  }
}

void adjust_brightness(pixel *data, int width, int height, float brightness) {
  for (int i = 0; i < width * height; i++) {
    data[i].r = clamp(data[i].r * brightness);
    data[i].g = clamp(data[i].g * brightness);
    data[i].b = clamp(data[i].b * brightness);
  }
}

void adjust_contrast(pixel *data, int width, int height, float contrast) {
  float f = (259 * (contrast + 255)) / (255 * (259 - contrast));
  for (int i = 0; i < width * height; i++) {
    data[i].r = clamp(f * (data[i].r - 128) + 128);
    data[i].g = clamp(f * (data[i].g - 128) + 128);
    data[i].b = clamp(f * (data[i].b - 128) + 128);
  }
}

int main() {
  int width, height;
  pixel *data = read_image("image.bmp", &width, &height);
  if (!data)
    return 1;
  flip_horizontal(data, width, height);
  adjust_brightness(data, width, height, 1.2);
  adjust_contrast(data, width, height, 1.5);
  flip_vertical(data, width, height);
  write_image("output.bmp", data, width, height);
  free(data);
  return 0;
}
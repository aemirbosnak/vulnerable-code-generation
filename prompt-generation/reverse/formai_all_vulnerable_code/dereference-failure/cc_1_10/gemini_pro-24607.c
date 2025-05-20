//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint32_t width, height;
  uint8_t *data;
} Image;

Image *new_image(uint32_t width, uint32_t height) {
  Image *img = malloc(sizeof(Image));
  img->width = width;
  img->height = height;
  img->data = malloc(width * height * sizeof(uint8_t));
  return img;
}

void free_image(Image *img) {
  free(img->data);
  free(img);
}

void save_image(Image *img, char *filename) {
  FILE *f = fopen(filename, "wb");
  fwrite(&img->width, sizeof(uint32_t), 1, f);
  fwrite(&img->height, sizeof(uint32_t), 1, f);
  fwrite(img->data, sizeof(uint8_t), img->width * img->height, f);
  fclose(f);
}

void load_image(Image *img, char *filename) {
  FILE *f = fopen(filename, "rb");
  fread(&img->width, sizeof(uint32_t), 1, f);
  fread(&img->height, sizeof(uint32_t), 1, f);
  img->data = malloc(img->width * img->height * sizeof(uint8_t));
  fread(img->data, sizeof(uint8_t), img->width * img->height, f);
  fclose(f);
}

void invert_image(Image *img) {
  for (uint32_t i = 0; i < img->width * img->height; i++) {
    img->data[i] = 255 - img->data[i];
  }
}

void grayscale_image(Image *img) {
  for (uint32_t i = 0; i < img->width * img->height; i++) {
    uint8_t avg = (img->data[i] + img->data[i + 1] + img->data[i + 2]) / 3;
    img->data[i] = avg;
    img->data[i + 1] = avg;
    img->data[i + 2] = avg;
  }
}

void blur_image(Image *img, int radius) {
  uint8_t *tmp = malloc(img->width * img->height * sizeof(uint8_t));
  for (uint32_t i = 0; i < img->width * img->height; i++) {
    tmp[i] = img->data[i];
  }
  for (uint32_t y = 0; y < img->height; y++) {
    for (uint32_t x = 0; x < img->width; x++) {
      int sum = 0;
      for (int j = -radius; j <= radius; j++) {
        for (int i = -radius; i <= radius; i++) {
          int nx = x + i;
          int ny = y + j;
          if (nx >= 0 && nx < img->width && ny >= 0 && ny < img->height) {
            sum += tmp[ny * img->width + nx];
          }
        }
      }
      img->data[y * img->width + x] = sum / ((2 * radius + 1) * (2 * radius + 1));
    }
  }
  free(tmp);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  Image *img = new_image(100, 100);
  load_image(img, argv[1]);
  invert_image(img);
  grayscale_image(img);
  blur_image(img, 2);
  save_image(img, "output.bmp");
  free_image(img);
  return 0;
}
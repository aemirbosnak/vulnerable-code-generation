//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct img {
  uint32_t w;
  uint32_t h;
  uint8_t *data;
};

static struct img *open_img(const char *name) {
  FILE *f = fopen(name, "rb");
  if (!f) return NULL;
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  fseek(f, 0, SEEK_SET);
  struct img *img = malloc(sizeof(struct img) + size);
  if (!img) {
    fclose(f);
    return NULL;
  }
  img->data = (uint8_t *)(img + 1);
  fread(img->data, 1, size, f);
  fclose(f);
  return img;
}

static int save_img(struct img *img, const char *name) {
  FILE *f = fopen(name, "wb");
  if (!f) return -1;
  fwrite(img->data, 1, img->w * img->h * 3, f);
  fclose(f);
  return 0;
}

static void flip_img(struct img *img) {
  for (uint32_t y = 0; y < img->h / 2; y++) {
    for (uint32_t x = 0; x < img->w; x++) {
      for (uint32_t c = 0; c < 3; c++) {
        uint8_t tmp = img->data[y * img->w * 3 + x * 3 + c];
        img->data[y * img->w * 3 + x * 3 + c] =
            img->data[(img->h - y - 1) * img->w * 3 + x * 3 + c];
        img->data[(img->h - y - 1) * img->w * 3 + x * 3 + c] = tmp;
      }
    }
  }
}

static void adjust_brightness(struct img *img, int brightness) {
  for (uint32_t y = 0; y < img->h; y++) {
    for (uint32_t x = 0; x < img->w; x++) {
      for (uint32_t c = 0; c < 3; c++) {
        int v = img->data[y * img->w * 3 + x * 3 + c] + brightness;
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        img->data[y * img->w * 3 + x * 3 + c] = v;
      }
    }
  }
}

static void adjust_contrast(struct img *img, float contrast) {
  for (uint32_t y = 0; y < img->h; y++) {
    for (uint32_t x = 0; x < img->w; x++) {
      for (uint32_t c = 0; c < 3; c++) {
        int v = img->data[y * img->w * 3 + x * 3 + c] * contrast;
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        img->data[y * img->w * 3 + x * 3 + c] = v;
      }
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <image.bmp>\n", argv[0]);
    return 1;
  }

  char *name = argv[1];

  struct img *img = open_img(name);
  if (!img) {
    printf("Error: Failed to open image %s\n", name);
    return 1;
  }

  if (img->w % 4 != 0) {
    printf("Error: Image width is not a multiple of 4\n");
    return 1;
  }

  flip_img(img);
  adjust_brightness(img, 30);
  adjust_contrast(img, 1.2);

  char *out_name = strchr(name, '.') ? strndup(name, strchr(name, '.') - name) : name;
  char *out_bmp_name = malloc(strlen(out_name) + 5);
  sprintf(out_bmp_name, "%s.bmp", out_name);

  if (save_img(img, out_bmp_name) != 0) {
    printf("Error: Failed to save image %s\n", out_bmp_name);
    return 1;
  }

  free(img);
  free(out_name);
  free(out_bmp_name);

  return 0;
}
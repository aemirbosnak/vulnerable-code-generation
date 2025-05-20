//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned char r, g, b;
} pixel;

typedef struct {
  unsigned int width, height;
  pixel *data;
} image;

image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  char header[256];
  if (!fread(header, 1, 256, fp)) {
    fclose(fp);
    return NULL;
  }

  if (strncmp(header, "BM", 2) != 0) {
    fclose(fp);
    return NULL;
  }

  unsigned int width, height, bitdepth;
  if (!fread(&width, 4, 1, fp)) {
    fclose(fp);
    return NULL;
  }
  if (!fread(&height, 4, 1, fp)) {
    fclose(fp);
    return NULL;
  }
  if (!fread(&bitdepth, 2, 1, fp)) {
    fclose(fp);
    return NULL;
  }

  if (bitdepth != 24) {
    fclose(fp);
    return NULL;
  }

  unsigned int padding = (4 - (width * 3) % 4) % 4;
  unsigned int data_size = width * height * 3 + padding * height;

  pixel *data = malloc(data_size);
  if (!data) {
    fclose(fp);
    return NULL;
  }

  if (!fread(data, 1, data_size, fp)) {
    fclose(fp);
    free(data);
    return NULL;
  }

  fclose(fp);

  image *img = malloc(sizeof(image));
  if (!img) {
    free(data);
    return NULL;
  }

  img->width = width;
  img->height = height;
  img->data = data;

  return img;
}

void save_image(const image *img, const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (!fp) return;

  fwrite("BM", 1, 2, fp);
  fwrite(&img->width, 4, 1, fp);
  fwrite(&img->height, 4, 1, fp);
  fwrite("\0\0", 2, 1, fp);
  fwrite("\x18\x00", 2, 1, fp);
  fwrite("\x00\x00\x00\x00", 4, 1, fp);
  fwrite("\x00\x00\x00\x00", 4, 1, fp);
  fwrite("\x00\x00\x00\x00", 4, 1, fp);
  fwrite("\x00\x00\x00\x00", 4, 1, fp);
  fwrite("\x00\x00\x00\x00", 4, 1, fp);

  unsigned int padding = (4 - (img->width * 3) % 4) % 4;
  unsigned int data_size = img->width * img->height * 3 + padding * img->height;

  fwrite(img->data, 1, data_size, fp);

  fclose(fp);
}

image *invert_image(const image *img) {
  image *new_img = malloc(sizeof(image));
  if (!new_img) return NULL;

  new_img->width = img->width;
  new_img->height = img->height;
  new_img->data = malloc(img->width * img->height * 3);
  if (!new_img->data) {
    free(new_img);
    return NULL;
  }

  for (unsigned int i = 0; i < img->width * img->height; i++) {
    new_img->data[i].r = 255 - img->data[i].r;
    new_img->data[i].g = 255 - img->data[i].g;
    new_img->data[i].b = 255 - img->data[i].b;
  }

  return new_img;
}

image *resize_image(const image *img, unsigned int new_width, unsigned int new_height) {
  image *new_img = malloc(sizeof(image));
  if (!new_img) return NULL;

  new_img->width = new_width;
  new_img->height = new_height;
  new_img->data = malloc(new_img->width * new_img->height * 3);
  if (!new_img->data) {
    free(new_img);
    return NULL;
  }

  for (unsigned int y = 0; y < new_img->height; y++) {
    for (unsigned int x = 0; x < new_img->width; x++) {
      unsigned int old_x = x * img->width / new_img->width;
      unsigned int old_y = y * img->height / new_img->height;
      new_img->data[y * new_img->width + x] = img->data[old_y * img->width + old_x];
    }
  }

  return new_img;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <input_image> <output_image>\n", argv[0]);
    return 1;
  }

  image *img = load_image(argv[1]);
  if (!img) {
    printf("Error loading image: %s\n", argv[1]);
    return 1;
  }

  image *new_img = invert_image(img);
  if (!new_img) {
    printf("Error inverting image\n");
    free(img);
    return 1;
  }

  new_img = resize_image(new_img, 2 * new_img->width, 2 * new_img->height);
  if (!new_img) {
    printf("Error resizing image\n");
    free(img);
    free(new_img);
    return 1;
  }

  save_image(new_img, argv[2]);
  if (!new_img) {
    printf("Error saving image: %s\n", argv[2]);
    free(img);
    free(new_img);
    return 1;
  }

  free(img);
  free(new_img);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265

typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

Image *load_image(const char *filename) {
  Image *image = malloc(sizeof(Image));
  if (!image) {
    fprintf(stderr, "Error: malloc failed\n");
    return NULL;
  }
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    fprintf(stderr, "Error: fopen failed\n");
    free(image);
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  image->data = malloc(size);
  if (!image->data) {
    fprintf(stderr, "Error: malloc failed\n");
    fclose(fp);
    free(image);
    return NULL;
  }
  fread(image->data, size, 1, fp);
  fclose(fp);
  return image;
}

void free_image(Image *image) {
  if (!image) {
    return;
  }
  free(image->data);
  free(image);
}

void embed_watermark(Image *image, const char *watermark, double alpha) {
  int watermark_length = strlen(watermark);
  for (int i = 0; i < watermark_length; i++) {
    int bit = watermark[i] - '0';
    for (int j = 0; j < 8; j++) {
      int bitmask = 1 << (7 - j);
      int offset = i * 8 + j;
      int index = offset / 2;
      int channel = offset % 2;
      if (bit & bitmask) {
        image->data[index] |= channel ? 0x01 : 0x02;
      } else {
        image->data[index] &= ~channel ? 0xfe : 0xfd;
      }
    }
  }
}

char *extract_watermark(Image *image, double alpha) {
  int watermark_length = (image->width * image->height) / 64;
  char *watermark = malloc(watermark_length + 1);
  if (!watermark) {
    fprintf(stderr, "Error: malloc failed\n");
    return NULL;
  }
  for (int i = 0; i < watermark_length; i++) {
    int bitmask = 1 << (7 - (i % 8));
    int offset = i / 8;
    int index = offset / 2;
    int channel = offset % 2;
    watermark[i] = (image->data[index] & channel ? 0x01 : 0x02) >> (7 - (i % 8)) + '0';
  }
  watermark[watermark_length] = '\0';
  return watermark;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s [image.bmp] [watermark]\n", argv[0]);
    return 1;
  }
  Image *image = load_image(argv[1]);
  if (!image) {
    return 1;
  }
  char *watermark = argv[2];
  embed_watermark(image, watermark, 0.5);
  char *extracted_watermark = extract_watermark(image, 0.5);
  printf("Extracted watermark: %s\n", extracted_watermark);
  free_image(image);
  free(extracted_watermark);
  return 0;
}
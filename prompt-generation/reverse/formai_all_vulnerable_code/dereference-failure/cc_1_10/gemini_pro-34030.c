//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024 * 3

unsigned char *image;
int image_width, image_height;
unsigned char *watermark;
int watermark_width, watermark_height;

void load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  fread(&image_width, sizeof(int), 1, fp);
  fread(&image_height, sizeof(int), 1, fp);
  image = malloc(image_width * image_height * 3);
  fread(image, image_width * image_height * 3, 1, fp);
  fclose(fp);
}

void load_watermark(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening watermark file");
    exit(1);
  }

  fread(&watermark_width, sizeof(int), 1, fp);
  fread(&watermark_height, sizeof(int), 1, fp);
  watermark = malloc(watermark_width * watermark_height);
  fread(watermark, watermark_width * watermark_height, 1, fp);
  fclose(fp);
}

void embed_watermark() {
  int i, j, k;
  for (i = 0; i < watermark_height; i++) {
    for (j = 0; j < watermark_width; j++) {
      k = (i * watermark_width + j) * 3;
      image[k] = (image[k] & 0xfe) | ((watermark[i * watermark_width + j] >> 7) & 0x01);
      image[k + 1] = (image[k + 1] & 0xfe) | ((watermark[i * watermark_width + j] >> 6) & 0x01);
      image[k + 2] = (image[k + 2] & 0xfe) | ((watermark[i * watermark_width + j] >> 5) & 0x01);
    }
  }
}

void extract_watermark() {
  int i, j, k;
  unsigned char *extracted_watermark = malloc(watermark_width * watermark_height);
  for (i = 0; i < watermark_height; i++) {
    for (j = 0; j < watermark_width; j++) {
      k = (i * watermark_width + j) * 3;
      extracted_watermark[i * watermark_width + j] = ((image[k] & 0x01) << 7) | ((image[k + 1] & 0x01) << 6) | ((image[k + 2] & 0x01) << 5);
    }
  }

  FILE *fp = fopen("extracted_watermark.bmp", "wb");
  if (fp == NULL) {
    perror("Error opening extracted watermark file");
    exit(1);
  }

  fwrite(&watermark_width, sizeof(int), 1, fp);
  fwrite(&watermark_height, sizeof(int), 1, fp);
  fwrite(extracted_watermark, watermark_width * watermark_height, 1, fp);
  fclose(fp);
}

void save_image(const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Error opening output image file");
    exit(1);
  }

  fwrite(&image_width, sizeof(int), 1, fp);
  fwrite(&image_height, sizeof(int), 1, fp);
  fwrite(image, image_width * image_height * 3, 1, fp);
  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <image_file> <watermark_file> <output_image_file> <extract_watermark>\n", argv[0]);
    exit(1);
  }

  load_image(argv[1]);
  load_watermark(argv[2]);
  if (strcmp(argv[4], "yes") == 0) {
    embed_watermark();
  } else if (strcmp(argv[4], "no") == 0) {
    extract_watermark();
  } else {
    fprintf(stderr, "Invalid extract_watermark argument. Use \"yes\" or \"no\"\n");
    exit(1);
  }
  save_image(argv[3]);

  free(image);
  free(watermark);

  return 0;
}
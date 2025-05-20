//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

unsigned char image[IMAGE_WIDTH][IMAGE_HEIGHT];
unsigned char watermark[IMAGE_WIDTH][IMAGE_HEIGHT];

void read_image(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening image file");
    exit(1);
  }

  fread(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT, fp);
  fclose(fp);
}

void read_watermark(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("Error opening watermark file");
    exit(1);
  }

  fread(watermark, 1, IMAGE_WIDTH * IMAGE_HEIGHT, fp);
  fclose(fp);
}

void embed_watermark() {
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      // Embed the watermark bit in the least significant bit of the image pixel
      image[i][j] &= ~(1 << 0);
      image[i][j] |= (watermark[i][j] & 1) << 0;
    }
  }
}

void extract_watermark() {
  for (int i = 0; i < IMAGE_WIDTH; i++) {
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
      // Extract the watermark bit from the least significant bit of the image pixel
      watermark[i][j] = (image[i][j] & 1) << 7;
    }
  }
}

void save_image(char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Error opening output image file");
    exit(1);
  }

  fwrite(image, 1, IMAGE_WIDTH * IMAGE_HEIGHT, fp);
  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <image file> <watermark file> <output image file> <extract (0/1)>\n", argv[0]);
    exit(1);
  }

  read_image(argv[1]);
  read_watermark(argv[2]);

  if (atoi(argv[4]) == 0) {
    embed_watermark();
  } else {
    extract_watermark();
  }

  save_image(argv[3]);

  return 0;
}
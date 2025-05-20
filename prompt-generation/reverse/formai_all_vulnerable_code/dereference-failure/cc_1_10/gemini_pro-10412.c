//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Maximum image size
#define MAX_SIZE 1024

// Watermark size
#define WM_SIZE 64

// Watermark data
static unsigned char watermark[WM_SIZE][WM_SIZE];

// Load the watermark from a file
void load_watermark(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open watermark file %s\n", filename);
    exit(1);
  }

  fread(watermark, sizeof(watermark), 1, fp);
  fclose(fp);
}

// Embed the watermark in the image
void embed_watermark(unsigned char *image, int width, int height) {
  // Calculate the number of watermark blocks that can fit in the image
  int num_blocks_x = width / WM_SIZE;
  int num_blocks_y = height / WM_SIZE;

  // Embed the watermark in the image
  for (int i = 0; i < num_blocks_x; i++) {
    for (int j = 0; j < num_blocks_y; j++) {
      // Get the image block
      unsigned char *block = image + (j * width + i) * WM_SIZE;

      // Embed the watermark in the image block
      for (int k = 0; k < WM_SIZE; k++) {
        for (int l = 0; l < WM_SIZE; l++) {
          block[k * WM_SIZE + l] += watermark[k][l];
        }
      }
    }
  }
}

// Extract the watermark from the image
void extract_watermark(unsigned char *image, int width, int height) {
  // Calculate the number of watermark blocks that can fit in the image
  int num_blocks_x = width / WM_SIZE;
  int num_blocks_y = height / WM_SIZE;

  // Extract the watermark from the image
  for (int i = 0; i < num_blocks_x; i++) {
    for (int j = 0; j < num_blocks_y; j++) {
      // Get the image block
      unsigned char *block = image + (j * width + i) * WM_SIZE;

      // Extract the watermark from the image block
      for (int k = 0; k < WM_SIZE; k++) {
        for (int l = 0; l < WM_SIZE; l++) {
          watermark[k][l] += block[k * WM_SIZE + l];
        }
      }
    }
  }
}

// Save the watermark to a file
void save_watermark(const char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open watermark file %s\n", filename);
    exit(1);
  }

  fwrite(watermark, sizeof(watermark), 1, fp);
  fclose(fp);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <input image> <output image> <watermark file> <embed/extract>\n", argv[0]);
    exit(1);
  }

  // Load the image
  unsigned char *image = malloc(MAX_SIZE * MAX_SIZE);
  if (image == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image\n");
    exit(1);
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open input image file %s\n", argv[1]);
    exit(1);
  }

  fread(image, MAX_SIZE * MAX_SIZE, 1, fp);
  fclose(fp);

  // Get the image width and height
  int width, height;
  fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open input image file %s\n", argv[1]);
    exit(1);
  }

  fscanf(fp, "P2\n%d %d\n255\n", &width, &height);
  fclose(fp);

  // Load the watermark
  load_watermark(argv[3]);

  // Embed or extract the watermark
  if (strcmp(argv[4], "embed") == 0) {
    embed_watermark(image, width, height);
  } else if (strcmp(argv[4], "extract") == 0) {
    extract_watermark(image, width, height);
  } else {
    fprintf(stderr, "Error: invalid operation %s\n", argv[4]);
    exit(1);
  }

  // Save the image
  fp = fopen(argv[2], "wb");
  if (fp == NULL) {
    fprintf(stderr, "Error: could not open output image file %s\n", argv[2]);
    exit(1);
  }

  fprintf(fp, "P2\n%d %d\n255\n", width, height);
  fwrite(image, MAX_SIZE * MAX_SIZE, 1, fp);
  fclose(fp);

  // Free the image
  free(image);

  return 0;
}
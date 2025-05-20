//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char byte;

// Read the image data from a file
byte* readImage(const char* filename, int* width, int* height) {
  FILE* f = fopen(filename, "rb");
  if (f == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  // Read the header
  byte header[54];
  if (fread(header, 1, 54, f) != 54) {
    fprintf(stderr, "Error: could not read header from file %s\n", filename);
    exit(1);
  }

  // Check the header
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
    exit(1);
  }

  // Get the width and height
  *width = *(int*)&header[18];
  *height = *(int*)&header[22];

  // Read the image data
  byte* data = malloc(*width * *height * 3);
  if (data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    exit(1);
  }

  if (fread(data, 1, *width * *height * 3, f) != *width * *height * 3) {
    fprintf(stderr, "Error: could not read image data from file %s\n", filename);
    exit(1);
  }

  fclose(f);

  return data;
}

// Write the image data to a file
void writeImage(const char* filename, byte* data, int width, int height) {
  FILE* f = fopen(filename, "wb");
  if (f == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", filename);
    exit(1);
  }

  // Write the header
  byte header[54];
  header[0] = 'B';
  header[1] = 'M';
  *(int*)&header[2] = 54 + width * height * 3;
  *(int*)&header[10] = 54;
  *(int*)&header[14] = 40;
  *(int*)&header[18] = width;
  *(int*)&header[22] = height;
  *(short*)&header[26] = 1;
  *(short*)&header[28] = 24;
  *(int*)&header[30] = 0;
  *(int*)&header[34] = width * height * 3;
  *(int*)&header[38] = 2835;
  *(int*)&header[42] = 2835;
  *(int*)&header[46] = 0;
  *(int*)&header[50] = 0;

  if (fwrite(header, 1, 54, f) != 54) {
    fprintf(stderr, "Error: could not write header to file %s\n", filename);
    exit(1);
  }

  // Write the image data
  if (fwrite(data, 1, width * height * 3, f) != width * height * 3) {
    fprintf(stderr, "Error: could not write image data to file %s\n", filename);
    exit(1);
  }

  fclose(f);
}

// Embed the watermark in the image data
void embedWatermark(byte* data, int width, int height, const char* watermark) {
  int watermarkLength = strlen(watermark);

  // Spread the watermark over the image data
  for (int i = 0; i < watermarkLength; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = (watermark[i] >> j) & 1;
      data[i * width * 8 + j] = (data[i * width * 8 + j] & ~1) | bit;
    }
  }
}

// Extract the watermark from the image data
char* extractWatermark(byte* data, int width, int height) {
  int watermarkLength = width * height / 8;
  char* watermark = malloc(watermarkLength + 1);
  if (watermark == NULL) {
    fprintf(stderr, "Error: could not allocate memory for watermark\n");
    exit(1);
  }

  // Extract the watermark from the image data
  for (int i = 0; i < watermarkLength; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = data[i * width * 8 + j] & 1;
      watermark[i] |= (bit << j);
    }
  }

  watermark[watermarkLength] = '\0';

  return watermark;
}

// Print the usage information
void usage(const char* programName) {
  fprintf(stderr, "Usage: %s <input image> <output image> <watermark>\n", programName);
  exit(1);
}

int main(int argc, char** argv) {
  // Check the arguments
  if (argc != 4) {
    usage(argv[0]);
  }

  // Read the input image
  int width, height;
  byte* data = readImage(argv[1], &width, &height);

  // Embed the watermark in the image data
  embedWatermark(data, width, height, argv[3]);

  // Write the output image
  writeImage(argv[2], data, width, height);

  // Extract the watermark from the output image
  char* watermark = extractWatermark(data, width, height);

  // Print the extracted watermark
  printf("Extracted watermark: %s\n", watermark);

  // Free the allocated memory
  free(data);
  free(watermark);

  return 0;
}
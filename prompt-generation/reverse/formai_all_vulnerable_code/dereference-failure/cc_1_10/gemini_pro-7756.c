//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_ASCII_ART_SIZE 1024

typedef unsigned char byte;

// Convert an image to grayscale
void to_grayscale(byte *image, int width, int height) {
  for (int i = 0; i < width * height; i++) {
    byte r = image[i * 3 + 0];
    byte g = image[i * 3 + 1];
    byte b = image[i * 3 + 2];
    byte gray = (r + g + b) / 3;
    image[i * 3 + 0] = gray;
    image[i * 3 + 1] = gray;
    image[i * 3 + 2] = gray;
  }
}

// Convert an image to ASCII art
void to_ascii_art(byte *image, int width, int height, char *ascii_art) {
  const char *characters = "@%#*+=-:. ";
  for (int i = 0; i < width * height; i++) {
    byte gray = image[i * 3 + 0];
    int index = (int) gray / 16;
    ascii_art[i] = characters[index];
  }
}

// Read an image from a file
byte *read_image(char *filename, int *width, int *height) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file '%s'\n", filename);
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);
  byte *data = malloc(size);
  if (data == NULL) {
    fprintf(stderr, "Error: could not allocate memory for image data\n");
    fclose(file);
    return NULL;
  }
  fread(data, 1, size, file);
  fclose(file);
  if (data[0] == 'B' && data[1] == 'M') {  // BMP format
    *width = *(int *) &data[18];
    *height = *(int *) &data[22];
    return data + 54;
  } else if (data[0] == 'P' && data[1] == '6') {  // PPM format
    char header[1024];
    fgets(header, 1024, file);
    while (header[0] == '#') {  // Skip comments
      fgets(header, 1024, file);
    }
    sscanf(header, "%d %d", width, height);
    return data + strlen(header);
  } else {
    fprintf(stderr, "Error: unsupported image format\n");
    free(data);
    return NULL;
  }
}

// Write an image to a file
void write_image(char *filename, byte *image, int width, int height) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    fprintf(stderr, "Error: could not open file '%s'\n", filename);
    return;
  }
  fprintf(file, "P6\n%d %d\n255\n", width, height);
  fwrite(image, 1, width * height * 3, file);
  fclose(file);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input image> <output ASCII art>\n", argv[0]);
    return 1;
  }
  int width, height;
  byte *image = read_image(argv[1], &width, &height);
  if (image == NULL) {
    return 1;
  }
  to_grayscale(image, width, height);
  char *ascii_art = malloc(width * height + 1);
  if (ascii_art == NULL) {
    fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
    free(image);
    return 1;
  }
  to_ascii_art(image, width, height, ascii_art);
  write_image(argv[2], (byte *) ascii_art, width, height);
  free(image);
  free(ascii_art);
  return 0;
}
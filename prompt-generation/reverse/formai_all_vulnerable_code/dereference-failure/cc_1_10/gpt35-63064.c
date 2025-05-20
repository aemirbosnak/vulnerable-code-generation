//FormAI DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grayscale(char* filename);
void invert(char* filename);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <image> <option>\nOptions:\n  -g  Convert to grayscale\n  -i  Invert colors\n", argv[0]);
    exit(1);
  } else {
    char* filename = argv[1];
    char* option = argv[2];

    if (strcmp(option, "-g") == 0) {
      grayscale(filename);
    } else if (strcmp(option, "-i") == 0) {
      invert(filename);
    } else {
      printf("Invalid option: %s\nOptions:\n  -g  Convert to grayscale\n  -i  Invert colors\n", option);
      exit(1);
    }
  }

  return 0;
}

void grayscale(char* filename) {
  FILE* img = fopen(filename, "rb");

  if (img == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Read header
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, img);

  // Get image width and height
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Calculate row padding
  int padding = 4 - (width * 3) % 4;

  // Get image data
  unsigned char data[height][width * 3 + padding];
  for (int i = 0; i < height; i++) {
    fread(data[i], sizeof(unsigned char), width * 3 + padding, img);
  }

  fclose(img);

  // Convert to grayscale
  unsigned char grayscale[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      unsigned char r = data[i][j * 3 + 2];
      unsigned char g = data[i][j * 3 + 1];
      unsigned char b = data[i][j * 3];

      grayscale[i][j] = 0.299 * r + 0.587 * g + 0.114 * b;
    }
  }

  // Write grayscale image
  char* newfilename = malloc(strlen(filename) + 10);
  sprintf(newfilename, "grayscale_%s", filename);
  FILE* newimg = fopen(newfilename, "wb");
  fwrite(header, sizeof(unsigned char), 54, newimg);
  for (int i = 0; i < height; i++) {
    fwrite(grayscale[i], sizeof(unsigned char), width, newimg);
    unsigned char padding_data[padding];
    memset(padding_data, 0, padding);
    fwrite(padding_data, sizeof(unsigned char), padding, newimg);
  }
  fclose(newimg);

  printf("Grayscale image saved as %s\n", newfilename);
}

void invert(char* filename) {
  FILE* img = fopen(filename, "rb");

  if (img == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  // Read header
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, img);

  // Get image width and height
  int width = *(int*)&header[18];
  int height = *(int*)&header[22];

  // Calculate row padding
  int padding = 4 - (width * 3) % 4;

  // Get image data
  unsigned char data[height][width * 3 + padding];
  for (int i = 0; i < height; i++) {
    fread(data[i], sizeof(unsigned char), width * 3 + padding, img);
  }

  fclose(img);

  // Invert colors
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      data[i][j * 3] = 255 - data[i][j * 3];
      data[i][j * 3 + 1] = 255 - data[i][j * 3 + 1];
      data[i][j * 3 + 2] = 255 - data[i][j * 3 + 2];
    }
  }

  // Write inverted image
  char* newfilename = malloc(strlen(filename) + 10);
  sprintf(newfilename, "inverted_%s", filename);
  FILE* newimg = fopen(newfilename, "wb");
  fwrite(header, sizeof(unsigned char), 54, newimg);
  for (int i = 0; i < height; i++) {
    fwrite(data[i], sizeof(unsigned char), width * 3 + padding, newimg);
  }
  fclose(newimg);

  printf("Inverted image saved as %s\n", newfilename);
}
//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char ascii[MAX_WIDTH][MAX_HEIGHT];

void convert(unsigned char image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int pixel = image[j][i];
      char c = ' ';
      
      if (pixel < 64) {
        c = '.';
      } else if (pixel < 128) {
        c = ':';
      } else if (pixel < 192) {
        c = '1';
      } else if (pixel < 256) {
        c = '|';
      }
      
      ascii[j][i] = c;
    }
  }
}

void print_ascii(int width, int height) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      putchar(ascii[j][i]);
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <path/to/image>\n", argv[0]);
    return 1;
  }

  char *path = argv[1];
  FILE *file = fopen(path, "rb");
  if (!file) {
    printf("Failed to open file: %s\n", path);
    return 1;
  }

  unsigned char image[MAX_WIDTH][MAX_HEIGHT] = {0};
  int width = 0, height = 0;

  fread(&width, sizeof(int), 1, file);
  fread(&height, sizeof(int), 1, file);

  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Image dimensions are too big\n");
    return 1;
  }

  fread(image, sizeof(unsigned char), width * height, file);

  convert(image, width, height);
  print_ascii(width, height);

  fclose(file);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char *ascii = " .,-~:;=!*#$@";

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <image>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    printf("Error opening image file %s\n", argv[1]);
    return 1;
  }

  fseek(fp, 10, SEEK_SET);
  int width, height;
  fread(&width, sizeof(int), 1, fp);
  fread(&height, sizeof(int), 1, fp);

  if (width > WIDTH || height > HEIGHT) {
    printf("Error: image too large (%dx%d)\n", width, height);
    fclose(fp);
    return 1;
  }

  unsigned char *data = malloc(width * height * 3);
  fread(data, sizeof(unsigned char), width * height * 3, fp);
  fclose(fp);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r = data[(y * width + x) * 3];
      int g = data[(y * width + x) * 3 + 1];
      int b = data[(y * width + x) * 3 + 2];
      int avg = (r + g + b) / 3;
      printf("%c", ascii[avg / 25]);
    }
    printf("\n");
  }

  free(data);
  return 0;
}
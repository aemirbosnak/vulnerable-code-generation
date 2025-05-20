//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

void convert(char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  unsigned char header[18];
  fread(header, sizeof(header), 1, fp);
  if (header[0] != 'B' || header[1] != 'M') {
    fprintf(stderr, "Invalid BMP file header\n");
    exit(EXIT_FAILURE);
  }

  int width = *(int *)&header[18];
  int height = *(int *)&header[22];
  if (width != WIDTH || height != HEIGHT) {
    fprintf(stderr, "Invalid BMP file dimensions\n");
    exit(EXIT_FAILURE);
  }

  int padding = (4 - (width * 3) % 4) % 4;

  char *data = malloc(width * height);
  fread(data, width * height, 1, fp);
  fclose(fp);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int offset = (y * width + x) * 3;
      int r = data[offset + 2];
      int g = data[offset + 1];
      int b = data[offset + 0];
      char c = ' ';
      if (r + g + b > 382) c = 'X';
      else if (r + g + b > 255) c = '+';
      else if (r + g + b > 127) c = '*';
      else c = ' ';
      printf("%c", c);
    }
    printf("\n");
  }

  free(data);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  convert(argv[1]);

  return 0;
}
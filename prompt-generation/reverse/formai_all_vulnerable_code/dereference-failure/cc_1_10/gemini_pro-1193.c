//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024

int main(int argc, char *argv[]) {
  char *filename;
  int width, height, depth;
  unsigned char *data;
  FILE *fp;

  if (argc < 4) {
    fprintf(stderr, "Usage: %s <filename> <width> <height> [<depth>]\n", argv[0]);
    return 1;
  }
  filename = argv[1];
  width = atoi(argv[2]);
  height = atoi(argv[3]);
  depth = argc >= 5 ? atoi(argv[4]) : 3;

  fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror(filename);
    return 1;
  }

  fprintf(fp, "P%d\n%d %d\n255\n", depth, width, height);

  data = malloc(width * height * depth);
  if (data == NULL) {
    perror("malloc");
    fclose(fp);
    return 1;
  }

  memset(data, 0, width * height * depth);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      data[y * width * depth + x * depth + 0] = x * 255 / width;
      data[y * width * depth + x * depth + 1] = y * 255 / height;
      data[y * width * depth + x * depth + 2] = 255;
    }
  }

  fwrite(data, 1, width * height * depth, fp);

  free(data);
  fclose(fp);

  return 0;
}
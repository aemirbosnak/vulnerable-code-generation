//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

const char *ASCII_CHARS = " .:-+*#%@";

void print_image(unsigned char *image, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int index = image[y * width + x] / 25;
      printf("%c", ASCII_CHARS[index]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <image.pgm>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "rb");
  if (!fp) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  char magic[3];
  if (fread(magic, 1, 3, fp) != 3 || strncmp(magic, "P5", 2) != 0) {
    printf("Error: file is not a valid PGM image\n");
    fclose(fp);
    return 1;
  }

  int width, height, max_val;
  if (fscanf(fp, "%d %d %d", &width, &height, &max_val) != 3) {
    printf("Error: could not read image dimensions\n");
    fclose(fp);
    return 1;
  }

  if (width > MAX_WIDTH || height > MAX_HEIGHT) {
    printf("Error: image is too large\n");
    fclose(fp);
    return 1;
  }

  unsigned char *image = malloc(width * height);
  if (!image) {
    printf("Error: could not allocate memory for image\n");
    fclose(fp);
    return 1;
  }

  if (fread(image, 1, width * height, fp) != width * height) {
    printf("Error: could not read image data\n");
    fclose(fp);
    free(image);
    return 1;
  }

  fclose(fp);

  print_image(image, width, height);

  free(image);

  return 0;
}
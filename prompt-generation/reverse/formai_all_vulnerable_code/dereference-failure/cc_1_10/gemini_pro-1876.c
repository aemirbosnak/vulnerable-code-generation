//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 64
#define HEIGHT 48

const char *ASCII_CHARS = ".',:;!*#&@";

struct Image {
  unsigned char *data;
  int width;
  int height;
};

struct Image *read_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) {
    perror("fopen");
    return NULL;
  }

  struct Image *image = malloc(sizeof(struct Image));
  if (!image) {
    perror("malloc");
    fclose(fp);
    return NULL;
  }

  fseek(fp, 18, SEEK_SET);
  fread(&image->width, sizeof(int), 1, fp);
  fread(&image->height, sizeof(int), 1, fp);
  fseek(fp, 54, SEEK_SET);

  image->data = malloc(image->width * image->height * 3);
  if (!image->data) {
    perror("malloc");
    fclose(fp);
    free(image);
    return NULL;
  }

  fread(image->data, image->width * image->height * 3, 1, fp);
  fclose(fp);

  return image;
}

void free_image(struct Image *image) {
  free(image->data);
  free(image);
}

void convert_to_ascii(struct Image *image) {
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      int index = y * image->width + x;
      int r = image->data[index * 3 + 0];
      int g = image->data[index * 3 + 1];
      int b = image->data[index * 3 + 2];
      int gray = (r + g + b) / 3;
      int index2 = gray * strlen(ASCII_CHARS) / 256;
      printf("%c", ASCII_CHARS[index2]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
    return 1;
  }

  struct Image *image = read_image(argv[1]);
  if (!image) {
    return 1;
  }

  convert_to_ascii(image);

  free_image(image);

  return 0;
}
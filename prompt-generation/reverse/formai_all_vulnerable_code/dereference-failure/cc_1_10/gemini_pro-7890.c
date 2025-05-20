//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
  unsigned char r, g, b;
} pixel;

typedef struct {
  int width, height;
  pixel *data;
} image;

image *load_image(const char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (!fp) return NULL;

  image *img = malloc(sizeof(image));
  if (!img) { fclose(fp); return NULL; }

  fread(&img->width, sizeof(int), 1, fp);
  fread(&img->height, sizeof(int), 1, fp);

  img->data = malloc(img->width * img->height * sizeof(pixel));
  if (!img->data) { fclose(fp); free(img); return NULL; }

  fread(img->data, sizeof(pixel), img->width * img->height, fp);
  fclose(fp);

  return img;
}

void free_image(image *img) {
  if (!img) return;

  free(img->data);
  free(img);
}

void print_image(const image *img) {
  for (int y = 0; y < img->height; y++) {
    for (int x = 0; x < img->width; x++) {
      const pixel *p = &img->data[y * img->width + x];

      // Convert the RGB value to a grayscale value.
      int gray = (p->r + p->g + p->b) / 3;

      // Map the grayscale value to an ASCII character.
      char c = " .,-~:;=*#%@";
      c += gray * (strlen(c) - 1) / 255;

      printf("%c", c);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  image *img = load_image(argv[1]);
  if (!img) {
    printf("Error: Unable to load image '%s'\n", argv[1]);
    return 1;
  }

  print_image(img);
  free_image(img);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image {
  int width;
  int height;
  char **pixels;
} Image;

Image *create_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(height * sizeof(char *) + 1);
  for (int i = 0; i < image->height; i++) {
    image->pixels[i] = malloc(width * sizeof(char) + 1);
  }
  return image;
}

void draw_pixel(Image *image, int x, int y, char color) {
  if (x < image->width && y < image->height) {
    image->pixels[y][x] = color;
  }
}

void save_image(Image *image, FILE *file) {
  fprintf(file, "PBM\n");
  fprintf(file, "WIDTH %d\n", image->width);
  fprintf(file, "HEIGHT %d\n", image->height);
  fprintf(file, " pixels\n");
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      fprintf(file, "%c ", image->pixels[y][x]);
    }
    fprintf(file, "\n");
  }
}

int main() {
  Image *image = create_image(16, 16);
  draw_pixel(image, 0, 0, 'R');
  draw_pixel(image, 0, 1, 'G');
  draw_pixel(image, 0, 2, 'B');
  draw_pixel(image, 1, 1, 'R');
  draw_pixel(image, 1, 2, 'G');
  save_image(image, stdout);

  return 0;
}
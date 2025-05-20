//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
  unsigned char r, g, b;
} Color;

typedef struct {
  Color *pixels;
  int width, height;
} Image;

Image *new_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(width * height * sizeof(Color));
  memset(image->pixels, 0, width * height * sizeof(Color));
  return image;
}

void free_image(Image *image) {
  free(image->pixels);
  free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
  if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
    image->pixels[y * image->width + x] = color;
  }
}

Color get_pixel(Image *image, int x, int y) {
  if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
    return image->pixels[y * image->width + x];
  } else {
    return (Color){0, 0, 0};
  }
}

void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
  fwrite(image->pixels, sizeof(Color), image->width * image->height, file);
  fclose(file);
}

int main() {
  Image *image = new_image(WIDTH, HEIGHT);

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      Color color = {
        (x * 255) / WIDTH,
        (y * 255) / HEIGHT,
        (x + y) % 255
      };
      set_pixel(image, x, y, color);
    }
  }

  save_image(image, "gradient.ppm");
  free_image(image);

  return 0;
}
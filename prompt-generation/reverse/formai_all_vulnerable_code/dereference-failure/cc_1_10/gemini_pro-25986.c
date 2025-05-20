//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 1024
#define HEIGHT 768
#define MAX_COLORS 256

typedef struct {
  unsigned char r, g, b;
} Color;

typedef struct {
  Color *pixels;
  int width, height;
} Image;

Image *image_new(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->pixels = malloc(sizeof(Color) * width * height);
  return image;
}

void image_free(Image *image) {
  free(image->pixels);
  free(image);
}

void image_set_pixel(Image *image, int x, int y, Color color) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->pixels[y * image->width + x] = color;
}

Color image_get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return (Color){0, 0, 0};
  }
  return image->pixels[y * image->width + x];
}

void image_save_ppm(Image *image, const char *filename) {
  FILE *file = fopen(filename, "wb");
  fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
  fwrite(image->pixels, sizeof(Color), image->width * image->height, file);
  fclose(file);
}

Image *image_from_ppm(const char *filename) {
  FILE *file = fopen(filename, "rb");
  char line[1024];
  int width, height;
  fscanf(file, "P6\n%d %d\n255\n", &width, &height);
  Image *image = image_new(width, height);
  fread(image->pixels, sizeof(Color), width * height, file);
  fclose(file);
  return image;
}

int main() {
  Image *image = image_new(WIDTH, HEIGHT);

  // Draw a circle in the center of the image
  int radius = WIDTH / 4;
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int dx = x - WIDTH / 2;
      int dy = y - HEIGHT / 2;
      if (dx * dx + dy * dy <= radius * radius) {
        image_set_pixel(image, x, y, (Color){255, 255, 255});
      }
    }
  }

  // Draw a rectangle in the top-left corner of the image
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x < 100; x++) {
      image_set_pixel(image, x, y, (Color){0, 0, 0});
    }
  }

  // Draw a line from the top-left corner to the bottom-right corner of the image
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (y == x) {
        image_set_pixel(image, x, y, (Color){255, 0, 0});
      }
    }
  }

  // Save the image to a PPM file
  image_save_ppm(image, "output.ppm");

  // Free the image
  image_free(image);

  return 0;
}
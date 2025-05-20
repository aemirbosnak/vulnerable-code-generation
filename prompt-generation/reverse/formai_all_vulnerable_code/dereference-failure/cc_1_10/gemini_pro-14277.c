//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 64
#define HEIGHT 64

typedef struct {
  unsigned char r, g, b, a;
} Color;

typedef struct {
  Color pixels[WIDTH * HEIGHT];
  int width, height;
} Image;

Image *new_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  memset(image->pixels, 0, sizeof(image->pixels));
  return image;
}

void free_image(Image *image) {
  free(image);
}

void set_pixel(Image *image, int x, int y, Color color) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->pixels[y * image->width + x] = color;
}

Color get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return (Color){0, 0, 0, 0};
  }
  return image->pixels[y * image->width + x];
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, Color color) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = (x2 - x1) > 0 ? 1 : -1;
  int sy = (y2 - y1) > 0 ? 1 : -1;
  int err = dx - dy;
  while (1) {
    set_pixel(image, x1, y1, color);
    if (x1 == x2 && y1 == y2) {
      break;
    }
    int e2 = 2 * err;
    if (e2 > -dy) {
      err = err - dy;
      x1 = x1 + sx;
    }
    if (e2 < dx) {
      err = err + dx;
      y1 = y1 + sy;
    }
  }
}

void draw_circle(Image *image, int x, int y, int radius, Color color) {
  int f = 1 - radius;
  int dx = 1;
  int dy = -2 * radius;
  int x1 = 0;
  int y1 = radius;
  while (x1 < y1) {
    set_pixel(image, x + x1, y + y1, color);
    set_pixel(image, x - x1, y + y1, color);
    set_pixel(image, x + x1, y - y1, color);
    set_pixel(image, x - x1, y - y1, color);
    set_pixel(image, x + y1, y + x1, color);
    set_pixel(image, x - y1, y + x1, color);
    set_pixel(image, x + y1, y - x1, color);
    set_pixel(image, x - y1, y - x1, color);
    if (f >= 0) {
      y1--;
      dy += 2;
      f += dy;
    }
    x1++;
    dx += 2;
    f += dx;
  }
}

void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      Color color = get_pixel(image, x, y);
      fprintf(file, "%d %d %d ", color.r, color.g, color.b);
    }
    fprintf(file, "\n");
  }
  fclose(file);
}

int main() {
  Image *image = new_image(WIDTH, HEIGHT);

  // Draw a red line from (0, 0) to (WIDTH, HEIGHT)
  draw_line(image, 0, 0, WIDTH - 1, HEIGHT - 1, (Color){255, 0, 0, 255});

  // Draw a green circle at (WIDTH / 2, HEIGHT / 2) with a radius of 10
  draw_circle(image, WIDTH / 2, HEIGHT / 2, 10, (Color){0, 255, 0, 255});

  // Save the image to a PPM file
  save_image(image, "output.ppm");

  free_image(image);
  return 0;
}
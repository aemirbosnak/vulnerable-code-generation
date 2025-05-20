//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int width;
  int height;
  unsigned char *data;
} Image;

Image *create_image(int width, int height) {
  Image *image = malloc(sizeof(Image));
  image->width = width;
  image->height = height;
  image->data = malloc(width * height);
  return image;
}

void destroy_image(Image *image) {
  free(image->data);
  free(image);
}

void set_pixel(Image *image, int x, int y, unsigned char color) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->data[y * image->width + x] = color;
}

unsigned char get_pixel(Image *image, int x, int y) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return 0;
  }
  return image->data[y * image->width + x];
}

void draw_line(Image *image, int x0, int y0, int x1, int y1, unsigned char color) {
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;
  while (1) {
    set_pixel(image, x0, y0, color);
    if (x0 == x1 && y0 == y1) break;
    int e2 = err;
    if (e2 > -dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void draw_circle(Image *image, int x0, int y0, int radius, unsigned char color) {
  int x = 0, y = radius;
  int dp = 1 - radius;
  do {
    if (dp < 0) dp += 2 * x + 3;
    else        dp += 2 * (x - y) + 5;
    set_pixel(image, x0 + x, y0 + y, color);
    set_pixel(image, x0 + y, y0 - x, color);
    set_pixel(image, x0 - x, y0 - y, color);
    set_pixel(image, x0 - y, y0 + x, color);
    x++;
  } while (x < y);
}

void draw_box(Image *image, int x0, int y0, int x1, int y1, unsigned char color) {
  for (int i = x0; i <= x1; i++) {
    set_pixel(image, i, y0, color);
    set_pixel(image, i, y1, color);
  }
  for (int j = y0; j <= y1; j++) {
    set_pixel(image, x0, j, color);
    set_pixel(image, x1, j, color);
  }
}

void draw_text(Image *image, int x0, int y0, const char *text, unsigned char color) {
  while (*text) {
    char c = *text++;
    int w = 5, h = 8;
    const unsigned char *font = (const unsigned char *)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,!?" + (c - 'A') * w * h;
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        if (font[j * w + i]) set_pixel(image, x0 + i, y0 + j, color);
      }
    }
    x0 += w;
  }
}

int main() {
  Image *image = create_image(320, 200);

  draw_box(image, 10, 10, 300, 100, 1);
  draw_line(image, 10, 10, 300, 100, 2);
  draw_circle(image, 150, 100, 50, 3);
  draw_text(image, 10, 160, "Hello, world!", 4);

  FILE *fp = fopen("image.ppm", "wb");
  fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height);
  for (int y = 0; y < image->height; y++) {
    for (int x = 0; x < image->width; x++) {
      fprintf(fp, "%d %d %d ", get_pixel(image, x, y), get_pixel(image, x, y), get_pixel(image, x, y));
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  destroy_image(image);

  return 0;
}
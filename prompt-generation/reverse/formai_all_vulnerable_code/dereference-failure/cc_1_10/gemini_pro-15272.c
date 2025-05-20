//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int width;
  int height;
  char *data;
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

void set_pixel(Image *image, int x, int y, char value) {
  if (x < 0 || x >= image->width || y < 0 || y >= image->height) {
    return;
  }
  image->data[y * image->width + x] = value;
}

void draw_line(Image *image, int x1, int y1, int x2, int y2, char value) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;
  while (1) {
    set_pixel(image, x1, y1, value);
    if (x1 == x2 && y1 == y2) {
      break;
    }
    int e2 = err;
    if (e2 > -dx) {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dy) {
      err += dx;
      y1 += sy;
    }
  }
}

void draw_circle(Image *image, int x, int y, int radius, char value) {
  int x1 = x - radius;
  int y1 = y - radius;
  int x2 = x + radius;
  int y2 = y + radius;
  for (int i = x1; i <= x2; i++) {
    for (int j = y1; j <= y2; j++) {
      if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius) {
        set_pixel(image, i, j, value);
      }
    }
  }
}

void draw_rectangle(Image *image, int x1, int y1, int x2, int y2, char value) {
  for (int i = x1; i <= x2; i++) {
    set_pixel(image, i, y1, value);
    set_pixel(image, i, y2, value);
  }
  for (int j = y1; j <= y2; j++) {
    set_pixel(image, x1, j, value);
    set_pixel(image, x2, j, value);
  }
}

void draw_triangle(Image *image, int x1, int y1, int x2, int y2, int x3, int y3, char value) {
  draw_line(image, x1, y1, x2, y2, value);
  draw_line(image, x2, y2, x3, y3, value);
  draw_line(image, x3, y3, x1, y1, value);
}

void save_image(Image *image, char *filename) {
  FILE *file = fopen(filename, "wb");
  fwrite("P1\n", 3, 1, file);
  fprintf(file, "%d %d\n", image->width, image->height);
  fwrite(image->data, image->width * image->height, 1, file);
  fclose(file);
}

int main() {
  Image *image = create_image(500, 500);

  for (int i = 0; i < image->width; i++) {
    for (int j = 0; j < image->height; j++) {
      set_pixel(image, i, j, '0');
    }
  }

  draw_line(image, 0, 0, image->width, image->height, '1');
  draw_line(image, 0, image->height, image->width, 0, '1');
  draw_circle(image, image->width / 2, image->height / 2, image->width / 4, '1');
  draw_rectangle(image, 100, 100, 200, 200, '1');
  draw_triangle(image, 100, 100, 200, 100, 150, 200, '1');

  save_image(image, "image.pbm");
  destroy_image(image);

  return 0;
}
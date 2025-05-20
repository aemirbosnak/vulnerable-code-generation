//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

typedef struct _image {
  int width;
  int height;
  char **data;
} image;

image *new_image(int width, int height) {
  image *img = malloc(sizeof(image));
  img->width = width;
  img->height = height;
  img->data = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    img->data[i] = malloc(sizeof(char) * width);
    for (int j = 0; j < width; j++) {
      img->data[i][j] = ' ';
    }
  }
  return img;
}

void free_image(image *img) {
  for (int i = 0; i < img->height; i++) {
    free(img->data[i]);
  }
  free(img->data);
  free(img);
}

void print_image(image *img) {
  for (int i = 0; i < img->height; i++) {
    for (int j = 0; j < img->width; j++) {
      printf("%c", img->data[i][j]);
    }
    printf("\n");
  }
}

void draw_line(image *img, int x1, int y1, int x2, int y2) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx - dy;
  while (1) {
    img->data[y1][x1] = '*';
    if (x1 == x2 && y1 == y2) break;
    int e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dx) {
      err += dx;
      y1 += sy;
    }
  }
}

void draw_circle(image *img, int x, int y, int radius) {
  int cx = x;
  int cy = y;
  int r2 = radius * radius;
  for (int i = -radius; i <= radius; i++) {
    for (int j = -radius; j <= radius; j++) {
      if (i * i + j * j <= r2) {
        img->data[cy + i][cx + j] = '*';
      }
    }
  }
}

void draw_rectangle(image *img, int x1, int y1, int x2, int y2) {
  for (int i = x1; i <= x2; i++) {
    img->data[y1][i] = '*';
    img->data[y2][i] = '*';
  }
  for (int i = y1; i <= y2; i++) {
    img->data[i][x1] = '*';
    img->data[i][x2] = '*';
  }
}

void draw_triangle(image *img, int x1, int y1, int x2, int y2, int x3, int y3) {
  draw_line(img, x1, y1, x2, y2);
  draw_line(img, x2, y2, x3, y3);
  draw_line(img, x3, y3, x1, y1);
}

int main() {
  image *img = new_image(200, 100);

  draw_line(img, 10, 10, 190, 10);
  draw_line(img, 10, 90, 190, 90);
  draw_line(img, 10, 10, 10, 90);
  draw_line(img, 190, 10, 190, 90);

  draw_circle(img, 100, 50, 20);
  draw_rectangle(img, 50, 20, 150, 80);
  draw_triangle(img, 20, 20, 80, 80, 180, 20);

  print_image(img);

  free_image(img);

  return 0;
}
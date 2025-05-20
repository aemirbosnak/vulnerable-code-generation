//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100

typedef struct {
  int width;
  int height;
  char **data;
} Canvas;

Canvas *canvas_create(int width, int height) {
  Canvas *canvas = malloc(sizeof(Canvas));
  canvas->width = width;
  canvas->height = height;
  canvas->data = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    canvas->data[i] = malloc(sizeof(char) * (width + 1));
    memset(canvas->data[i], ' ', width);
    canvas->data[i][width] = '\0';
  }
  return canvas;
}

void canvas_destroy(Canvas *canvas) {
  for (int i = 0; i < canvas->height; i++) {
    free(canvas->data[i]);
  }
  free(canvas->data);
  free(canvas);
}

void canvas_draw_line(Canvas *canvas, int x1, int y1, int x2, int y2) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx - dy;
  while (1) {
    canvas->data[y1][x1] = '*';
    if (x1 == x2 && y1 == y2) {
      break;
    }
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

void canvas_draw_circle(Canvas *canvas, int x, int y, int radius) {
  int f = 1 - radius;
  int dx = 1;
  int dy = -2 * radius;
  int x1 = 0;
  int y1 = radius;
  canvas->data[y][x] = '*';
  while (x1 < y1) {
    if (f >= 0) {
      y1--;
      dy += 2;
      f -= dy;
    }
    x1++;
    dx += 2;
    f += dx;
    canvas->data[y + y1][x + x1] = '*';
    canvas->data[y + y1][x - x1] = '*';
    canvas->data[y - y1][x + x1] = '*';
    canvas->data[y - y1][x - x1] = '*';
    canvas->data[y + x1][x + y1] = '*';
    canvas->data[y + x1][x - y1] = '*';
    canvas->data[y - x1][x + y1] = '*';
    canvas->data[y - x1][x - y1] = '*';
  }
}

void canvas_draw_text(Canvas *canvas, int x, int y, const char *text) {
  int len = strlen(text);
  for (int i = 0; i < len; i++) {
    int c = text[i];
    if (c >= 'a' && c <= 'z') {
      c -= 'a';
      canvas_draw_circle(canvas, x + i * 10, y, 5);
      canvas_draw_line(canvas, x + i * 10 - 5, y + 5, x + i * 10 + 5, y + 5);
      canvas_draw_line(canvas, x + i * 10, y + 5, x + i * 10, y + 15);
    } else if (c >= 'A' && c <= 'Z') {
      c -= 'A';
      canvas_draw_circle(canvas, x + i * 10, y, 5);
      canvas_draw_line(canvas, x + i * 10 - 5, y + 5, x + i * 10 + 5, y + 5);
      canvas_draw_line(canvas, x + i * 10, y + 5, x + i * 10, y + 20);
      canvas_draw_line(canvas, x + i * 10, y + 20, x + i * 10 - 5, y + 25);
      canvas_draw_line(canvas, x + i * 10, y + 20, x + i * 10 + 5, y + 25);
    } else if (c >= '0' && c <= '9') {
      c -= '0';
      canvas_draw_circle(canvas, x + i * 10, y, 5);
      canvas_draw_line(canvas, x + i * 10 - 5, y + 5, x + i * 10 + 5, y + 5);
      canvas_draw_line(canvas, x + i * 10, y + 5, x + i * 10, y + 15);
      canvas_draw_line(canvas, x + i * 10, y + 15, x + i * 10 - 5, y + 20);
      canvas_draw_line(canvas, x + i * 10, y + 15, x + i * 10 + 5, y + 20);
    }
  }
}

void canvas_print(Canvas *canvas) {
  for (int i = 0; i < canvas->height; i++) {
    printf("%s\n", canvas->data[i]);
  }
}

int main() {
  Canvas *canvas = canvas_create(MAX_WIDTH, 100);
  canvas_draw_text(canvas, 10, 10, "Hello, Medieval ASCII Art!");
  canvas_print(canvas);
  canvas_destroy(canvas);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

char *pixels;

void init() {
  pixels = malloc(WIDTH * HEIGHT);
  memset(pixels, ' ', WIDTH * HEIGHT);
}

void putpixel(int x, int y, char c) {
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    pixels[y * WIDTH + x] = c;
  }
}

void draw_line(int x0, int y0, int x1, int y1, char c) {
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;

  while (1) {
    putpixel(x0, y0, c);
    if (x0 == x1 && y0 == y1) break;
    int e2 = err;
    if (e2 > -dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void draw_circle(int x0, int y0, int radius, char c) {
  int x = radius, y = 0;
  int err = 0;

  while (x >= y) {
    putpixel(x0 + x, y0 + y, c);
    putpixel(x0 + y, y0 + x, c);
    putpixel(x0 - y, y0 + x, c);
    putpixel(x0 - x, y0 + y, c);
    putpixel(x0 - x, y0 - y, c);
    putpixel(x0 - y, y0 - x, c);
    putpixel(x0 + y, y0 - x, c);
    putpixel(x0 + x, y0 - y, c);
    y++;
    err += 1 + 2 * y;
    if (2 * (err - x) + 1 > 0) { x--; err -= 1 + 2 * x; }
  }
}

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, char c) {
  draw_line(x0, y0, x1, y1, c);
  draw_line(x1, y1, x2, y2, c);
  draw_line(x2, y2, x0, y0, c);
}

void draw_square(int x0, int y0, int side, char c) {
  draw_line(x0, y0, x0 + side, y0, c);
  draw_line(x0 + side, y0, x0 + side, y0 + side, c);
  draw_line(x0 + side, y0 + side, x0, y0 + side, c);
  draw_line(x0, y0 + side, x0, y0, c);
}

void draw_image(char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: could not open file %s\n", filename);
    return;
  }

  int width, height;
  fscanf(file, "%d %d\n", &width, &height);

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      char c;
      fscanf(file, "%c", &c);
      putpixel(x, y, c);
    }
  }

  fclose(file);
}

void display() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", pixels[y * WIDTH + x]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  init();

  // Draw a random number of pixels
  for (int i = 0; i < 1000; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    char c = rand() % 26 + 'a';
    putpixel(x, y, c);
  }

  // Draw a line
  draw_line(10, 10, 70, 10, '*');

  // Draw a circle
  draw_circle(40, 12, 10, '*');

  // Draw a triangle
  draw_triangle(20, 20, 40, 20, 30, 30, '*');

  // Draw a square
  draw_square(50, 15, 10, '*');

  // Draw an image
  draw_image("image.txt");

  // Display the image
  display();

  return 0;
}
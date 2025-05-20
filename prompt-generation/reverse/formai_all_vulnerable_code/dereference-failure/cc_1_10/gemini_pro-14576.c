//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

unsigned char *pixels;

void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
  pixels[y * WIDTH * 3 + x * 3 + 0] = r;
  pixels[y * WIDTH * 3 + x * 3 + 1] = g;
  pixels[y * WIDTH * 3 + x * 3 + 2] = b;
}

void draw_line(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
  int dx = x2 - x1;
  int dy = y2 - y1;
  float m = (float)dy / dx;
  for (int i = 0; i <= dx; i++) {
    int x = x1 + i;
    int y = y1 + (int)(m * i);
    set_pixel(x, y, r, g, b);
  }
}

void draw_circle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b) {
  for (int i = 0; i <= 360; i++) {
    float radians = i * (M_PI / 180);
    int x2 = x + (int)(radius * cos(radians));
    int y2 = y + (int)(radius * sin(radians));
    set_pixel(x2, y2, r, g, b);
  }
}

void draw_rectangle(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b) {
  draw_line(x1, y1, x2, y1, r, g, b);
  draw_line(x2, y1, x2, y2, r, g, b);
  draw_line(x2, y2, x1, y2, r, g, b);
  draw_line(x1, y2, x1, y1, r, g, b);
}

void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char r, unsigned char g, unsigned char b) {
  draw_line(x1, y1, x2, y2, r, g, b);
  draw_line(x2, y2, x3, y3, r, g, b);
  draw_line(x3, y3, x1, y1, r, g, b);
}

int main() {
  pixels = (unsigned char *)malloc(WIDTH * HEIGHT * 3);
  memset(pixels, 0, WIDTH * HEIGHT * 3);

  // Draw a red line from (0, 0) to (WIDTH, HEIGHT)
  draw_line(0, 0, WIDTH, HEIGHT, 255, 0, 0);

  // Draw a green circle at (WIDTH / 2, HEIGHT / 2) with a radius of 100
  draw_circle(WIDTH / 2, HEIGHT / 2, 100, 0, 255, 0);

  // Draw a blue rectangle from (0, 0) to (WIDTH / 2, HEIGHT / 2)
  draw_rectangle(0, 0, WIDTH / 2, HEIGHT / 2, 0, 0, 255);

  // Draw a yellow triangle from (WIDTH / 2, 0) to (WIDTH, HEIGHT / 2) to (WIDTH / 2, HEIGHT)
  draw_triangle(WIDTH / 2, 0, WIDTH, HEIGHT / 2, WIDTH / 2, HEIGHT, 255, 255, 0);

  // Save the image to a file
  FILE *file = fopen("output.bmp", "wb");
  fprintf(file, "BM%c%c%c%c%c%c%c%c%c%c\x1a\x00\x00\x00\x00\x00\x00\x00\x00\x00\x76\x00\x00\x00\x28\x00\x00\x00\x28\x00\x00\x00\x01\x00\x18\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x12\x0B\x00\x00\x12\x0B\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  fwrite(pixels, 1, WIDTH * HEIGHT * 3, file);
  fclose(file);

  return 0;
}
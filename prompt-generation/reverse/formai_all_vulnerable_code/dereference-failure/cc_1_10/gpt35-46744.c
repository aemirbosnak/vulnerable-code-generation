//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 200
#define HEIGHT 200
#define MAX_ITER 100

typedef struct _complex {
  double x, y;
} complex;

void set(complex *a, double x, double y) {
  a->x = x;
  a->y = y;
}

void add(complex *a, complex *b) {
  a->x += b->x;
  a->y += b->y;
}

void mul(complex *a, complex *b) {
  complex tmp;
  tmp.x = a->x * b->x - a->y * b->y;
  tmp.y = a->x * b->y + a->y * b->x;
  *a = tmp;
}

double norm(complex *a) {
  return a->x * a->x + a->y * a->y;
}

void iterate(complex *z, complex *c, int *n) {
  int i = 0;
  set(z, 0.0, 0.0);
  while (i < MAX_ITER && norm(z) < 4.0) {
    mul(z, z);
    add(z, c);
    i++;
  }
  *n = i;
}

void putpixel(char *buffer, int x, int y, char c) {
  buffer[y * WIDTH + x] = c;
}

void display(char *buffer) {
  int x, y;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++)
      putchar(buffer[y * WIDTH + x]);
    putchar('\n');
  }
}

void generate_fractal(char *buffer) {
  int x, y, n;
  complex z, c;
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      set(&c, 2.0 * x / WIDTH - 1.5, 2.0 * y / HEIGHT - 1.0);
      iterate(&z, &c, &n);
      putpixel(buffer, x, y, "#.=-+*$/@"[n % 8]);
    }
  }
}

int main(int argc, char **argv) {
  char *buffer = malloc(WIDTH * HEIGHT);
  memset(buffer, ' ', WIDTH * HEIGHT);
  generate_fractal(buffer);
  display(buffer);
  free(buffer);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define WIDTH 1024
#define HEIGHT 1024
#define MAX_ITER 1000

typedef struct {
  double real;
  double imag;
} complex_t;

void fractal(complex_t c, int iter, int *out) {
  complex_t z = {0, 0};
  while (iter-- > 0 && z.real * z.real + z.imag * z.imag < 4) {
    double tmp = z.real;
    z.real = z.real * z.real - z.imag * z.imag + c.real;
    z.imag = 2 * tmp * z.imag + c.imag;
  }
  *out = iter;
}

int main() {
  int *data = malloc(WIDTH * HEIGHT * sizeof(int));
  double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5;
  double dx = (xmax - xmin) / WIDTH, dy = (ymax - ymin) / HEIGHT;
#pragma omp parallel for
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      complex_t c = {xmin + x * dx, ymin + y * dy};
      fractal(c, MAX_ITER, &data[y * WIDTH + x]);
    }
  }
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int iter = data[y * WIDTH + x];
      double color = sqrt(iter / (double)MAX_ITER);
      fprintf(fp, "%d %d %d ", (int)(255 * color), (int)(255 * color),
              (int)(255 * color));
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
  free(data);
  return 0;
}
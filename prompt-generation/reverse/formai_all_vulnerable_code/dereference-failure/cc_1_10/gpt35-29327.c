//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_ITERATIONS 100

typedef struct Complex {
  double r;
  double i;
} Complex;

void computeFractal(unsigned char *data, int width, int height) {
  int i, j, index;
  Complex c, z, temp;
  int iterations;
  double minR = -2.0;
  double maxR = 1.0;
  double minI = -1.0;
  double maxI = 1.0;

  for (i = 0; i < width; i++) {
    for (j = 0; j < height; j++) {

      /* map pixel coordinates to complex plane */
      c.r = minR + (maxR - minR) * i / width;
      c.i = minI + (maxI - minI) * j / height;

      /* initialize z to (0,0) */
      z.r = 0;
      z.i = 0;

      iterations = 0;
      while (z.r * z.r + z.i * z.i < 4 && iterations < MAX_ITERATIONS) {
        /* calculate z = z^2 + c */
        temp.r = z.r * z.r - z.i * z.i + c.r;
        temp.i = 2 * z.r * z.i + c.i;
        z = temp;

        iterations++;
      }

      /* set the color of the pixel based on the number of iterations */
      index = (j * width + i) * 3;
      if (iterations == MAX_ITERATIONS) {
        /* pixel is in the Mandelbrot set */
        data[index] = 0;
        data[index + 1] = 0;
        data[index + 2] = 0;
      } else {
        /* pixel is not in the Mandelbrot set */
        data[index] = 255 - iterations;
        data[index + 1] = 255 - iterations;
        data[index + 2] = 255 - iterations;
      }
    }
  }
}

int main() {
  unsigned char *data = (unsigned char*)malloc(WIDTH * HEIGHT * 3 * sizeof(unsigned char));
  computeFractal(data, WIDTH, HEIGHT);

  FILE *fp;
  char *filename = "fractal.ppm";
  fp = fopen(filename, "wb");
  fprintf(fp, "P6\n%i %i 255\n", WIDTH, HEIGHT);
  fwrite(data, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
  fclose(fp);

  free(data);
  printf("Fractal image generated and saved as %s.\n", filename);

  return 0;
}
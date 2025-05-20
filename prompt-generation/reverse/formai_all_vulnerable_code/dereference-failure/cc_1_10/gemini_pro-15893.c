//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex number structure
typedef struct {
  double real;
  double imag;
} complex;

// Define the fractal parameters
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 255

// Define the color palette
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF

// Generate a random complex number
complex random_complex() {
  complex c;
  c.real = (double)rand() / (double)RAND_MAX * 4.0 - 2.0;
  c.imag = (double)rand() / (double)RAND_MAX * 4.0 - 2.0;
  return c;
}

// Calculate the Mandelbrot set value for a given complex number
int mandelbrot(complex c) {
  int iterations = 0;
  complex z = {0.0, 0.0};
  while (iterations < MAX_ITERATIONS && z.real * z.real + z.imag * z.imag < 4.0) {
    double temp = z.real * z.real - z.imag * z.imag + c.real;
    z.imag = 2.0 * z.real * z.imag + c.imag;
    z.real = temp;
    iterations++;
  }
  return iterations;
}

// Generate the fractal image
void generate_fractal(int *pixels) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      complex c = {-2.0 + (double)x / (double)WIDTH * 4.0,
                   -2.0 + (double)y / (double)HEIGHT * 4.0};
      int iterations = mandelbrot(c);
      pixels[y * WIDTH + x] = iterations == MAX_ITERATIONS ? COLOR_BLACK : COLOR_WHITE;
    }
  }
}

// Write the fractal image to a PPM file
void write_ppm(int *pixels, char *filename) {
  FILE *fp = fopen(filename, "wb");
  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(pixels, sizeof(int), WIDTH * HEIGHT, fp);
  fclose(fp);
}

// Main function
int main() {
  // Allocate memory for the fractal image
  int *pixels = (int *)malloc(WIDTH * HEIGHT * sizeof(int));

  // Generate the fractal image
  generate_fractal(pixels);

  // Write the fractal image to a PPM file
  write_ppm(pixels, "fractal.ppm");

  // Free the memory allocated for the fractal image
  free(pixels);

  return 0;
}
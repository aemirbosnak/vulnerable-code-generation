//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the complex data type
typedef struct complex {
  double real;
  double imaginary;
} complex;

// Define the function to calculate the next complex number in the Mandelbrot set
complex mandelbrot(complex c, complex z) {
  // Calculate the next complex number in the Mandelbrot set
  z.real = (z.real * z.real) - (z.imaginary * z.imaginary) + c.real;
  z.imaginary = 2 * z.real * z.imaginary + c.imaginary;

  // Return the next complex number
  return z;
}

// Define the function to generate the Mandelbrot set
void generate_mandelbrot(int width, int height) {
  // Create a 2D array to store the Mandelbrot set
  int **mandelbrot_set = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    mandelbrot_set[i] = malloc(sizeof(int) * width);
  }

  // Calculate the Mandelbrot set
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the complex number corresponding to the pixel (x, y)
      complex c;
      c.real = (double)x / width * 4 - 2;
      c.imaginary = (double)y / height * 4 - 2;

      // Calculate the Mandelbrot set for the complex number c
      complex z;
      z.real = 0;
      z.imaginary = 0;
      int iterations = 0;
      while (iterations < MAX_ITERATIONS && (z.real * z.real + z.imaginary * z.imaginary) < 4) {
        z = mandelbrot(c, z);
        iterations++;
      }

      // Store the number of iterations in the Mandelbrot set
      mandelbrot_set[y][x] = iterations;
    }
  }

  // Write the Mandelbrot set to a file
  FILE *file = fopen("mandelbrot.ppm", "w");
  fprintf(file, "P3\n%d %d\n255\n", width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int iterations = mandelbrot_set[y][x];
      int color = 255 * iterations / MAX_ITERATIONS;
      fprintf(file, "%d %d %d ", color, color, color);
    }
  }
  fclose(file);

  // Free the memory allocated for the Mandelbrot set
  for (int i = 0; i < height; i++) {
    free(mandelbrot_set[i]);
  }
  free(mandelbrot_set);
}

// Define the main function
int main() {
  // Generate the Mandelbrot set
  generate_mandelbrot(1000, 1000);

  // Return 0
  return 0;
}
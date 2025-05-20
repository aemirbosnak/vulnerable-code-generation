//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Constants
#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 255

// Function prototypes
void generateFractal(int **pixels, int width, int height, double centerX, double centerY, double zoom);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Allocate memory for the pixel array
  int **pixels = (int **)malloc(sizeof(int *) * HEIGHT);
  for (int i = 0; i < HEIGHT; i++) {
    pixels[i] = (int *)malloc(sizeof(int) * WIDTH);
  }

  // Generate the fractal
  double centerX = 0.0;
  double centerY = 0.0;
  double zoom = 1.0;
  generateFractal(pixels, WIDTH, HEIGHT, centerX, centerY, zoom);

  // Write the fractal to a file
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      fprintf(fp, "%d %d %d ", pixels[i][j], pixels[i][j], pixels[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);

  // Free the memory allocated for the pixel array
  for (int i = 0; i < HEIGHT; i++) {
    free(pixels[i]);
  }
  free(pixels);

  return 0;
}

// Function to generate the fractal
void generateFractal(int **pixels, int width, int height, double centerX, double centerY, double zoom) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // Convert the pixel coordinates to complex coordinates
      double cx = (j - width / 2) / zoom + centerX;
      double cy = (i - height / 2) / zoom + centerY;

      // Iterate the complex number through the Mandelbrot set
      int iterations = 0;
      double zx = cx;
      double zy = cy;
      while (iterations < MAX_ITERATIONS && zx * zx + zy * zy < 4.0) {
        double temp = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
        zx = temp;
        iterations++;
      }

      // Set the pixel color based on the number of iterations
      pixels[i][j] = 255 * iterations / MAX_ITERATIONS;
    }
  }
}
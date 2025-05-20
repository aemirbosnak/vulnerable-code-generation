//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  // Create a canvas
  unsigned char *canvas = malloc(WIDTH * HEIGHT * 3);

  // Set the background color to black
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    canvas[i * 3] = 0;
    canvas[i * 3 + 1] = 0;
    canvas[i * 3 + 2] = 0;
  }

  // Define the fractal parameters
  double cx = -0.7;
  double cy = 0.27015;
  double zoom = 1000;
  int maxIterations = 1000;

  // Iterate over each pixel in the canvas
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      // Convert the pixel coordinates to a complex number
      double zx = (x - WIDTH / 2) / (0.5 * zoom);
      double zy = (y - HEIGHT / 2) / (0.5 * zoom);

      // Iterate the complex number until it escapes the Mandelbrot set or reaches the maximum number of iterations
      int iteration = 0;
      while (zx * zx + zy * zy < 4 && iteration < maxIterations) {
        double tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        iteration++;
      }

      // Set the pixel color based on the number of iterations
      int color = 255 * iteration / maxIterations;
      canvas[3 * (x + WIDTH * y)] = color;
      canvas[3 * (x + WIDTH * y) + 1] = color;
      canvas[3 * (x + WIDTH * y) + 2] = color;
    }
  }

  // Write the canvas to a PPM file
  FILE *file = fopen("mandelbrot.ppm", "wb");
  fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(canvas, 1, WIDTH * HEIGHT * 3, file);
  fclose(file);

  // Free the canvas
  free(canvas);

  return 0;
}
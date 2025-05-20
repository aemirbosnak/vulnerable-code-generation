//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define WIDTH 800
#define HEIGHT 600

int main() {
  // Allocate memory for the image.
  int *image = malloc(WIDTH * HEIGHT * sizeof(int));

  // Set the initial parameters.
  double cx = -0.7;
  double cy = 0.27015;
  double zoom = 1.0;
  int iterations = 1000;

  // Generate the fractal.
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Convert the pixel coordinates to complex coordinates.
      double zx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
      double zy = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);

      // Iterate the complex number.
      int iteration = 0;
      while (zx * zx + zy * zy < 4 && iteration < MAX_ITERATIONS) {
        double temp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = temp;
        iteration++;
      }

      // Set the pixel color.
      image[y * WIDTH + x] = iteration;
    }
  }

  // Write the image to a file.
  FILE *file = fopen("fractal.ppm", "w");
  fprintf(file, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      fprintf(file, "%d %d %d ", image[y * WIDTH + x] % 256, image[y * WIDTH + x] % 256, image[y * WIDTH + x] % 256);
    }
    fprintf(file, "\n");
  }
  fclose(file);

  // Free the memory.
  free(image);

  return 0;
}
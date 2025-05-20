//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Create a buffer to store the fractal
  unsigned char *buffer = malloc(WIDTH * HEIGHT);

  // Iterate over each pixel in the fractal
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Calculate the complex number c for this pixel
      double c_real = (2.0 * x / WIDTH - 1.5);
      double c_imag = (2.0 * y / HEIGHT - 1.0);

      // Iterate over the complex number z
      double z_real = 0.0;
      double z_imag = 0.0;
      int iterations = 0;
      while (z_real * z_real + z_imag * z_imag < 4.0 && iterations < 255) {
        // Update z
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2.0 * z_real * z_imag + c_imag;
        z_real = temp;

        // Increment the iteration count
        iterations++;
      }

      // Set the pixel color based on the number of iterations
      buffer[y * WIDTH + x] = 255 - iterations;
    }
  }

  // Write the fractal to a file
  FILE *file = fopen("fractal.ppm", "wb");
  fprintf(file, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(buffer, WIDTH * HEIGHT, 1, file);
  fclose(file);

  // Free the buffer
  free(buffer);

  return 0;
}
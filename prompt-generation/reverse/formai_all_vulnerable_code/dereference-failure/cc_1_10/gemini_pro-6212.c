//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: medieval
// A medieval fractal generation program.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// The main function.
int main(int argc, char* argv[]) {
  // The usage string.
  char* usage = "Usage: %s <width> <height> <max_iterations>\n";

  // The width and height of the image.
  int width = 640;
  int height = 480;

  // The maximum number of iterations.
  int max_iterations = 100;

  // Parse the command line arguments.
  if (argc != 4) {
    fprintf(stderr, usage, argv[0]);
    return 1;
  }

  width = atoi(argv[1]);
  height = atoi(argv[2]);
  max_iterations = atoi(argv[3]);

  // Create the image.
  unsigned char* image = malloc(width * height * 3);

  // Iterate over each pixel in the image.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Convert the pixel coordinates to complex coordinates.
      double c_real = (2.0 * x / width) - 1.5;
      double c_imag = (2.0 * y / height) - 1.0;

      // Initialize the fractal value.
      double z_real = 0.0;
      double z_imag = 0.0;

      // Iterate the fractal value.
      int iterations = 0;
      while (iterations < max_iterations && (z_real * z_real + z_imag * z_imag) < 4.0) {
        // Calculate the next fractal value.
        double z_real_temp = z_real * z_real - z_imag * z_imag + c_real;
        double z_imag_temp = 2.0 * z_real * z_imag + c_imag;

        // Update the fractal value.
        z_real = z_real_temp;
        z_imag = z_imag_temp;

        // Increment the number of iterations.
        iterations++;
      }

      // Set the pixel color.
      image[3 * (y * width + x) + 0] = 255 * iterations / max_iterations;
      image[3 * (y * width + x) + 1] = 255 * iterations / max_iterations;
      image[3 * (y * width + x) + 2] = 255 * iterations / max_iterations;
    }
  }

  // Write the image to a file.
  FILE* fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P3\n%d %d\n255\n", width, height);
  fwrite(image, width * height * 3, 1, fp);
  fclose(fp);

  // Free the image.
  free(image);

  // Return 0.
  return 0;
}
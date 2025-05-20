//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
/*
  This program generates a fractal image using the Mandelbrot set.
  The Mandelbrot set is a set of complex numbers for which the sequence z(n+1) = z(n)^2 + c does not diverge.
  The program calculates the number of iterations needed for the sequence to diverge for each pixel in the image.
  The number of iterations is then used to determine the color of the pixel.

  The program uses Ada Lovelace's method of calculating the Mandelbrot set.
  This method uses a loop to calculate the sequence z(n) for each pixel in the image.
  The loop stops when either the sequence diverges or the maximum number of iterations is reached.

  The program uses the following parameters to generate the fractal image:

  - centerX: The real part of the center of the image.
  - centerY: The imaginary part of the center of the image.
  - zoom: The zoom level of the image.
  - width: The width of the image in pixels.
  - height: The height of the image in pixels.
  - maxIterations: The maximum number of iterations to calculate the sequence z(n) for each pixel.

  The program outputs the fractal image to a file named "mandelbrot.ppm".
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  // Get the parameters from the command line.
  double centerX = atof(argv[1]);
  double centerY = atof(argv[2]);
  double zoom = atof(argv[3]);
  int width = atoi(argv[4]);
  int height = atoi(argv[5]);
  int maxIterations = atoi(argv[6]);

  // Create an array to store the fractal image.
  int *image = malloc(width * height * sizeof(int));

  // Calculate the Mandelbrot set.
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      // Calculate the complex number c for the pixel.
      double cReal = centerX + (x - width / 2) * zoom / width;
      double cImag = centerY + (y - height / 2) * zoom / height;

      // Calculate the sequence z(n) for the pixel.
      double zReal = 0;
      double zImag = 0;
      int iterations = 0;
      while (zReal * zReal + zImag * zImag < 4 && iterations < maxIterations) {
        double zRealTemp = zReal * zReal - zImag * zImag + cReal;
        zImag = 2 * zReal * zImag + cImag;
        zReal = zRealTemp;
        iterations++;
      }

      // Store the number of iterations in the image array.
      image[y * width + x] = iterations;
    }
  }

  // Output the fractal image to a file.
  FILE *file = fopen("mandelbrot.ppm", "w");
  fprintf(file, "P3\n%d %d\n255\n", width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int iterations = image[y * width + x];
      fprintf(file, "%d %d %d ", iterations % 256, iterations % 256, iterations % 256);
    }
  }
  fclose(file);

  // Free the memory allocated for the image.
  free(image);

  return 0;
}
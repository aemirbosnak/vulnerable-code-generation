//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  // Create a bitmap image
  unsigned char *image = malloc(WIDTH * HEIGHT);

  // Set the background color to black
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    image[i] = 0;
  }

  // Define the complex plane
  double xmin = -2.0;
  double xmax = 1.0;
  double ymin = -1.5;
  double ymax = 1.5;

  // Iterate through each pixel in the image
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      // Convert the pixel coordinates to complex coordinates
      double cx = xmin + (xmax - xmin) * x / WIDTH;
      double cy = ymin + (ymax - ymin) * y / HEIGHT;

      // Initialize the complex number z
      double zx = 0.0;
      double zy = 0.0;

      // Iterate the complex number z
      int iterations = 0;
      while (zx * zx + zy * zy < 4 && iterations < 255) {
        // Calculate the next value of z
        double temp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = temp;

        // Increment the number of iterations
        iterations++;
      }

      // Set the pixel color based on the number of iterations
      image[x + y * WIDTH] = iterations;
    }
  }

  // Write the bitmap image to a file
  FILE *fp = fopen("fractal.bmp", "wb");
  fwrite(image, 1, WIDTH * HEIGHT, fp);
  fclose(fp);

  // Free the bitmap image
  free(image);

  return 0;
}
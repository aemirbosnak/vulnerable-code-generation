//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdio.h>
#include <math.h>

int main() {
  // Maximum number of iterations
  int maxIter = 1000;

  // Starting point for the fractal
  double x0 = -2.0;
  double y0 = -1.5;

  // Set the width and height of the image
  int width = 800;
  int height = 600;

  // Create a black image
  unsigned char* image = (unsigned char*)malloc(width * height * sizeof(unsigned char));

  // Set all pixels to black
  for (int i = 0; i < width * height; i++) {
    image[i] = 0;
  }

  // Calculate the color of each pixel
  for (int i = 0; i < width * height; i++) {
    double x = (double)i / (double)width;
    double y = (double)i / (double)height;
    double z = 0;

    for (int j = 0; j < maxIter; j++) {
      z = z * z + x;

      if (z * z + y >= 4) {
        image[i] = 255;
        break;
      }
    }
  }

  // Display the image
  printf("Mandelbrot set image:\n");
  for (int i = 0; i < width * height; i++) {
    printf("%02X ", image[i]);
  }
  printf("\n");

  // Free the memory
  free(image);

  return 0;
}
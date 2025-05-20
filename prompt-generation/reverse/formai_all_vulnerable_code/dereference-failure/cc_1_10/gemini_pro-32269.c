//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  // Allocate memory for the image
  unsigned char *image = malloc(WIDTH * HEIGHT * 3);

  // Set the background color to black
  for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
    image[i] = 0;
  }

  // Generate the fractal
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      // Calculate the complex number c corresponding to the pixel (x, y)
      double c_real = (x - WIDTH / 2.0) * 4.0 / WIDTH;
      double c_imag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;

      // Initialize the complex number z and iterate the Mandelbrot function
      double z_real = 0.0;
      double z_imag = 0.0;
      int iterations = 0;
      while (z_real * z_real + z_imag * z_imag < 4.0 && iterations < 256) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2.0 * z_real * z_imag + c_imag;
        z_real = temp;
        iterations++;
      }

      // Set the pixel color based on the number of iterations
      if (iterations == 256) {
        image[(y * WIDTH + x) * 3 + 0] = 0;
        image[(y * WIDTH + x) * 3 + 1] = 0;
        image[(y * WIDTH + x) * 3 + 2] = 0;
      } else {
        image[(y * WIDTH + x) * 3 + 0] = iterations * 2;
        image[(y * WIDTH + x) * 3 + 1] = iterations * 4;
        image[(y * WIDTH + x) * 3 + 2] = iterations * 8;
      }
    }
  }

  // Write the image to a PPM file
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  fwrite(image, 1, WIDTH * HEIGHT * 3, fp);
  fclose(fp);

  // Free the memory allocated for the image
  free(image);

  return 0;
}
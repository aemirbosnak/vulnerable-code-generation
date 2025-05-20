//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int escape_iterations = 1000;
  double escape_radius = 2.0;
  double zoom_factor = 0.5;
  int width = 800;
  int height = 600;
  double x_min = -2.0;
  double x_max = 2.0;
  double y_min = -1.5;
  double y_max = 1.5;
  double x_range = x_max - x_min;
  double y_range = y_max - y_min;
  
  // Allocate memory for the image data
  int* data = (int*)malloc(width * height * sizeof(int));

  // Generate fractal
  for (int i = 0; i < height; i++) {
    double y = (double)i * y_range / height + y_min;
    for (int j = 0; j < width; j++) {
      double x = (double)j * x_range / width + x_min;
      double zr = x;
      double zi = y;
      int k;
      for (k = 0; k < escape_iterations; k++) {
        double zr_new = zr * zr - zi * zi + x;
        double zi_new = 2 * zr * zi + y;
        if (zr_new * zr_new + zi_new * zi_new > escape_radius * escape_radius) {
          break;
        }
        zr = zr_new;
        zi = zi_new;
      }
      if (k == escape_iterations) {
        data[i * width + j] = 0x00000000; // black
      } else {
        double color = (double)k / escape_iterations;
        int blue = (int)(color * 255);
        int red = (int)((1 - color) * 255);
        data[i * width + j] = 0x00FF0000 | (blue << 8) | red; // blue-red gradient
      }
    }
  }

  // Output fractal as PPM image
  printf("P3\n");
  printf("%d %d\n", width, height);
  printf("255\n");
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int color = data[i * width + j];
      int r = (color >> 16) & 0xFF;
      int g = (color >> 8) & 0xFF;
      int b = color & 0xFF;
      printf("%d %d %d ", r, g, b);
    }
    printf("\n");
  }

  // Free memory
  free(data);

  return 0;
}
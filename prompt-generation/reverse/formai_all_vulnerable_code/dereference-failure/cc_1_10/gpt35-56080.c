//FormAI DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  // Set up variables
  int width = 800;
  int height = 600;
  float zoom = 1.5;
  float moveX = -0.5;
  float moveY = 0;
  
  // Allocate memory for image buffer
  int **image = (int **)malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    image[i] = (int *)malloc(sizeof(int) * width);
  }
  
  // Loop over each pixel and compute the Mandelbrot set
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      float zx = 0;
      float zy = 0;
      float cx = 1.5 * (x - width/2) / (0.5 * zoom * width) + moveX;
      float cy = (y - height/2) / (0.5 * zoom * height) + moveY;
      int i = 0;
      while (i < 100) {
        float new_zx = zx * zx - zy * zy + cx;
        float new_zy = 2 * zx * zy + cy;
        if (sqrt(new_zx * new_zx + new_zy * new_zy) > 2) {
          break;
        }
        zx = new_zx;
        zy = new_zy;
        i++;
      }
      image[y][x] = i * 255 / 100;
    }
  }
  
  // Write the image to a file
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P6\n%s %s\n255\n", width, height);
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      fputc(image[y][x], fp);
      fputc(image[y][x], fp);
      fputc(image[y][x], fp);
    }
  }
  fclose(fp);
  
  // Free the memory
  for (int i = 0; i < height; i++) {
    free(image[i]);
  }
  free(image);
  
  return 0;
}
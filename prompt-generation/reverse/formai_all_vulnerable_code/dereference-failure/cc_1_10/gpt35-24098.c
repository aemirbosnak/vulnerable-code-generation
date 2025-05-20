//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_ITERATIONS 100

int main () {
  double x, y, zx, zy, temp;
  int i, j, n;

  // Allocate memory for the image
  int *image = malloc(WIDTH * HEIGHT * sizeof(int));

  // Calculate the fractal
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      x = (i - WIDTH/2.0) * 4.0 / WIDTH;
      y = (j - HEIGHT/2.0) * 4.0 / HEIGHT;

      zx = x;
      zy = y;

      n = 0;
      while (n < MAX_ITERATIONS && zx*zx + zy*zy < 4) {
        temp = zx*zx - zy*zy + x;
        zy = 2*zx*zy + y;
        zx = temp;
        n++;
      }

      if (n == MAX_ITERATIONS) {
        image[i + j * WIDTH] = 0;
      } else {
        image[i + j * WIDTH] = 255 * n / MAX_ITERATIONS;
      }
    }
  }

  // Print the image as a PGM file
  printf("P2\n%d %d\n255\n", WIDTH, HEIGHT);
  for (i = 0; i < WIDTH; i++) {
    for (j = 0; j < HEIGHT; j++) {
      printf("%d ", image[i + j * WIDTH]);
    }
    printf("\n");
  }

  // Free memory
  free(image);

  return 0;
}
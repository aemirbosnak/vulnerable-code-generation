//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define escape radius of fractal
#define BAILOUT 2

//define number of iterations before color is assigned
#define MAX_ITERATIONS 1000

int main()
{
  //determine size of fractal image
  int WIDTH = 800;
  int HEIGHT = 600;

  //allocate memory for pixel array
  int *pixels = (int *)malloc(WIDTH * HEIGHT * sizeof(int));

  //determine center coordinates of fractal
  double cx = -0.5;
  double cy = 0;

  //determine zoom level of fractal
  double zoom = 1;

  //iterate over each pixel of image
  for(int y = 0; y < HEIGHT; y++)
  {
    for(int x = 0; x < WIDTH; x++)
    {
      //calculate coordinates of pixel in complex plane
      double zx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + cx;
      double zy = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + cy;

      //initialize variables for iteration
      double magnitude_squared = 0;
      int iterations = 0;

      //iterate until escape radius is exceeded or maximum iterations is reached
      while(magnitude_squared < BAILOUT * BAILOUT && iterations < MAX_ITERATIONS)
      {
        //calculate new complex number using Mandelbrot equation
        double new_zx = zx * zx - zy * zy + zx;
        double new_zy = 2 * zx * zy + zy;

        //update variables for next iteration
        zx = new_zx;
        zy = new_zy;
        magnitude_squared = zx * zx + zy * zy;
        iterations += 1;
      }

      //assign color based on number of iterations
      if(iterations == MAX_ITERATIONS)
      {
        pixels[y * WIDTH + x] = 0;
      }
      else
      {
        double color = log(iterations) / log(MAX_ITERATIONS);
        pixels[y * WIDTH + x] = (int)(color * 255);
      }
    }
  }

  //output pixel array as PPM image file
  FILE *fp = fopen("fractal.ppm", "wb");
  fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
  for(int i = 0; i < WIDTH * HEIGHT; i++)
  {
    fwrite(&pixels[i], 1, 3, fp);
  }
  fclose(fp);

  //free memory
  free(pixels);

  return 0;
}
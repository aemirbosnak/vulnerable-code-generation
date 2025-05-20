//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

#define MAX 1024

int main()
{
  int x, y, i, j, n;
  double dx, dy, x1, x2, y1, y2, r;
  char **buf;

  n = MAX;
  buf = (char *)malloc(n * n);

  x1 = -1.5;
  x2 = 1.5;
  y1 = -1.0;
  y2 = 1.0;
  r = 0.01;

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      dx = x1 + (x2 - x1) * (double)i / (n - 1);
      dy = y1 + (y2 - y1) * (double)j / (n - 1);
      r = 0.0;
      for (x = 0; x < MAX; x++)
      {
        for (y = 0; y < MAX; y++)
        {
          if (Mandelbrot(dx, dy, r) == 0)
          {
            buf[i * n + j] = 255;
          }
          else
          {
            buf[i * n + j] = 0;
          }
          r++;
        }
      }
    }
  }

  free(buf);

  return 0;
}

int Mandelbrot(double x, double y, double r)
{
  int i, j, z;
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < r; j++)
    {
      z = 0;
      for (int n = 0; z < MAX && n < 255; n++)
      {
        double w = x + (double)i / r * 2 - 1.0;
        double v = y + (double)j / r * 2 - 1.0;
        double z_new = w * w + v * v + z;
        z = z_new;
      }
      if (z == MAX)
      {
        return 0;
      }
    }
  }
  return 255;
}
//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a complex number type
typedef struct {
  double r, i; // real and imaginary parts
} complex;

// a function to add two complex numbers
complex add(complex a, complex b) {
  complex c;
  c.r = a.r + b.r;
  c.i = a.i + b.i;
  return c;
}

// a function to multiply two complex numbers
complex mul(complex a, complex b) {
  complex c;
  c.r = a.r * b.r - a.i * b.i;
  c.i = a.r * b.i + a.i * b.r;
  return c;
}

// a function to square a complex number
complex sqr(complex a) {
  return mul(a, a);
}

// a function to calculate the modulus of a complex number
double mod(complex a) {
  return sqrt(a.r * a.r + a.i * a.i);
}

// a function to generate a mandelbrot set
void mandelbrot(int width, int height, double x0, double y0, double zoom) {
  // create a 2D array of complex numbers
  complex **set = malloc(sizeof(complex *) * height);
  for (int i = 0; i < height; i++) {
    set[i] = malloc(sizeof(complex) * width);
  }

  // initialize the set
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      set[i][j].r = x0 + (j - width / 2) / zoom;
      set[i][j].i = y0 + (i - height / 2) / zoom;
    }
  }

  // iterate the set
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      complex z = set[i][j];
      for (int k = 0; k < 100; k++) {
        z = add(z, mul(z, z));
        if (mod(z) > 2) {
          break;
        }
      }
      set[i][j] = z;
    }
  }

  // print the set
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", set[i][j].r < 2 ? '.' : '*');
    }
    printf("\n");
  }

  // free the set
  for (int i = 0; i < height; i++) {
    free(set[i]);
  }
  free(set);
}

int main() {
  // generate a mandelbrot set
  mandelbrot(80, 24, -2.0, 1.0, 1.0);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
  double real;
  double imag;
} complex;

complex cadd(complex a, complex b) {
  complex c;
  c.real = a.real + b.real;
  c.imag = a.imag + b.imag;
  return c;
}

complex cmul(complex a, complex b) {
  complex c;
  c.real = a.real * b.real - a.imag * b.imag;
  c.imag = a.real * b.imag + a.imag * b.real;
  return c;
}

int main(int argc, char **argv) {
  int N = 1024;
  double fs = 1000.0;

  double *x = (double *)malloc(N * sizeof(double));
  double *y = (double *)malloc(N * sizeof(double));

  for (int n = 0; n < N; n++) {
    x[n] = sin(2 * PI * n / 128);
    y[n] = cos(2 * PI * n / 64);
  }

  complex *X = (complex *)malloc(N * sizeof(complex));
  complex *Y = (complex *)malloc(N * sizeof(complex));

  for (int n = 0; n < N; n++) {
    X[n].real = x[n];
    X[n].imag = 0.0;
    Y[n].real = y[n];
    Y[n].imag = 0.0;
  }

  complex *Z = (complex *)malloc(N * sizeof(complex));

  for (int n = 0; n < N; n++) {
    Z[n] = cmul(X[n], Y[n]);
  }

  for (int n = 0; n < N; n++) {
    x[n] = Z[n].real;
    y[n] = Z[n].imag;
  }

  free(X);
  free(Y);
  free(Z);

  for (int n = 0; n < N; n++) {
    printf("%f %f\n", x[n], y[n]);
  }

  free(x);
  free(y);

  return 0;
}
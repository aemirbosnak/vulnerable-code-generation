//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int N, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  double *x_real, *x_imag, *y_real, *y_imag, *z_real, *z_imag;

  if (argc != 2)
  {
    printf("Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  N = atoi(argv[1]);

  x_real = (double *)malloc(N * sizeof(double));
  x_imag = (double *)malloc(N * sizeof(double));
  y_real = (double *)malloc(N * sizeof(double));
  y_imag = (double *)malloc(N * sizeof(double));
  z_real = (double *)malloc(N * sizeof(double));
  z_imag = (double *)malloc(N * sizeof(double));

  for (i = 0; i < N; i++)
  {
    scanf("%lf %lf", &x_real[i], &x_imag[i]);
  }

  for (j = 0; j < N; j++)
  {
    scanf("%lf %lf", &y_real[j], &y_imag[j]);
  }

  for (k = 0; k < N; k++)
  {
    z_real[k] = x_real[k] * y_real[k] - x_imag[k] * y_imag[k];
    z_imag[k] = x_real[k] * y_imag[k] + x_imag[k] * y_real[k];
  }

  for (l = 0; l < N; l++)
  {
    printf("%lf %lf\n", z_real[l], z_imag[l]);
  }

  free(x_real);
  free(x_imag);
  free(y_real);
  free(y_imag);
  free(z_real);
  free(z_imag);

  return EXIT_SUCCESS;
}
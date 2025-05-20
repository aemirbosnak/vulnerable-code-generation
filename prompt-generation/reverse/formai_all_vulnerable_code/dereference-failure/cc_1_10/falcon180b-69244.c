//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define PI 3.14159265358979323846

int main(int argc, char *argv[]) {
  int N, M, i, j, k;
  double *data, *spectrum;
  fftw_complex *in, *out;
  fftw_plan plan;

  // Input signal parameters
  N = 1024;
  M = N / 2 + 1;

  // Allocate memory for input signal
  data = (double *)malloc(N * sizeof(double));

  // Generate input signal
  for (i = 0; i < N; i++) {
    data[i] = sin(2.0 * PI * i / N);
  }

  // Allocate memory for FFT input and output
  in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * M);

  // Copy input signal to FFT input
  for (i = 0; i < N; i++) {
    in[i][0] = data[i];
    in[i][1] = 0.0;
  }

  // Create FFT plan
  plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_MEASURE);

  // Execute FFT
  fftw_execute(plan);

  // Allocate memory for frequency spectrum
  spectrum = (double *)malloc(M * sizeof(double));

  // Calculate frequency spectrum
  for (i = 0; i < M; i++) {
    k = i * 2;
    spectrum[i] = sqrt(out[k][0] * out[k][0] + out[k][1] * out[k][1]);
  }

  // Print frequency spectrum
  for (i = 0; i < M; i++) {
    printf("%d -> %f\n", i, spectrum[i]);
  }

  // Free memory
  fftw_destroy_plan(plan);
  fftw_free(in);
  fftw_free(out);
  free(data);
  free(spectrum);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of data points
#define N 100

// Define the sampling frequency
#define Fs 1000

// Define the Nyquist frequency
#define Fnyquist Fs / 2

// Define the frequency of the sine wave
#define F 100

// Define the amplitude of the sine wave
#define A 1

// Generate a sine wave
double *generate_sine_wave() {
  double *x = (double *)malloc(N * sizeof(double));

  for (int n = 0; n < N; n++) {
    x[n] = A * sin(2 * M_PI * F * n / Fs);
  }

  return x;
}

// Compute the power spectral density (PSD) of a signal
double *compute_psd(double *x) {
  double *Pxx = (double *)malloc(N * sizeof(double));

  for (int f = 0; f < N; f++) {
    double sum = 0;

    for (int n = 0; n < N; n++) {
      sum += x[n] * exp(-2 * M_PI * f * n / Fs);
    }

    Pxx[f] = (1.0 / N) * fabs(sum);
  }

  return Pxx;
}

// Plot the PSD of a signal
void plot_psd(double *Pxx) {
  for (int f = 0; f < N; f++) {
    printf("%f %f\n", f / Fnyquist, Pxx[f]);
  }
}

int main() {
  // Generate a sine wave
  double *x = generate_sine_wave();

  // Compute the PSD of the sine wave
  double *Pxx = compute_psd(x);

  // Plot the PSD of the sine wave
  plot_psd(Pxx);

  // Free the memory allocated for the sine wave and the PSD
  free(x);
  free(Pxx);

  return 0;
}
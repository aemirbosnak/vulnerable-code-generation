//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 1024

// Function to generate a sine wave
double generate_sine_wave(double frequency, double sample_rate, double time) {
  return sin(2 * M_PI * frequency * time / sample_rate);
}

// Function to perform a Fast Fourier Transform (FFT)
void fft(double *x, int n) {
  // Base case: n == 1
  if (n == 1) {
    return;
  }

  // Calculate the midpoint of the array
  int m = n / 2;

  // Create two new arrays to store the even and odd elements of the original array
  double *even = malloc(m * sizeof(double));
  double *odd = malloc(m * sizeof(double));

  // Populate the even and odd arrays
  for (int i = 0; i < m; i++) {
    even[i] = x[2 * i];
    odd[i] = x[2 * i + 1];
  }

  // Recursively perform FFT on the even and odd arrays
  fft(even, m);
  fft(odd, m);

  // Combine the results of the even and odd FFTs
  for (int i = 0; i < m; i++) {
    double t = even[i] + odd[i] * cos(2 * M_PI * i / n);
    double u = even[i] - odd[i] * cos(2 * M_PI * i / n);
    x[i] = t;
    x[i + m] = u;
  }

  // Free the memory allocated for the even and odd arrays
  free(even);
  free(odd);
}

// Function to print the magnitude of the FFT results
void print_fft_magnitude(double *x, int n) {
  for (int i = 0; i < n; i++) {
    printf("%f\n", sqrt(x[i] * x[i]));
  }
}

int main() {
  // Generate a sine wave
  double frequency = 100;
  double sample_rate = 1024;
  double time = 1;
  double *signal = malloc(NUM_SAMPLES * sizeof(double));
  for (int i = 0; i < NUM_SAMPLES; i++) {
    signal[i] = generate_sine_wave(frequency, sample_rate, i * time / NUM_SAMPLES);
  }

  // Perform FFT on the sine wave
  fft(signal, NUM_SAMPLES);

  // Print the magnitude of the FFT results
  print_fft_magnitude(signal, NUM_SAMPLES);

  // Free the memory allocated for the signal
  free(signal);

  return 0;
}
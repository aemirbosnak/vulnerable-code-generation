//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex data type
typedef struct {
  float real;
  float imag;
} complex;

// Define the FFT function
void fft(complex *x, int n) {
  // Check if the number of samples is a power of 2
  if ((n & (n - 1)) != 0) {
    printf("Error: n must be a power of 2\n");
    return;
  }

  // Compute the FFT
  for (int k = 0; k < n; k++) {
    complex sum = {0, 0};
    for (int j = 0; j < n; j++) {
      complex w = {cos(2 * M_PI * j * k / n), sin(2 * M_PI * j * k / n)};
      complex product = {x[j].real * w.real - x[j].imag * w.imag,
                         x[j].real * w.imag + x[j].imag * w.real};
      sum.real += product.real;
      sum.imag += product.imag;
    }
    x[k] = sum;
  }
}

// Define the IFFT function
void ifft(complex *x, int n) {
  // Check if the number of samples is a power of 2
  if ((n & (n - 1)) != 0) {
    printf("Error: n must be a power of 2\n");
    return;
  }

  // Compute the IFFT
  for (int k = 0; k < n; k++) {
    complex sum = {0, 0};
    for (int j = 0; j < n; j++) {
      complex w = {cos(2 * M_PI * j * k / n), sin(2 * M_PI * j * k / n)};
      complex product = {x[j].real * w.real + x[j].imag * w.imag,
                         x[j].real * w.imag - x[j].imag * w.real};
      sum.real += product.real;
      sum.imag += product.imag;
    }
    x[k].real = sum.real / n;
    x[k].imag = sum.imag / n;
  }
}

// Define the main function
int main() {
  // Generate a test signal
  int n = 1024;
  complex *x = (complex *)malloc(n * sizeof(complex));
  for (int i = 0; i < n; i++) {
    x[i].real = sin(2 * M_PI * 100 * i / n) + sin(2 * M_PI * 200 * i / n) + sin(2 * M_PI * 300 * i / n);
    x[i].imag = 0;
  }

  // Compute the FFT
  fft(x, n);

  // Compute the IFFT
  ifft(x, n);

  // Print the result
  for (int i = 0; i < n; i++) {
    printf("%f %f\n", x[i].real, x[i].imag);
  }

  return 0;
}
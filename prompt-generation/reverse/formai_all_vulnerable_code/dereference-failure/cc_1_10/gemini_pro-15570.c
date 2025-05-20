//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex number structure
typedef struct {
  float real;
  float imag;
} complex_t;

// Define the function to generate a sinusoid
complex_t generate_sinusoid(float frequency, float sampling_rate, float time) {
  complex_t sinusoid;
  sinusoid.real = sin(2 * M_PI * frequency * time / sampling_rate);
  sinusoid.imag = 0;
  return sinusoid;
}

// Define the function to perform the DFT
complex_t* dft(complex_t* x, int N) {
  complex_t* X = (complex_t*)malloc(N * sizeof(complex_t));
  for (int k = 0; k < N; k++) {
    X[k].real = 0;
    X[k].imag = 0;
    for (int n = 0; n < N; n++) {
      X[k].real += x[n].real * cos(2 * M_PI * k * n / N) + x[n].imag * sin(2 * M_PI * k * n / N);
      X[k].imag += -x[n].real * sin(2 * M_PI * k * n / N) + x[n].imag * cos(2 * M_PI * k * n / N);
    }
  }
  return X;
}

// Define the function to plot the DFT results
void plot_dft(complex_t* X, int N) {
  // Create a gnuplot pipe
  FILE* gnuplot = popen("gnuplot", "w");

  // Set the plot title
  fprintf(gnuplot, "set title \"DFT Results\"\n");

  // Set the x-axis label
  fprintf(gnuplot, "set xlabel \"Frequency\"\n");

  // Set the y-axis label
  fprintf(gnuplot, "set ylabel \"Magnitude\"\n");

  // Plot the DFT results
  fprintf(gnuplot, "plot '-' with lines\n");
  for (int k = 0; k < N; k++) {
    fprintf(gnuplot, "%f %f\n", k, sqrt(X[k].real * X[k].real + X[k].imag * X[k].imag));
  }

  // Close the gnuplot pipe
  pclose(gnuplot);
}

int main() {
  // Define the parameters of the sinusoid
  float frequency = 100;
  float sampling_rate = 1000;
  float time = 1;

  // Generate the sinusoid
  complex_t sinusoid = generate_sinusoid(frequency, sampling_rate, time);

  // Perform the DFT on the sinusoid
  complex_t* X = dft(&sinusoid, 1);

  // Plot the DFT results
  plot_dft(X, 1);

  return 0;
}
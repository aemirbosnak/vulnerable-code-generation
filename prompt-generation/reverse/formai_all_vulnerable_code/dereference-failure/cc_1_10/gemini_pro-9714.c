//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a sine wave
double sine_wave(double t, double f, double A) {
  return A * sin(2 * M_PI * f * t);
}

// Function to generate a square wave
double square_wave(double t, double f, double A) {
  return A * ((t - floor(t / (1 / f))) < 0.5 ? 1 : -1);
}

// Function to generate a sawtooth wave
double sawtooth_wave(double t, double f, double A) {
  return A * (fmod(t, 1 / f) / (1 / f));
}

// Function to generate a triangle wave
double triangle_wave(double t, double f, double A) {
  return A * fabs(fmod(t, 1 / f) - 0.5) * 2;
}

// Function to plot a waveform
void plot_waveform(double *data, int n, double f, char *filename) {
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%f %f\n", i / f, data[i]);
  }
  fclose(fp);
}

int main() {
  // Define the parameters of the waveform
  double f = 100;  // Frequency in Hz
  double A = 1;  // Amplitude
  int n = 1000;  // Number of samples

  // Generate the waveform data
  double *sine_data = malloc(n * sizeof(double));
  double *square_data = malloc(n * sizeof(double));
  double *sawtooth_data = malloc(n * sizeof(double));
  double *triangle_data = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    double t = i / f;
    sine_data[i] = sine_wave(t, f, A);
    square_data[i] = square_wave(t, f, A);
    sawtooth_data[i] = sawtooth_wave(t, f, A);
    triangle_data[i] = triangle_wave(t, f, A);
  }

  // Plot the waveforms
  plot_waveform(sine_data, n, f, "sine_wave.txt");
  plot_waveform(square_data, n, f, "square_wave.txt");
  plot_waveform(sawtooth_data, n, f, "sawtooth_wave.txt");
  plot_waveform(triangle_data, n, f, "triangle_wave.txt");

  // Free the allocated memory
  free(sine_data);
  free(square_data);
  free(sawtooth_data);
  free(triangle_data);

  return 0;
}
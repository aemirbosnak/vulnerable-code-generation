//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024 // Number of samples
#define Fs 44100 // Sampling frequency (Hz)

// Function to generate a sine wave
double sine(double t, double f) {
  return sin(2 * M_PI * f * t);
}

// Function to generate a cosine wave
double cosine(double t, double f) {
  return cos(2 * M_PI * f * t);
}

// Function to generate a square wave
double square(double t, double f) {
  return (t - (int)t) < 0.5 ? 1 : -1;
}

// Function to generate a triangle wave
double triangle(double t, double f) {
  return (t - (int)t) * 4 - 1;
}

// Function to generate a sawtooth wave
double sawtooth(double t, double f) {
  return (t - (int)t) * 2 - 1;
}

int main() {
  // Generate a sine wave
  double *y = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++) {
    y[i] = sine(i / (double)Fs, 440);
  }

  // Write the sine wave to a file
  FILE *fp = fopen("sine.wav", "wb");
  fwrite(y, sizeof(double), N, fp);
  fclose(fp);

  // Generate a cosine wave
  double *x = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++) {
    x[i] = cosine(i / (double)Fs, 440);
  }

  // Write the cosine wave to a file
  fp = fopen("cosine.wav", "wb");
  fwrite(x, sizeof(double), N, fp);
  fclose(fp);

  // Generate a square wave
  double *z = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++) {
    z[i] = square(i / (double)Fs, 440);
  }

  // Write the square wave to a file
  fp = fopen("square.wav", "wb");
  fwrite(z, sizeof(double), N, fp);
  fclose(fp);

  // Generate a triangle wave
  double *w = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++) {
    w[i] = triangle(i / (double)Fs, 440);
  }

  // Write the triangle wave to a file
  fp = fopen("triangle.wav", "wb");
  fwrite(w, sizeof(double), N, fp);
  fclose(fp);

  // Generate a sawtooth wave
  double *v = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++) {
    v[i] = sawtooth(i / (double)Fs, 440);
  }

  // Write the sawtooth wave to a file
  fp = fopen("sawtooth.wav", "wb");
  fwrite(v, sizeof(double), N, fp);
  fclose(fp);

  // Free the allocated memory
  free(y);
  free(x);
  free(z);
  free(w);
  free(v);

  return 0;
}
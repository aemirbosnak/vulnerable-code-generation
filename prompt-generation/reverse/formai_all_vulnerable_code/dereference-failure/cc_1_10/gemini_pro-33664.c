//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define TWOPI 6.28318530717958647692

// Function to generate a sine wave
double sine(double frequency, double time) {
  return sin(2 * PI * frequency * time);
}

// Function to generate a square wave
double square(double frequency, double time) {
  return signbit(sin(2 * PI * frequency * time));
}

// Function to generate a sawtooth wave
double sawtooth(double frequency, double time) {
  return 2 * (time * frequency - floor(time * frequency)) - 1;
}

// Function to generate a triangle wave
double triangle(double frequency, double time) {
  return fabs(sawtooth(frequency, time));
}

int main() {
  // Set the sampling rate
  double sampling_rate = 44100;

  // Set the duration of the sound
  double duration = 1;

  // Create a buffer to store the sound data
  double *buffer = malloc(sampling_rate * duration * sizeof(double));

  // Generate the sound data
  for (int i = 0; i < sampling_rate * duration; i++) {
    double time = i / sampling_rate;
    buffer[i] = sine(440, time) + square(880, time) + sawtooth(1760, time) + triangle(3520, time);
  }

  // Write the sound data to a file
  FILE *file = fopen("sound.wav", "wb");
  fwrite(buffer, sizeof(double), sampling_rate * duration, file);
  fclose(file);

  // Free the buffer
  free(buffer);

  return 0;
}
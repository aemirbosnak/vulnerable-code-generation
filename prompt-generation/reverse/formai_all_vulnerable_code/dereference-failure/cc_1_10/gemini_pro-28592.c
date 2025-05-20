//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to generate a sine wave
double sine_wave(double frequency, double amplitude, double phase, double time) {
  return amplitude * sin(2 * PI * frequency * time + phase);
}

// Function to generate a square wave
double square_wave(double frequency, double amplitude, double phase, double time) {
  return amplitude * signbit(sin(2 * PI * frequency * time + phase));
}

// Function to generate a triangle wave
double triangle_wave(double frequency, double amplitude, double phase, double time) {
  return amplitude * abs(sin(2 * PI * frequency * time + phase));
}

// Function to generate a sawtooth wave
double sawtooth_wave(double frequency, double amplitude, double phase, double time) {
  return amplitude * (2 * fmod(time, 1 / frequency) - 1);
}

// Function to plot a waveform
void plot_waveform(double *waveform, int num_samples, double sample_rate) {
  for (int i = 0; i < num_samples; i++) {
    double time = i / sample_rate;
    printf("%f %f\n", time, waveform[i]);
  }
}

int main() {
  // Generate a sine wave
  int num_samples = 1000;
  double sample_rate = 1000;
  double frequency = 100;
  double amplitude = 1;
  double phase = 0;
  double *sine_waveform = malloc(sizeof(double) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    double time = i / sample_rate;
    sine_waveform[i] = sine_wave(frequency, amplitude, phase, time);
  }

  // Generate a square wave
  double *square_waveform = malloc(sizeof(double) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    double time = i / sample_rate;
    square_waveform[i] = square_wave(frequency, amplitude, phase, time);
  }

  // Generate a triangle wave
  double *triangle_waveform = malloc(sizeof(double) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    double time = i / sample_rate;
    triangle_waveform[i] = triangle_wave(frequency, amplitude, phase, time);
  }

  // Generate a sawtooth wave
  double *sawtooth_waveform = malloc(sizeof(double) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    double time = i / sample_rate;
    sawtooth_waveform[i] = sawtooth_wave(frequency, amplitude, phase, time);
  }

  // Plot the waveforms
  plot_waveform(sine_waveform, num_samples, sample_rate);
  plot_waveform(square_waveform, num_samples, sample_rate);
  plot_waveform(triangle_waveform, num_samples, sample_rate);
  plot_waveform(sawtooth_waveform, num_samples, sample_rate);

  // Free the waveforms
  free(sine_waveform);
  free(square_waveform);
  free(triangle_waveform);
  free(sawtooth_waveform);

  return 0;
}
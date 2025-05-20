//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of samples in the signal
#define NUM_SAMPLES 1024

// Define the sampling rate
#define SAMPLING_RATE 44100

// Define the cutoff frequency for the low-pass filter
#define CUTOFF_FREQUENCY 1000

// Generate a random signal
float *generate_signal(int num_samples, int sampling_rate) {
  float *signal = malloc(sizeof(float) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    signal[i] = (float)rand() / (float)RAND_MAX;
  }
  return signal;
}

// Apply a low-pass filter to the signal
float *low_pass_filter(float *signal, int num_samples, int sampling_rate, float cutoff_frequency) {
  float *filtered_signal = malloc(sizeof(float) * num_samples);
  for (int i = 0; i < num_samples; i++) {
    float cutoff_angle = 2 * M_PI * cutoff_frequency / sampling_rate;
    float alpha = sin(cutoff_angle) / (2 * sin(cutoff_angle / 2));
    filtered_signal[i] = alpha * filtered_signal[i] + (1 - alpha) * signal[i];
  }
  return filtered_signal;
}

// Write the signal to a file
void write_signal(float *signal, int num_samples, char *filename) {
  FILE *file = fopen(filename, "w");
  for (int i = 0; i < num_samples; i++) {
    fprintf(file, "%f\n", signal[i]);
  }
  fclose(file);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the signal
  float *signal = generate_signal(NUM_SAMPLES, SAMPLING_RATE);

  // Apply the low-pass filter
  float *filtered_signal = low_pass_filter(signal, NUM_SAMPLES, SAMPLING_RATE, CUTOFF_FREQUENCY);

  // Write the signal to a file
  write_signal(signal, NUM_SAMPLES, "signal.txt");
  write_signal(filtered_signal, NUM_SAMPLES, "filtered_signal.txt");

  // Free the memory
  free(signal);
  free(filtered_signal);

  return 0;
}
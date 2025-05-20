//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of samples
#define NUM_SAMPLES 256

// Define the sampling frequency
#define SAMPLING_FREQUENCY 1000

// Generate a sine wave
void generate_sine_wave(float *samples, int num_samples, float sampling_frequency) {
  float increment = 2 * M_PI * sampling_frequency / num_samples;

  for (int i = 0; i < num_samples; i++) {
    samples[i] = sin(increment * i);
  }
}

// Apply a moving average filter to the samples
void apply_moving_average_filter(float *samples, int num_samples, int filter_order) {
  float sum = 0;
  float *filtered_samples = malloc(num_samples * sizeof(float));

  // Calculate the sum of the first filter_order samples
  for (int i = 0; i < filter_order; i++) {
    sum += samples[i];
  }

  // Calculate the filtered samples
  for (int i = 0; i < num_samples; i++) {
    filtered_samples[i] = sum / filter_order;

    // Update the sum by subtracting the oldest sample and adding the newest sample
    sum -= samples[i - filter_order];
    sum += samples[i + filter_order];
  }

  // Copy the filtered samples back to the original array
  for (int i = 0; i < num_samples; i++) {
    samples[i] = filtered_samples[i];
  }

  free(filtered_samples);
}

// Print the samples to the console
void print_samples(float *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    printf("%f\n", samples[i]);
  }
}

int main() {
  // Generate a sine wave
  float *samples = malloc(NUM_SAMPLES * sizeof(float));
  generate_sine_wave(samples, NUM_SAMPLES, SAMPLING_FREQUENCY);

  // Apply a moving average filter to the samples
  apply_moving_average_filter(samples, NUM_SAMPLES, 10);

  // Print the samples to the console
  print_samples(samples, NUM_SAMPLES);

  free(samples);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a sine wave
double sine_wave(double frequency, double sampling_rate, double time) {
  return sin(2 * M_PI * frequency * time / sampling_rate);
}

// Function to apply a moving average filter to a signal
double moving_average_filter(double *signal, int signal_length, int filter_order) {
  double sum = 0;
  for (int i = 0; i < filter_order; i++) {
    sum += signal[i];
  }
  return sum / filter_order;
}

int main() {
  // Define the parameters of the sine wave
  double frequency = 1000;  // in Hz
  double sampling_rate = 44100;  // in Hz
  double duration = 1;  // in seconds

  // Generate the sine wave
  int num_samples = sampling_rate * duration;
  double *signal = malloc(num_samples * sizeof(double));
  for (int i = 0; i < num_samples; i++) {
    signal[i] = sine_wave(frequency, sampling_rate, i / sampling_rate);
  }

  // Apply the moving average filter to the sine wave
  int filter_order = 10;
  double *filtered_signal = malloc(num_samples * sizeof(double));
  for (int i = 0; i < num_samples; i++) {
    filtered_signal[i] = moving_average_filter(signal, num_samples, filter_order);
  }

  // Print the original and filtered signals
  for (int i = 0; i < num_samples; i++) {
    printf("Original signal: %f\n", signal[i]);
    printf("Filtered signal: %f\n", filtered_signal[i]);
  }

  // Free the allocated memory
  free(signal);
  free(filtered_signal);

  return 0;
}
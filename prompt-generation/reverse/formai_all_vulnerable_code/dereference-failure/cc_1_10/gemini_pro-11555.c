//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of samples per second
#define SAMPLE_RATE 44100

// Define the number of channels
#define NUM_CHANNELS 1

// Define the length of the signal in seconds
#define SIGNAL_LENGTH 1

// Define the frequency of the signal in Hertz
#define SIGNAL_FREQUENCY 440

// Generate a sine wave
void generate_sine_wave(float *data, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    data[i] = sin(2 * M_PI * SIGNAL_FREQUENCY * i / SAMPLE_RATE);
  }
}

// Play the signal
void play_signal(float *data, int num_samples) {
  // Open the audio device
  FILE *audio_file = fopen("output.wav", "wb");

  // Write the header
  fprintf(audio_file, "RIFF");
  fprintf(audio_file, "%c%c%c%c", 36 + sizeof(data), 0, 0, 0);
  fprintf(audio_file, "WAVEfmt ");
  fprintf(audio_file, "%c%c%c%c", 16, 0, 0, 0);
  fprintf(audio_file, "%c%c", 1, 0);
  fprintf(audio_file, "%c%c", NUM_CHANNELS, 0);
  fprintf(audio_file, "%c%c%c%c", 44100, 0, 0, 0);
  fprintf(audio_file, "%c%c%c%c", NUM_CHANNELS * 44100 / 8, 0, 0, 0);
  fprintf(audio_file, "%c%c", 4, 0);
  fprintf(audio_file, "%c%c%c%c", 16, 0, 0, 0);
  fprintf(audio_file, "data");
  fprintf(audio_file, "%c%c%c%c", num_samples * sizeof(float), 0, 0, 0);

  // Write the data
  for (int i = 0; i < num_samples; i++) {
    fwrite(&data[i], sizeof(float), 1, audio_file);
  }

  // Close the audio device
  fclose(audio_file);
}

int main() {
  // Allocate memory for the signal data
  float *data = (float *)malloc(SAMPLE_RATE * SIGNAL_LENGTH * sizeof(float));

  // Generate the sine wave
  generate_sine_wave(data, SAMPLE_RATE * SIGNAL_LENGTH);

  // Play the signal
  play_signal(data, SAMPLE_RATE * SIGNAL_LENGTH);

  // Free the memory for the signal data
  free(data);

  return 0;
}
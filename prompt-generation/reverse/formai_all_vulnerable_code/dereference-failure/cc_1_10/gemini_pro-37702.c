//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the sample rate and the number of samples
#define SAMPLE_RATE 44100
#define NUM_SAMPLES 1024

// Define the signal frequency and amplitude
#define SIGNAL_FREQ 440
#define SIGNAL_AMPLITUDE 0.5

// Generate a sine wave
void generate_sine_wave(float *samples, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    samples[i] = SIGNAL_AMPLITUDE * sin(2 * M_PI * SIGNAL_FREQ * i / SAMPLE_RATE);
  }
}

// Write the samples to a WAV file
void write_wav_file(float *samples, int num_samples) {
  // Open the WAV file for writing
  FILE *wav_file = fopen("output.wav", "wb");

  // Write the WAV header
  fwrite("RIFF", 1, 4, wav_file);
  int file_size = 36 + num_samples * sizeof(float);
  fwrite(&file_size, 1, 4, wav_file);
  fwrite("WAVE", 1, 4, wav_file);
  fwrite("fmt ", 1, 4, wav_file);
  int sub_chunk_size = 16;
  fwrite(&sub_chunk_size, 1, 4, wav_file);
  short audio_format = 1;
  fwrite(&audio_format, 1, 2, wav_file);
  short num_channels = 1;
  fwrite(&num_channels, 1, 2, wav_file);
  int sample_rate = SAMPLE_RATE;
  fwrite(&sample_rate, 1, 4, wav_file);
  int byte_rate = SAMPLE_RATE * sizeof(float);
  fwrite(&byte_rate, 1, 4, wav_file);
  short block_align = sizeof(float);
  fwrite(&block_align, 1, 2, wav_file);
  short bits_per_sample = 32;
  fwrite(&bits_per_sample, 1, 2, wav_file);
  fwrite("data", 1, 4, wav_file);
  int data_size = num_samples * sizeof(float);
  fwrite(&data_size, 1, 4, wav_file);

  // Write the samples to the WAV file
  fwrite(samples, 1, data_size, wav_file);

  // Close the WAV file
  fclose(wav_file);
}

// Main function
int main() {
  // Allocate memory for the samples
  float *samples = malloc(NUM_SAMPLES * sizeof(float));

  // Generate the sine wave
  generate_sine_wave(samples, NUM_SAMPLES);

  // Write the samples to a WAV file
  write_wav_file(samples, NUM_SAMPLES);

  // Free the memory allocated for the samples
  free(samples);

  return 0;
}
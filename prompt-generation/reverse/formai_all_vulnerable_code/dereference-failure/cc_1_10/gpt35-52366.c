//FormAI DATASET v1.0 Category: Audio processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {

  // Generate a 440Hz sine wave
  unsigned int samplerate = 48000;
  unsigned int duration = 5;
  double frequency = 440; // Hz
  double phase = 0;
  double amplitude = 0.5;

  unsigned int samples = samplerate * duration;
  double* buffer = (double*)malloc(samples * sizeof(double));

  unsigned int i;
  for (i = 0; i < samples; i++) {
    buffer[i] = amplitude * sin(2 * PI * frequency * i / samplerate + phase);
  }

  // Apply a low-pass filter
  double cutoff_frequency = 8000; // Hz
  double resonance = 0.5;
  double filter_coeff = 2 * PI * cutoff_frequency / samplerate;
  double feedback = resonance * (1 - filter_coeff) / (1 + filter_coeff);
  double lowpass_state = 0;
  
  for (i = 0; i < samples; i++) {
    double input = buffer[i];
    double output = input + feedback * lowpass_state;
    lowpass_state = output;
    buffer[i] = output;
  }

  // Normalize the output
  double max_amplitude = 0;
  for (i = 0; i < samples; i++) {
    if (fabs(buffer[i]) > max_amplitude) {
      max_amplitude = fabs(buffer[i]);
    }
  }

  for (i = 0; i < samples; i++) {
    buffer[i] /= max_amplitude;
  }

  // Write to a wav file
  FILE* file = fopen("example.wav", "wb");
  if (file == NULL) {
    fprintf(stderr, "Error: failed to open file for writing\n");
    return 1;
  }

  unsigned int bitdepth = 16;
  unsigned int bytes_per_sample = bitdepth / 8;
  unsigned int subchunk2size = samples * bytes_per_sample;
  unsigned int chunksize = 36 + subchunk2size;

  fwrite("RIFF", 4, 1, file);
  fwrite(&chunksize, 4, 1, file);
  fwrite("WAVE", 4, 1, file);
  fwrite("fmt ", 4, 1, file);
  unsigned int subchunk1size = 16;
  unsigned short audio_format = 1;
  unsigned short numchannels = 1;
  unsigned int samplerate_uint = samplerate;
  unsigned int byterate = samplerate * numchannels * bytes_per_sample;
  unsigned short blockalign = numchannels * bytes_per_sample;
  fwrite(&subchunk1size, 4, 1, file);
  fwrite(&audio_format, 2, 1, file);
  fwrite(&numchannels, 2, 1, file);
  fwrite(&samplerate_uint, 4, 1, file);
  fwrite(&byterate, 4, 1, file);
  fwrite(&blockalign, 2, 1, file);
  fwrite(&bitdepth, 2, 1, file);
  fwrite("data", 4, 1, file);
  fwrite(&subchunk2size, 4, 1, file);

  for (i = 0; i < samples; i++) {
    short sample = (short)(buffer[i] * 32767);
    fwrite(&sample, bytes_per_sample, 1, file);
  }

  fclose(file);
  free(buffer);

  printf("Wrote %s\n", "example.wav");

  return 0;
}
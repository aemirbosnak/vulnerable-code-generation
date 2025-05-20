//FormAI DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SAMPLE_RATE 44100 // audio sample rate in Hz
#define PEAK_AMPLITUDE 32760 // maximum value of a sample (signed 16-bit integer)

int main() {
  int num_samples = SAMPLE_RATE * 5; // creates a 5 second audio clip
  short *samples = (short*) malloc(num_samples * sizeof(short)); // allocate memory for audio samples

  // Generate a 440 Hz sine wave using the formula A*sin(2*pi*f*t)
  float frequency = 440.0f; // frequency of the sine wave in Hz
  float amplitude = PEAK_AMPLITUDE / 2.0f; // amplitude of the sine wave
  for (int i = 0; i < num_samples; i++) {
    float time = (float)i / (float)SAMPLE_RATE; // calculate time in seconds from sample index
    samples[i] = (short)(amplitude * sin(2.0f * M_PI * frequency * time));
  }

  // Write the audio samples to a file
  FILE *file = fopen("output.wav", "wb");
  if (file == NULL) {
    printf("Error: Could not open file for writing.\n");
    return 1;
  }

  // Write a WAV file header
  char header[44];
  memset(header, 0, sizeof(header));
  memcpy(header, "RIFF", 4);
  *(int*)(header + 4) = 36 + num_samples * sizeof(short); // size of file in bytes - 8
  memcpy(header + 8, "WAVE", 4);
  memcpy(header + 12, "fmt ", 4);
  *(int*)(header + 16) = 16; // size of chunk (16 for PCM format)
  *(short*)(header + 20) = 1; // PCM format
  *(short*)(header + 22) = 1; // mono (1 channel)
  *(int*)(header + 24) = SAMPLE_RATE; // sample rate in Hz
  *(int*)(header + 28) = SAMPLE_RATE * sizeof(short); // byte rate
  *(short*)(header + 32) = sizeof(short); // block align
  *(short*)(header + 34) = 16; // bits per sample
  memcpy(header + 36, "data", 4);
  *(int*)(header + 40) = num_samples * sizeof(short); // size of data chunk
  fwrite(header, 1, sizeof(header), file);

  // Write the audio samples to the file as 16-bit signed integers
  fwrite(samples, sizeof(short), num_samples, file);
  fclose(file);

  free(samples); // free memory

  printf("Audio processing complete. Check the output.wav file for the result.\n");

  return 0;
}
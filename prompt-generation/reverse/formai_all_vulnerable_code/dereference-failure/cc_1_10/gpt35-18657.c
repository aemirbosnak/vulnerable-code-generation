//FormAI DATASET v1.0 Category: Digital signal processing ; Style: enthusiastic
// Welcome to the exciting world of Digital Signal Processing using C!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 44100
#define FREQUENCY 1000
#define AMPLITUDE 10000
#define DURATION 5

int main()
{
  int n = SAMPLING_RATE * DURATION; // total number of samples
  double theta = 2 * M_PI * FREQUENCY / SAMPLING_RATE; // angular frequency
  
  // create an array of integers to store the samples
  int* samples = (int*)malloc(sizeof(int) * n);
  
  // generate the sine wave samples
  for (int i = 0; i < n; i++)
  {
    samples[i] = AMPLITUDE * sin(theta * i);
  }
  
  // write the samples to a WAV file
  FILE* file = fopen("sine.wav", "wb");
  
  // write WAV header
  fwrite("RIFF", 4, 1, file);
  int chunk_size = 36 + n * 2;
  fwrite(&chunk_size, 4, 1, file);
  fwrite("WAVE", 4, 1, file);
  fwrite("fmt ", 4, 1, file);
  int subchunk1_size = 16;
  fwrite(&subchunk1_size, 4, 1, file);
  short audio_format = 1;
  fwrite(&audio_format, 2, 1, file);
  short num_channels = 1;
  fwrite(&num_channels, 2, 1, file);
  int sample_rate = SAMPLING_RATE;
  fwrite(&sample_rate, 4, 1, file);
  int byte_rate = SAMPLING_RATE * 2;
  fwrite(&byte_rate, 4, 1, file);
  short block_align = 2;
  fwrite(&block_align, 2, 1, file);
  short bits_per_sample = 16;
  fwrite(&bits_per_sample, 2, 1, file);
  fwrite("data", 4, 1, file);
  fwrite(&n, 4, 1, file);
  
  // write audio data
  for (int i = 0; i < n; i++)
  {
    fwrite(&samples[i], 2, 1, file);
  }
  
  // clean up
  free(samples);
  fclose(file);
  
  printf("Sine wave generated successfully and saved to sine.wav!\n");
  
  return 0;
}
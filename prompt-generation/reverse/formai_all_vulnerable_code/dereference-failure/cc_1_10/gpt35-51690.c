//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100

int main()
{
  //Generate a sine wave
  double frequency = 440.0;
  double duration = 2.0; //seconds
  int sample_count = duration * SAMPLE_RATE;
  double *samples = malloc(sample_count * sizeof(double));
  double max_amplitude = 0;
  for (int i = 0; i < sample_count; i++)
  {
    double t = (double)i / SAMPLE_RATE;
    double amplitude = sin(2 * M_PI * frequency * t);
    samples[i] = amplitude;
    if (amplitude > max_amplitude) max_amplitude = amplitude;
  }

  //Normalize the amplitude
  for (int i = 0; i < sample_count; i++)
  {
    samples[i] /= max_amplitude;
  }

  //Apply a low-pass filter
  double cutoff_frequency = 1000.0;
  double rc = 1.0 / (2 * M_PI * cutoff_frequency);
  double dt = 1.0 / SAMPLE_RATE;
  double alpha = dt / (rc + dt);
  double *filtered_samples = malloc(sample_count * sizeof(double));
  filtered_samples[0] = samples[0];
  for (int i = 1; i < sample_count; i++)
  {
    filtered_samples[i] = alpha * samples[i] + (1 - alpha) * filtered_samples[i-1];
  }

  //Save the filtered samples to a file
  FILE *f = fopen("output.raw", "wb");
  fwrite(filtered_samples, sizeof(double), sample_count, f);
  fclose(f);

  free(samples);
  free(filtered_samples);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

typedef struct {
  double sampleRate;
  double samplingInterval;
  int numSamples;
  short* samples;
} AudioData;

AudioData* createAudioData(double sampleRate, double samplingInterval, int numSamples) {
  AudioData* data = malloc(sizeof(AudioData));

  data->sampleRate = sampleRate;
  data->samplingInterval = samplingInterval;
  data->numSamples = numSamples;
  data->samples = malloc(numSamples * sizeof(short));

  return data;
}

void freeAudioData(AudioData* data) {
  free(data->samples);
  free(data);
}

short generateSine(double frequency, double time, int numSamples) {
  short sample = 0;
  for (int n = 0; n < numSamples; n++) {
    double t = n / frequency;
    sample += (short)(sin(2 * PI * t) * 127);
  }

  return sample;
}

int main() {
  AudioData* data = createAudioData(44100, 1/44100, 1000);

  for (int n = 0; n < data->numSamples; n++) {
    data->samples[n] = generateSine(440, n / data->sampleRate, data->numSamples);
  }

  freeAudioData(data);

  return 0;
}
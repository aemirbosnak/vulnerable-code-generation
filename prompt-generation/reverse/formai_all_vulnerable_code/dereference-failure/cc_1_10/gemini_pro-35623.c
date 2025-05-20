//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double freq;
  double amp;
  double phase;
} SineWave;

SineWave* createSineWave(double freq, double amp, double phase) {
  SineWave* wave = malloc(sizeof(SineWave));
  wave->freq = freq;
  wave->amp = amp;
  wave->phase = phase;
  return wave;
}

void freeSineWave(SineWave* wave) {
  free(wave);
}

double getSineValue(SineWave* wave, double time) {
  return wave->amp * sin(2 * M_PI * wave->freq * time + wave->phase);
}

int main() {
  // Create an array of sine waves
  const int numWaves = 3;
  SineWave* waves[numWaves];
  waves[0] = createSineWave(440, 0.5, 0);
  waves[1] = createSineWave(220, 0.25, M_PI/2);
  waves[2] = createSineWave(880, 0.125, M_PI);

  // Process the audio signal
  const int numSamples = 44100;
  double samples[numSamples];
  for (int i = 0; i < numSamples; i++) {
    double sample = 0;
    for (int j = 0; j < numWaves; j++) {
      sample += getSineValue(waves[j], i / 44100.0);
    }
    samples[i] = sample;
  }

  // Write the audio signal to a file
  FILE* file = fopen("audio.wav", "wb");
  fwrite("RIFF", 1, 4, file);
  fwrite(&numSamples, 4, 1, file);
  fwrite("WAVEfmt ", 1, 8, file);
  fwrite("\x10\x00\x00\x00\x01\x00\x01\x00\x80\x3e\x00\x00\x64\x61\x74\x61", 1, 16, file);
  fwrite(samples, sizeof(double), numSamples, file);
  fclose(file);

  // Free the sine waves
  for (int i = 0; i < numWaves; i++) {
    freeSineWave(waves[i]);
  }

  return 0;
}
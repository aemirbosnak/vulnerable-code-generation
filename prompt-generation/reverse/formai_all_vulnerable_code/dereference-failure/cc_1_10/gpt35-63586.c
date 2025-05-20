//FormAI DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to create a sine wave
void createSineWave(float *output, float freq, int sampleRate, float duration) {
  int i;
  int numSamples = (int) (duration * sampleRate);
  
  for (i = 0; i < numSamples; i++) {
    float t = (float) i / sampleRate;
    output[i] = sin(2 * M_PI * freq * t);
  }
}

// Function to apply a low-pass filter to an audio signal
void applyLowPassFilter(float *input, float *output, int numSamples, float sampleRate, float cutoffFreq) {
  float RC = 1 / (2 * M_PI * cutoffFreq);
  float dt = 1 / sampleRate;
  float alpha = dt / (RC + dt);
  float prevOutput = 0;
  
  int i;
  for (i = 0; i < numSamples; i++) {
    output[i] = alpha * input[i] + (1 - alpha) * prevOutput;
    prevOutput = output[i];
  }
}

int main() {
  // Define parameters for creating a sine wave
  float freq = 440; // A4 note frequency
  int sampleRate = 44100;
  float duration = 1; // 1 second duration
  
  // Create a sine wave
  float *sineWave = malloc(sampleRate * duration * sizeof(float));
  createSineWave(sineWave, freq, sampleRate, duration);
  
  // Define parameters for applying a low-pass filter
  float cutoffFreq = 2000; // Hz
  float *filteredWave = malloc(sampleRate * duration * sizeof(float));
  
  // Apply low-pass filter to the sine wave
  applyLowPassFilter(sineWave, filteredWave, sampleRate * duration, sampleRate, cutoffFreq);
  
  // Output the filtered wave to a file for playback
  FILE *outputFile = fopen("sine_wave_lowpass_filtered.bin", "wb");
  fwrite(filteredWave, sizeof(float), sampleRate * duration, outputFile);
  fclose(outputFile);
  
  printf("Done!\n");
  
  return 0;
}
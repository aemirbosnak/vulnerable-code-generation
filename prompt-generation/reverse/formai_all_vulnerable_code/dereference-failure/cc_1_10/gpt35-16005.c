//FormAI DATASET v1.0 Category: Audio processing ; Style: ultraprecise
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

int main() {

  // Define input variables
  float frequency = 440.0;
  float amplitude = 0.8;
  float duration = 2.0;

  // Define output variables
  float *output = malloc(SAMPLE_RATE * duration * sizeof(float));
  int n = 0;

  // Generate sine wave
  for (int i = 0; i < SAMPLE_RATE * duration; i++) {
    output[i] = amplitude * sin(2 * PI * frequency * i / SAMPLE_RATE);
    n++;
  }

  // Add reverb effect
  float *reverb = malloc(SAMPLE_RATE * duration * sizeof(float));
  for (int i = 0; i < SAMPLE_RATE * duration; i++) {
    float value = 0.0;
    for (int j = 0; j < 10; j++) {
      if (i - j < 0) {
        continue;
      }
      value += output[i - j];
    }
    value *= 0.2;
    reverb[i] = value;
  }

  // Print output to file
  FILE *file;
  file = fopen("output.txt", "w");
  for (int i = 0; i < SAMPLE_RATE * duration; i++) {
    fprintf(file, "%f\n", reverb[i]);
  }
  fclose(file);

  free(output);
  free(reverb);

  return 0;
}
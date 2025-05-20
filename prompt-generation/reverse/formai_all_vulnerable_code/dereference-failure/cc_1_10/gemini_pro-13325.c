//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <input file> <output file> <sample rate>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *input_file = argv[1];
  const char *output_file = argv[2];
  const float sample_rate = atof(argv[3]);

  // Read the input file into memory.
  FILE *input = fopen(input_file, "rb");
  if (!input) {
    perror("fopen");
    return EXIT_FAILURE;
  }
  fseek(input, 0, SEEK_END);
  size_t input_size = ftell(input);
  rewind(input);
  int16_t *input_buffer = malloc(input_size);
  if (!input_buffer) {
    perror("malloc");
    fclose(input);
    return EXIT_FAILURE;
  }
  fread(input_buffer, 1, input_size, input);
  fclose(input);

  // Create the output file.
  FILE *output = fopen(output_file, "wb");
  if (!output) {
    perror("fopen");
    free(input_buffer);
    return EXIT_FAILURE;
  }

  // Process the audio data.
  const size_t output_size = input_size;
  int16_t *output_buffer = malloc(output_size);
  if (!output_buffer) {
    perror("malloc");
    free(input_buffer);
    fclose(output);
    return EXIT_FAILURE;
  }
  int offset = 0;
  int delay = 100000;
  float amplitude = 100;
  float frequency = 440;
  float gain = 0.9;
  for (; offset + delay < output_size; offset++) {
    float sample = input_buffer[offset] + gain * input_buffer[offset - delay];
    float sine = amplitude * sin(2 * PI * frequency * offset / sample_rate);
    output_buffer[offset] = sine + sample;
  }

  // Write the output file to disk.
  fwrite(output_buffer, 1, output_size, output);
  fclose(output);

  // Free the memory.
  free(input_buffer);
  free(output_buffer);

  return EXIT_SUCCESS;
}
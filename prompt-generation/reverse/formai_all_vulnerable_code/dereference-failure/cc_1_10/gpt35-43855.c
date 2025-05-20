//FormAI DATASET v1.0 Category: Digital signal processing ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE 44100.0
#define PI 3.14159265358979323846

typedef struct {
  double* buffer;
  size_t length;
  size_t write_index;
} delay_line_t;

void delay_line_init(delay_line_t* delay_line, size_t delay_length) {
  delay_line->length = delay_length;
  delay_line->buffer = calloc(delay_length, sizeof(double));
  delay_line->write_index = 0;
}

void delay_line_destroy(delay_line_t* delay_line) {
  free(delay_line->buffer);
}

double delay_line_read(delay_line_t* delay_line, size_t delay_samples) {
  if (delay_samples >= delay_line->length) {
    return 0.0;
  }
  size_t read_index = (delay_line->write_index - delay_samples - 1) % delay_line->length;
  return delay_line->buffer[read_index];
}

void delay_line_write(delay_line_t* delay_line, double sample) {
  delay_line->buffer[delay_line->write_index] = sample;
  delay_line->write_index = (delay_line->write_index + 1) % delay_line->length;
}

double apply_comb_filter(double input_sample, double delay_gain, size_t delay_samples, delay_line_t* delay_line) {
  double delay_sample = delay_line_read(delay_line, delay_samples);
  double output_sample = input_sample + (delay_sample * delay_gain);
  delay_line_write(delay_line, output_sample);
  return output_sample;
}

int main() {
  double frequency = 880.0;
  size_t delay_samples = round(SAMPLE_RATE / frequency);
  delay_line_t delay_line;
  delay_line_init(&delay_line, delay_samples);
  double delay_gain = 0.8;
  double amplitude = 0.1;
  double duration = 3.0;
  size_t length = round(duration * SAMPLE_RATE);
  double* signal = calloc(length, sizeof(double));
  double angle_increment = 2.0 * PI * frequency / SAMPLE_RATE;
  double current_angle = 0.0;
  for (size_t i = 0; i < length; i++) {
    double sample = sin(current_angle) * amplitude;
    sample = apply_comb_filter(sample, delay_gain, delay_samples, &delay_line);
    current_angle += angle_increment;
    signal[i] = sample;
  }
  for (size_t i = 0; i < length; i++) {
    printf("%f\n", signal[i]);
  }
  delay_line_destroy(&delay_line);
  free(signal);
  return 0;
}
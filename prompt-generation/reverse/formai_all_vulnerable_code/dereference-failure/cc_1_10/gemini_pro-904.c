//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SR 44100

typedef struct {
  float *data;
  size_t length;
} buffer;

buffer *buffer_new(size_t length) {
  buffer *buf = malloc(sizeof(buffer));
  buf->data = malloc(length * sizeof(float));
  buf->length = length;
  return buf;
}

void buffer_free(buffer *buf) {
  free(buf->data);
  free(buf);
}

void buffer_write(buffer *buf, float *data, size_t length) {
  memcpy(buf->data, data, length * sizeof(float));
}

void buffer_read(buffer *buf, float *data, size_t length) {
  memcpy(data, buf->data, length * sizeof(float));
}

void oscillator(buffer *buf, float freq, float amp) {
  for (size_t i = 0; i < buf->length; i++) {
    buf->data[i] = amp * sinf(2 * PI * freq * i / SR);
  }
}

void reverb(buffer *buf, float decay) {
  for (size_t i = 0; i < buf->length; i++) {
    if (i < decay * SR) {
      buf->data[i] *= 1 - decay;
    } else {
      buf->data[i] = 0;
    }
  }
}

void compressor(buffer *buf, float threshold, float ratio) {
  for (size_t i = 0; i < buf->length; i++) {
    if (buf->data[i] > threshold) {
      buf->data[i] = threshold + (buf->data[i] - threshold) / ratio;
    }
  }
}

int main() {
  buffer *buf = buffer_new(SR * 5);
  oscillator(buf, 440, 0.5);
  reverb(buf, 0.5);
  compressor(buf, 0.5, 2);
  float out[SR];
  buffer_read(buf, out, SR);
  for (size_t i = 0; i < SR; i++) {
    printf("%f\n", out[i]);
  }
  buffer_free(buf);
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *samples;
  int num_samples;
} audio_buffer;

audio_buffer *create_audio_buffer(int num_samples) {
  audio_buffer *buffer = malloc(sizeof(audio_buffer));
  buffer->samples = malloc(num_samples * sizeof(float));
  buffer->num_samples = num_samples;
  return buffer;
}

void destroy_audio_buffer(audio_buffer *buffer) {
  free(buffer->samples);
  free(buffer);
}

int main(int argc, char **argv) {
  PaStream *stream;
  PaError err;
  audio_buffer *buffer;
  int i;

  err = Pa_Initialize();
  if (err != paNoError) goto error;

  err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, paFloat32, paNoFlag, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
  if (err != paNoError) goto error;

  buffer = create_audio_buffer(FRAMES_PER_BUFFER);

  for (;;) {
    err = Pa_ReadStream(stream, buffer->samples, FRAMES_PER_BUFFER);
    if (err != paNoError) goto error;

    for (i = 0; i < buffer->num_samples; i++) {
      buffer->samples[i] = sin(i / 100.0);
    }

    err = Pa_WriteStream(stream, buffer->samples, FRAMES_PER_BUFFER);
    if (err != paNoError) goto error;
  }

error:
  Pa_Terminate();
  destroy_audio_buffer(buffer);
  return err;
}
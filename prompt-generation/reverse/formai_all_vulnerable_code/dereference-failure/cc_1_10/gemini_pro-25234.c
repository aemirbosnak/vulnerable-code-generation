//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *buffer;
  int buffer_size;
  int buffer_index;
} AudioBuffer;

AudioBuffer *create_audio_buffer(int size) {
  AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
  buffer->buffer = malloc(sizeof(float) * size);
  buffer->buffer_size = size;
  buffer->buffer_index = 0;
  return buffer;
}

void destroy_audio_buffer(AudioBuffer *buffer) {
  free(buffer->buffer);
  free(buffer);
}

int audio_callback(const void *input_buffer, void *output_buffer,
                   unsigned long frames_per_buffer,
                   const PaStreamCallbackTimeInfo *time_info,
                   PaStreamCallbackFlags status_flags, void *user_data) {
  AudioBuffer *buffer = (AudioBuffer *)user_data;

  const float *in = (const float *)input_buffer;
  float *out = (float *)output_buffer;

  for (int i = 0; i < frames_per_buffer; i++) {
    out[i * NUM_CHANNELS] = in[i * NUM_CHANNELS] * 0.5;
    out[i * NUM_CHANNELS + 1] = in[i * NUM_CHANNELS + 1] * 0.5;

    buffer->buffer[buffer->buffer_index++] = in[i * NUM_CHANNELS];
    if (buffer->buffer_index >= buffer->buffer_size) {
      buffer->buffer_index = 0;
    }
  }

  return paContinue;
}

int main(int argc, char **argv) {
  PaStream *stream;
  PaError error;

  error = Pa_Initialize();
  if (error != paNoError) {
    fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  AudioBuffer *buffer = create_audio_buffer(FRAMES_PER_BUFFER * NUM_CHANNELS);

  error = Pa_OpenDefaultStream(&stream, 2, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, audio_callback, buffer);
  if (error != paNoError) {
    fprintf(stderr, "Error opening default stream: %s\n", Pa_GetErrorText(error));
    Pa_Terminate();
    return 1;
  }

  error = Pa_StartStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(error));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return 1;
  }

  printf("Press Enter to quit.\n");
  getchar();

  error = Pa_StopStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(error));
  }

  error = Pa_CloseStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(error));
  }

  Pa_Terminate();

  destroy_audio_buffer(buffer);

  return 0;
}
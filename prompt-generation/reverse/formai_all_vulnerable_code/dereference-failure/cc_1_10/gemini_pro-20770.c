//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE  44100
#define FRAMES_PER_BUFFER  512

typedef struct {
  float sample_rate;
  int num_channels;
} AudioFormat;

typedef struct {
  short *samples;
  int num_samples;
} AudioBuffer;

AudioBuffer *audio_buffer_create(int num_samples) {
  AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
  buffer->samples = malloc(sizeof(short) * num_samples);
  buffer->num_samples = num_samples;
  return buffer;
}

void audio_buffer_destroy(AudioBuffer *buffer) {
  free(buffer->samples);
  free(buffer);
}

int audio_callback(const void *input_buffer, void *output_buffer,
                   unsigned long frames_per_buffer,
                   const PaStreamCallbackTimeInfo* time_info,
                   PaStreamCallbackFlags status_flags,
                   void *user_data) {
  AudioBuffer *buffer = (AudioBuffer *)user_data;

  const float *input = (const float *)input_buffer;
  float *output = (float *)output_buffer;

  for (int i = 0; i < frames_per_buffer; i++) {
    float sample = input[i];
    output[i] = sample;
  }

  return paContinue;
}

int main() {
  AudioFormat format = {
    .sample_rate = SAMPLE_RATE,
    .num_channels = 2,
  };

  AudioBuffer *buffer = audio_buffer_create(FRAMES_PER_BUFFER);

  PaStream *stream;
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError) {
    printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_OpenStream(&stream, NULL, &format, FRAMES_PER_BUFFER, FRAMES_PER_BUFFER, paClipOff,
                    audio_callback, buffer);
  if (err != paNoError) {
    printf("Error opening stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_StartStream(stream);
  if (err != paNoError) {
    printf("Error starting stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  while (1) {
    
  }

  err = Pa_StopStream(stream);
  if (err != paNoError) {
    printf("Error stopping stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    printf("Error closing stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_Terminate();
  if (err != paNoError) {
    printf("Error terminating PortAudio: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  audio_buffer_destroy(buffer);

  return 0;
}
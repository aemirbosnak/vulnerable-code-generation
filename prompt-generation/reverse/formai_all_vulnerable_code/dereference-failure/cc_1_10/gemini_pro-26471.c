//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <portaudio.h>

#define NUM_BUFFERS 10
#define BUFFER_SIZE 1024
#define SAMPLE_RATE 44100

typedef struct {
  float *buffers[NUM_BUFFERS];
  int num_filled;
  int current_buffer;
} AudioBuffer;

AudioBuffer *create_audio_buffer() {
  AudioBuffer *buffer = malloc(sizeof(AudioBuffer));
  for (int i = 0; i < NUM_BUFFERS; i++) {
    buffer->buffers[i] = malloc(BUFFER_SIZE * sizeof(float));
  }
  buffer->num_filled = 0;
  buffer->current_buffer = 0;
  return buffer;
}

void destroy_audio_buffer(AudioBuffer *buffer) {
  for (int i = 0; i < NUM_BUFFERS; i++) {
    free(buffer->buffers[i]);
  }
  free(buffer);
}

int audio_callback(const void *input_buffer, void *output_buffer,
                   unsigned long frames_per_buffer,
                   const PaStreamCallbackTimeInfo *time_info,
                   PaStreamCallbackFlags status_flags,
                   void *user_data) {
  AudioBuffer *buffer = (AudioBuffer *)user_data;

  // Copy the input buffer into the next buffer in the ring buffer.
  memcpy(buffer->buffers[buffer->current_buffer], input_buffer, frames_per_buffer * sizeof(float));
  buffer->num_filled++;
  buffer->current_buffer = (buffer->current_buffer + 1) % NUM_BUFFERS;

  // Copy the next buffer in the ring buffer into the output buffer.
  memcpy(output_buffer, buffer->buffers[buffer->current_buffer], frames_per_buffer * sizeof(float));

  return paContinue;
}

int main() {
  // Initialize PortAudio.
  PaStream *stream;
  PaError error = Pa_Initialize();
  if (error != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Open the default input device.
  error = Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE, BUFFER_SIZE, audio_callback, NULL);
  if (error != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Create the audio buffer.
  AudioBuffer *buffer = create_audio_buffer();

  // Start the stream.
  error = Pa_StartStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Wait for the user to press Enter.
  printf("Press Enter to quit.\n");
  getchar();

  // Stop the stream.
  error = Pa_StopStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Close the stream.
  error = Pa_CloseStream(stream);
  if (error != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Destroy the audio buffer.
  destroy_audio_buffer(buffer);

  // Terminate PortAudio.
  Pa_Terminate();

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

// Ring buffer for storing audio data
typedef struct {
  float *data;
  int head;
  int tail;
  int size;
} RingBuffer;

// Initialize ring buffer
void initRingBuffer(RingBuffer *buffer, int size) {
  buffer->data = (float *)malloc(size * sizeof(float));
  buffer->head = 0;
  buffer->tail = 0;
  buffer->size = size;
}

// Write data to ring buffer
void writeRingBuffer(RingBuffer *buffer, float *data, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    buffer->data[buffer->head] = data[i];
    buffer->head = (buffer->head + 1) % buffer->size;
  }
}

// Read data from ring buffer
void readRingBuffer(RingBuffer *buffer, float *data, int num_samples) {
  for (int i = 0; i < num_samples; i++) {
    data[i] = buffer->data[buffer->tail];
    buffer->tail = (buffer->tail + 1) % buffer->size;
  }
}

// Callback function for PortAudio
int callback(const void *input_buffer, void *output_buffer,
             unsigned long frames_per_buffer,
             const PaStreamCallbackTimeInfo *time_info,
             PaStreamCallbackFlags status_flags,
             void *user_data) {
  // Cast user data to ring buffer
  RingBuffer *buffer = (RingBuffer *)user_data;

  // Get input and output buffers
  float *in = (float *)input_buffer;
  float *out = (float *)output_buffer;

  // Process audio data
  for (int i = 0; i < frames_per_buffer; i++) {
    // Read from ring buffer
    float sample;
    readRingBuffer(buffer, &sample, 1);

    // Apply effect (e.g., reverb)
    sample *= 0.5;

    // Write to output buffer
    out[i * NUM_CHANNELS] = sample;
    out[i * NUM_CHANNELS + 1] = sample;
  }

  return paContinue;
}

int main() {
  // Initialize PortAudio
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Initialize ring buffer
  RingBuffer buffer;
  initRingBuffer(&buffer, FRAMES_PER_BUFFER * 10);

  // Open audio stream
  PaStream *stream;
  err = Pa_OpenStream(&stream, paNoDevice, NUM_CHANNELS, paFloat32, SAMPLE_RATE,
                     FRAMES_PER_BUFFER, callback, &buffer);
  if (err != paNoError) {
    printf("Error opening audio stream: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
  }

  // Start audio stream
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    printf("Error starting audio stream: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return -1;
  }

  // Generate audio data and write to ring buffer
  float data[FRAMES_PER_BUFFER];
  for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
    data[i] = (float)sin(2 * M_PI * 440 * i / SAMPLE_RATE);
  }

  while (1) {
    // Write data to ring buffer
    writeRingBuffer(&buffer, data, FRAMES_PER_BUFFER);
  }

  // Stop audio stream
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    printf("Error stopping audio stream: %s\n", Pa_GetErrorText(err));
  }

  // Close audio stream
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    printf("Error closing audio stream: %s\n", Pa_GetErrorText(err));
  }

  // Terminate PortAudio
  Pa_Terminate();

  return 0;
}
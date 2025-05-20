//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *buffer;
  int bufferSize;
  int bufferIndex;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} RingBuffer;

// Create a new ring buffer
RingBuffer *newRingBuffer(int size) {
  RingBuffer *buffer = malloc(sizeof(RingBuffer));
  buffer->buffer = malloc(sizeof(float) * size);
  buffer->bufferSize = size;
  buffer->bufferIndex = 0;
  pthread_mutex_init(&buffer->mutex, NULL);
  pthread_cond_init(&buffer->cond, NULL);
  return buffer;
}

// Destroy a ring buffer
void destroyRingBuffer(RingBuffer *buffer) {
  pthread_mutex_destroy(&buffer->mutex);
  pthread_cond_destroy(&buffer->cond);
  free(buffer->buffer);
  free(buffer);
}

// Write to a ring buffer
void writeRingBuffer(RingBuffer *buffer, float *data, int size) {
  pthread_mutex_lock(&buffer->mutex);
  while (buffer->bufferIndex + size > buffer->bufferSize) {
    pthread_cond_wait(&buffer->cond, &buffer->mutex);
  }
  for (int i = 0; i < size; i++) {
    buffer->buffer[buffer->bufferIndex++] = data[i];
  }
  pthread_mutex_unlock(&buffer->mutex);
  pthread_cond_signal(&buffer->cond);
}

// Read from a ring buffer
void readRingBuffer(RingBuffer *buffer, float *data, int size) {
  pthread_mutex_lock(&buffer->mutex);
  while (buffer->bufferIndex < size) {
    pthread_cond_wait(&buffer->cond, &buffer->mutex);
  }
  for (int i = 0; i < size; i++) {
    data[i] = buffer->buffer[buffer->bufferIndex++];
  }
  pthread_mutex_unlock(&buffer->mutex);
  pthread_cond_signal(&buffer->cond);
}

// Audio callback function
static int audioCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                           void *userData) {
  RingBuffer *buffer = (RingBuffer *)userData;

  float *in = (float *)inputBuffer;
  float *out = (float *)outputBuffer;

  // Copy the input data to the ring buffer
  writeRingBuffer(buffer, in, framesPerBuffer * NUM_CHANNELS);

  // Read the output data from the ring buffer
  readRingBuffer(buffer, out, framesPerBuffer * NUM_CHANNELS);

  // Process the audio data
  for (int i = 0; i < framesPerBuffer * NUM_CHANNELS; i++) {
    out[i] = in[i] * 0.5;
  }

  return paContinue;
}

int main() {
  // Create a ring buffer
  RingBuffer *buffer = newRingBuffer(FRAMES_PER_BUFFER * NUM_CHANNELS);

  // Initialize PortAudio
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Open an audio stream
  PaStream *stream;
  err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, audioCallback, buffer);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Start the audio stream
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Wait for the user to press enter
  getchar();

  // Stop the audio stream
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Close the audio stream
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Terminate PortAudio
  err = Pa_Terminate();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Destroy the ring buffer
  destroyRingBuffer(buffer);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <portaudio.h>

#define NUM_THREADS 4

typedef struct {
  float *inputBuffer;
  int inputBufferSize;
  float *outputBuffer;
  int outputBufferSize;
} audioData;

void *processAudio(void *arg) {
  audioData *data = (audioData *)arg;

  // Process the audio data
  for (int i = 0; i < data->inputBufferSize; i++) {
    data->outputBuffer[i] = data->inputBuffer[i] * 2;
  }

  return NULL;
}

int main() {
  // Initialize PortAudio
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Open the default audio input device
  PaStream *inputStream = NULL;
  err = Pa_OpenDefaultStream(&inputStream, 1, 0, paFloat32, 44100, 1024, NULL, NULL);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }

  // Open the default audio output device
  PaStream *outputStream = NULL;
  err = Pa_OpenDefaultStream(&outputStream, 0, 2, paFloat32, 44100, 1024, NULL, NULL);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }

  // Start the audio streams
  err = Pa_StartStream(inputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }
  err = Pa_StartStream(outputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }

  // Create the audio data struct
  audioData data;
  data.inputBuffer = malloc(sizeof(float) * 1024);
  data.inputBufferSize = 1024;
  data.outputBuffer = malloc(sizeof(float) * 1024);
  data.outputBufferSize = 1024;

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, processAudio, &data);
  }

  // Wait for the threads to finish
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Stop the audio streams
  err = Pa_StopStream(inputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }
  err = Pa_StopStream(outputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }

  // Close the audio streams
  err = Pa_CloseStream(inputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }
  err = Pa_CloseStream(outputStream);
  if (err != paNoError) {
    printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    goto cleanup;
  }

  // Terminate PortAudio
  Pa_Terminate();

  // Cleanup
cleanup:
  if (inputStream) {
    Pa_CloseStream(inputStream);
  }
  if (outputStream) {
    Pa_CloseStream(outputStream);
  }
  if (data.inputBuffer) {
    free(data.inputBuffer);
  }
  if (data.outputBuffer) {
    free(data.outputBuffer);
  }

  return EXIT_SUCCESS;
}
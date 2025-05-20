//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 1
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *buffer;
  int frames;
} AudioBuffer;

static int callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                     const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
                     void *userData) {
  AudioBuffer *buffer = (AudioBuffer *)userData;

  if (buffer->frames < framesPerBuffer) {
    memset(outputBuffer, 0, framesPerBuffer * sizeof(float));
    return paContinue;
  }

  memcpy(outputBuffer, buffer->buffer, framesPerBuffer * sizeof(float));
  buffer->buffer += framesPerBuffer;
  buffer->frames -= framesPerBuffer;

  return paContinue;
}

int main(int argc, char **argv) {
  AudioBuffer buffer;
  PaError err;
  PaStream *stream;
  PaStreamParameters outputParameters;

  // Check command line arguments
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read input file
  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  fseek(file, 0, SEEK_END);
  size_t fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  buffer.frames = fileSize / sizeof(float);
  buffer.buffer = (float *)malloc(fileSize);
  if (buffer.buffer == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  fread(buffer.buffer, sizeof(float), buffer.frames, file);
  fclose(file);

  // Initialize PortAudio
  err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "Pa_Initialize: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Define output stream parameters
  outputParameters.device = Pa_GetDefaultOutputDevice();
  outputParameters.channelCount = NUM_CHANNELS;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowInputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;

  // Open output stream
  err = Pa_OpenStream(&stream, NULL, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, 0, callback,
                       &buffer);
  if (err != paNoError) {
    fprintf(stderr, "Pa_OpenStream: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Start output stream
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_StartStream: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Wait for stream to finish
  while (buffer.frames > 0) {
    Pa_Sleep(100);
  }

  // Stop output stream
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_StopStream: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Close output stream
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_CloseStream: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  // Terminate PortAudio
  err = Pa_Terminate();
  if (err != paNoError) {
    fprintf(stderr, "Pa_Terminate: %s\n", Pa_GetErrorText(err));
    return EXIT_FAILURE;
  }

  free(buffer.buffer);

  return EXIT_SUCCESS;
}
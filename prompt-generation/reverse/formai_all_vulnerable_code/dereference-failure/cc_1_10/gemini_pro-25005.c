//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *buffer;
  int buffer_size;
  int buffer_index;
} AudioBuffer;

int callback(const void *inputBuffer, void *outputBuffer,
              unsigned long framesPerBuffer,
              const PaStreamCallbackTimeInfo *timeInfo,
              PaStreamCallbackFlags statusFlags,
              void *userData) {
  AudioBuffer *audioBuffer = (AudioBuffer *)userData;

  if (audioBuffer->buffer_index + framesPerBuffer > audioBuffer->buffer_size) {
    // We've reached the end of the buffer, so we need to wrap around
    int remainingFrames = audioBuffer->buffer_size - audioBuffer->buffer_index;
    memcpy(outputBuffer, &audioBuffer->buffer[audioBuffer->buffer_index],
           remainingFrames * NUM_CHANNELS * sizeof(float));
    memcpy(outputBuffer + remainingFrames * NUM_CHANNELS * sizeof(float),
           audioBuffer->buffer,
           (framesPerBuffer - remainingFrames) * NUM_CHANNELS * sizeof(float));
    audioBuffer->buffer_index = framesPerBuffer - remainingFrames;
  } else {
    // We're still within the bounds of the buffer, so we can just copy the data
    memcpy(outputBuffer, &audioBuffer->buffer[audioBuffer->buffer_index],
           framesPerBuffer * NUM_CHANNELS * sizeof(float));
    audioBuffer->buffer_index += framesPerBuffer;
  }

  return paContinue;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *inputFile = fopen(argv[1], "rb");
  if (inputFile == NULL) {
    printf("Error opening input file\n");
    return EXIT_FAILURE;
  }

  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  float *audioBuffer = malloc(fileSize);
  if (audioBuffer == NULL) {
    printf("Error allocating memory for audio buffer\n");
    return EXIT_FAILURE;
  }

  fread(audioBuffer, 1, fileSize, inputFile);
  fclose(inputFile);

  AudioBuffer audioBufferStruct = {
    .buffer = audioBuffer,
    .buffer_size = fileSize / (NUM_CHANNELS * sizeof(float)),
    .buffer_index = 0
  };

  PaError err;
  PaStream *stream;
  PaStreamParameters outputParameters;

  err = Pa_Initialize();
  if (err != paNoError) {
    printf("Error initializing PortAudio\n");
    return EXIT_FAILURE;
  }

  outputParameters.device = Pa_GetDefaultOutputDevice();
  if (outputParameters.device == paNoDevice) {
    printf("Error getting default output device\n");
    return EXIT_FAILURE;
  }

  outputParameters.channelCount = NUM_CHANNELS;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultHighOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;

  err = Pa_OpenStream(&stream, NULL, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER,
                         paClipOff, callback, &audioBufferStruct);
  if (err != paNoError) {
    printf("Error opening stream\n");
    return EXIT_FAILURE;
  }

  err = Pa_StartStream(stream);
  if (err != paNoError) {
    printf("Error starting stream\n");
    return EXIT_FAILURE;
  }

  while (Pa_IsStreamActive(stream)) {
    // Do stuff
  }

  err = Pa_StopStream(stream);
  if (err != paNoError) {
    printf("Error stopping stream\n");
    return EXIT_FAILURE;
  }

  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    printf("Error closing stream\n");
    return EXIT_FAILURE;
  }

  Pa_Terminate();

  free(audioBuffer);

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

// A sine wave generator.
void generateSineWave(float *buffer, int numFrames) {
  for (int i = 0; i < numFrames; i++) {
    buffer[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
  }
}

// A callback function that is called by PortAudio to fill the output buffer.
int callback(const void *inputBuffer, void *outputBuffer,
             unsigned long framesPerBuffer,
             const PaStreamCallbackTimeInfo* timeInfo,
             PaStreamCallbackFlags statusFlags,
             void *userData) {
  float *out = (float *)outputBuffer;
  generateSineWave(out, framesPerBuffer);
  return paContinue;
}

int main() {
  PaStreamParameters outputParameters;
  PaError err;

  // Initialize PortAudio.
  err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Set up the output stream parameters.
  outputParameters.device = Pa_GetDefaultOutputDevice();
  if (outputParameters.device == paNoDevice) {
    fprintf(stderr, "Error: No default output device.\n");
    return 1;
  }
  outputParameters.channelCount = 2;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowInputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;

  // Open the stream.
  PaStream *stream;
  err = Pa_OpenStream(&stream,
                      NULL,
                      &outputParameters,
                      SAMPLE_RATE,
                      FRAMES_PER_BUFFER,
                      paClipOff,
                      callback,
                      NULL);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Start the stream.
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Wait for the user to press Enter.
  printf("Press Enter to quit.\n");
  getchar();

  // Stop the stream.
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Close the stream.
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  // Terminate PortAudio.
  err = Pa_Terminate();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  return 0;
}
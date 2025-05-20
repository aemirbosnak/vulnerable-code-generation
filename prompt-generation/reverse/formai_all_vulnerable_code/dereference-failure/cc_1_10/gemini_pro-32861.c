//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

// Define the sample rate and number of channels
#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2

// Audio buffer size
#define BUFF_SIZE 1024

// Number of seconds to record
#define SECONDS_TO_RECORD 5

// Audio data array
float audio_data[BUFF_SIZE * SECONDS_TO_RECORD * NUM_CHANNELS];

// Audio callback function
int audio_callback(const void *inputBuffer, void *outputBuffer,
                   unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo *timeInfo,
                   PaStreamCallbackFlags statusFlags,
                   void *userData) {
  // Cast input buffer to float pointer
  const float *in = (const float *)inputBuffer;

  // Cast output buffer to float pointer
  float *out = (float *)outputBuffer;

  // Copy input data to output buffer
  for (int i = 0; i < framesPerBuffer * NUM_CHANNELS; i++) {
    out[i] = in[i];
  }

  // Store audio data for later analysis
  for (int i = 0; i < framesPerBuffer * NUM_CHANNELS; i++) {
    audio_data[i] = in[i];
  }

  // Return 0 to indicate successful callback
  return 0;
}

int main() {
  // Initialize PortAudio
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Open audio stream
  PaStreamParameters inputParameters;
  inputParameters.device = Pa_GetDefaultInputDevice();
  inputParameters.channelCount = NUM_CHANNELS;
  inputParameters.sampleFormat = paFloat32;
  inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
  inputParameters.hostApiSpecificStreamInfo = NULL;

  PaStream *stream;
  err = Pa_OpenStream(&stream, &inputParameters, NULL, SAMPLE_RATE, BUFF_SIZE, paClipOff, audio_callback, NULL);
  if (err != paNoError) {
    printf("Error opening audio stream: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
  }

  // Start recording
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    printf("Error starting audio stream: %s\n", Pa_GetErrorText(err));
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    return -1;
  }

  // Record for N seconds
  Pa_Sleep(SECONDS_TO_RECORD * 1000);

  // Stop recording
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    printf("Error stopping audio stream: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return -1;
  }

  // Close audio stream
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    printf("Error closing audio stream: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
  }

  // Terminate PortAudio
  Pa_Terminate();

  // Analyze audio data and identify sounds of nature (omitted for brevity)

  printf("The rainforest is alive with sound!\n");

  return 0;
}
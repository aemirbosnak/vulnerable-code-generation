//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLE_RATE  (44100)
#define FRAMES_PER_BUFFER  (1024)

typedef struct {
  float frequency;
  float amplitude;
  float phase;
} SineWave;

static int callback( const void *inputBuffer, void *outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData )
{
  SineWave *sineWaves = (SineWave *)userData;

  float *out = (float*)outputBuffer;

  for(unsigned int i = 0; i < framesPerBuffer; i++) {
    float sample = 0.0f;
    for(unsigned int j = 0; j < 3; j++) {
      SineWave *sineWave = &sineWaves[j];
      sample += sineWave->amplitude * sinf(2 * M_PI * sineWave->frequency * i / SAMPLE_RATE + sineWave->phase);
    }
    *out++ = sample;
  }

  return 0;
}

int main(void) {
  PaStream *stream;
  PaError err;

  printf("Initializing PortAudio...\n");

  err = Pa_Initialize();
  if(err != paNoError) {
    printf("PortAudio initialization failed: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  printf("Setting up stream parameters...\n");

  PaStreamParameters outputParams;
  outputParams.device = Pa_GetDefaultOutputDevice();  
  if (outputParams.device == paNoDevice) {
    printf("No default output device found\n");
  }
  outputParams.channelCount = 1; 
  outputParams.sampleFormat = paFloat32;  
  outputParams.suggestedLatency = Pa_GetDeviceInfo(outputParams.device)->defaultLowOutputLatency;
  outputParams.hostApiSpecificStreamInfo = NULL;

  printf("Opening stream...\n");

  err = Pa_OpenStream(&stream,
      NULL,  
      &outputParams,
      SAMPLE_RATE,
      FRAMES_PER_BUFFER,
      paClipOff,  
      callback,
      NULL);
  if(err != paNoError) {
    printf("Error opening stream: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return 1;
  }

  SineWave sineWaves[] = {
    {440.0f, 0.5f, 0.0f},
    {880.0f, 0.3f, 0.0f},
    {1320.0f, 0.2f, 0.0f}
  };

  printf("Starting stream...\n");

  err = Pa_StartStream(stream);
  if(err != paNoError) {
    printf("Error starting stream: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return 1;
  }

  printf("Press any key to stop the stream...\n");
  getchar();

  printf("Stopping stream...\n");

  err = Pa_StopStream(stream);
  if(err != paNoError) {
    printf("Error stopping stream: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return 1;
  }

  printf("Closing stream...\n");

  err = Pa_CloseStream(stream);
  if(err != paNoError) {
    printf("Error closing stream: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return 1;
  }

  printf("Terminating PortAudio...\n");

  Pa_Terminate();
  return 0;
}
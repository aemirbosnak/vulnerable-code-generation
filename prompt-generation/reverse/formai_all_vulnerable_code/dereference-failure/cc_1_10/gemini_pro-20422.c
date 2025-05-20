//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>
#include <math.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (512)

typedef struct {
  float *sine_table;
  int sine_table_size;
  int sine_table_index;
  float frequency;
} SineOsc;

SineOsc *sine_osc_new(float frequency) {
  SineOsc *osc = malloc(sizeof(SineOsc));
  osc->sine_table_size = SAMPLE_RATE / frequency;
  osc->sine_table = malloc(sizeof(float) * osc->sine_table_size);
  for (int i = 0; i < osc->sine_table_size; i++) {
    osc->sine_table[i] = sin(2 * M_PI * i / osc->sine_table_size);
  }
  osc->sine_table_index = 0;
  osc->frequency = frequency;
  return osc;
}

void sine_osc_free(SineOsc *osc) {
  free(osc->sine_table);
  free(osc);
}

float sine_osc_tick(SineOsc *osc) {
  float sample = osc->sine_table[osc->sine_table_index];
  osc->sine_table_index = (osc->sine_table_index + 1) % osc->sine_table_size;
  return sample;
}

int callback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
             const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags,
             void *userData) {
  SineOsc *osc = (SineOsc *)userData;
  float *output = (float *)outputBuffer;
  for (int i = 0; i < framesPerBuffer; i++) {
    output[i] = sine_osc_tick(osc);
  }
  return 0;
}

int main() {
  SineOsc *osc = sine_osc_new(220);

  PaStream *stream;
  PaError err;
  err = Pa_Initialize();
  if (err != paNoError) goto error;

  err = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, callback, osc);
  if (err != paNoError) goto error;

  err = Pa_StartStream(stream);
  if (err != paNoError) goto error;

  printf("Press Enter to quit.\n");
  getchar();

  err = Pa_StopStream(stream);
  if (err != paNoError) goto error;

  err = Pa_CloseStream(stream);
  if (err != paNoError) goto error;

  Pa_Terminate();
  sine_osc_free(osc);
  return 0;

error:
  Pa_Terminate();
  sine_osc_free(osc);
  fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
  return -1;
}
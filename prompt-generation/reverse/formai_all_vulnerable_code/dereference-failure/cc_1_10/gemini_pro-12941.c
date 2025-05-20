//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
// Ada Lovelace's Anthem for the Audio Realm

// Prelude: A tapestry of sound, woven from numbers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

// I. Overture: Defining the Symphony
#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2
#define NUM_SECONDS 5

// II. The Instruments: A Chorus of Sine Waves
typedef struct {
  double frequency;
  double amplitude;
  double phase;
} Note;

// III. The Score: A Sequence of Notes
Note notes[] = {
  { 261.63, 0.5, 0 }, // C4
  { 293.66, 0.5, 0 }, // D4
  { 329.63, 0.5, 0 }, // E4
  { 349.23, 0.5, 0 }, // F4
  { 392.00, 0.5, 0 }, // G4
  { 440.00, 0.5, 0 }, // A4
  { 493.88, 0.5, 0 }, // B4
  { 523.25, 0.5, 0 }, // C5
};

// IV. The Conductor: Callback for Generating Audio Samples
static int callback(const void *inputBuffer, void *outputBuffer,
                    unsigned long framesPerBuffer,
                    const PaStreamCallbackTimeInfo* timeInfo,
                    PaStreamCallbackFlags statusFlags,
                    void *userData) {
  // Constructing the audio samples
  float *output = (float *) outputBuffer;
  double time = 0;
  for (unsigned int i = 0; i < framesPerBuffer; i++) {
    double sample = 0;
    for (unsigned int j = 0; j < sizeof(notes) / sizeof(notes[0]); j++) {
      sample += notes[j].amplitude * sin(2 * M_PI * notes[j].frequency * time + notes[j].phase);
    }
    output[2 * i] = output[2 * i + 1] = sample;
    time += 1.0 / SAMPLE_RATE;
  }
  // End of the audio samples
  return paContinue;
}

// V. The Concert Hall: Initializing and Playing the Audio
int main() {
  // Initializing PortAudio
  PaStream *stream;
  PaError err;
  err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Configuring the stream parameters
  PaStreamParameters outputParameters;
  outputParameters.device = Pa_GetDefaultOutputDevice();
  outputParameters.channelCount = NUM_CHANNELS;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;

  // Opening the audio stream
  err = Pa_OpenStream(&stream,
                       NULL, // No input
                       &outputParameters,
                       SAMPLE_RATE,
                       NUM_SECONDS * SAMPLE_RATE, // Frames per buffer
                       paClipOff,
                       callback,
                       NULL); // User data
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
  }

  // Starting the audio stream
  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return -1;
  }

  // Waiting for the audio stream to complete
  Pa_Sleep(NUM_SECONDS * 1000);

  // Stopping and closing the audio stream
  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return -1;
  }
  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    Pa_Terminate();
    return -1;
  }

  // Deinitializing PortAudio
  err = Pa_Terminate();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  return 0;
}

// VI. Epilogue: A Symphony of Numbers, Forever Resonating
//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: immersive
// Embark on an audio adventure, where frequencies dance and waveforms paint sonic landscapes.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

// Define the canvas of our sonic masterpiece.
typedef struct {
  double frequency;  // The pitch and essence of the sound.
  double amplitude;  // The volume and intensity of the sound.
} Waveform;

// Our virtual orchestra's conductor, translating ideas into sound.
PaStream *stream;
PaError paError;

// Generate a seamless stream of sine waves, the foundation of our audio odyssey.
void generateSineWave(Waveform waveform, double sampleRate) {
  printf("A sine wave emerges, its frequency %g, its volume %g.\n", waveform.frequency, waveform.amplitude);
  double phase = 0.0;  // The ebb and flow of the wave.
  while (1) {
    double sample = waveform.amplitude * sin(2 * M_PI * waveform.frequency * phase);
    printf("%g\n", sample);
    phase += 1.0 / sampleRate;
  }
}

// Your maestro takes the stage, ready to orchestrate a symphony of waveforms.
void playWaveform(Waveform waveform) {
  paError = Pa_Initialize();
  if (paError != paNoError) {
    fprintf(stderr, "Failed to initialize PortAudio: %s\n", Pa_GetErrorText(paError));
    return;
  }
  PaStreamParameters outputParameters;
  outputParameters.device = Pa_GetDefaultOutputDevice();
  outputParameters.channelCount = 1;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultHighOutputLatency;
  outputParameters.hostApiSpecificStreamInfo = NULL;
  paError = Pa_OpenStream(&stream, NULL, &outputParameters, 44100, 1024, paClipOff, generateSineWave, &waveform);
  if (paError != paNoError) {
    fprintf(stderr, "Failed to open PortAudio stream: %s\n", Pa_GetErrorText(paError));
    return;
  }
  paError = Pa_StartStream(stream);
  if (paError != paNoError) {
    fprintf(stderr, "Failed to start PortAudio stream: %s\n", Pa_GetErrorText(paError));
    return;
  }
  printf("The wave of sound is unleashed!\n");
  Pa_Sleep(10000);
  paError = Pa_StopStream(stream);
  if (paError != paNoError) {
    fprintf(stderr, "Failed to stop PortAudio stream: %s\n", Pa_GetErrorText(paError));
    return;
  }
  paError = Pa_CloseStream(stream);
  if (paError != paNoError) {
    fprintf(stderr, "Failed to close PortAudio stream: %s\n", Pa_GetErrorText(paError));
    return;
  }
  Pa_Terminate();
  printf("The symphony fades into silence.\n");
}

// Our musical palette, a kaleidoscope of waveforms.
Waveform waveforms[] = {
  {440.0, 0.5},  // A4, a familiar note.
  {261.6, 0.2},  // C4, a lower voice.
  {880.0, 0.8},  // A5, a higher pitch.
};

// Invite the audience to our sonic extravaganza.
int main() {
  printf("Welcome to the sonic sanctuary!\n");
  int choice;
  do {
    printf("Choose your sonic masterpiece:\n");
    for (int i = 0; i < sizeof(waveforms) / sizeof(Waveform); i++) {
      printf("%d. %g Hz, %g amplitude\n", i + 1, waveforms[i].frequency, waveforms[i].amplitude);
    }
    printf("0. Exit\n");
    scanf("%d", &choice);
    if (choice > 0 && choice <= sizeof(waveforms) / sizeof(Waveform)) {
      playWaveform(waveforms[choice - 1]);
    }
  } while (choice != 0);
  printf("Thank you for joining us!\n");
  return 0;
}
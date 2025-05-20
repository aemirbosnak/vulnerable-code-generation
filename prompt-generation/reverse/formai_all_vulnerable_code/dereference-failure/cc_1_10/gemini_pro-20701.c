//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE (44100)
#define NUM_CHANNELS (2)
#define BUFFER_SIZE (512)

typedef struct {
  float *buffer;
  int buffer_length;
  int buffer_index;
  PaStream *stream;
} AudioContext;

void audio_callback(void *userdata, float *output, int num_frames) {
  AudioContext *context = (AudioContext *)userdata;

  for (int i = 0; i < num_frames; i++) {
    output[i * NUM_CHANNELS] = context->buffer[context->buffer_index];
    output[i * NUM_CHANNELS + 1] = context->buffer[context->buffer_index + 1];

    context->buffer_index += 2;
    if (context->buffer_index >= context->buffer_length) {
      context->buffer_index = 0;
    }
  }
}

int main(int argc, char **argv) {
  AudioContext context;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    return -1;
  }

  // Read the audio file
  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("fopen");
    return -1;
  }

  fseek(file, 0, SEEK_END);
  int file_length = ftell(file);
  fseek(file, 0, SEEK_SET);

  context.buffer = malloc(file_length);
  if (context.buffer == NULL) {
    perror("malloc");
    return -1;
  }

  fread(context.buffer, 1, file_length, file);
  fclose(file);

  context.buffer_length = file_length / 2;
  context.buffer_index = 0;

  // Initialize PortAudio
  PaError err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "Pa_Initialize: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Open the audio output stream
  PaStreamParameters output_parameters;
  output_parameters.device = Pa_GetDefaultOutputDevice();
  output_parameters.channelCount = NUM_CHANNELS;
  output_parameters.sampleFormat = paFloat32;
  output_parameters.suggestedLatency = Pa_GetDeviceInfo(output_parameters.device)->defaultHighOutputLatency;
  output_parameters.hostApiSpecificStreamInfo = NULL;

  err = Pa_OpenStream(&(context.stream), NULL, &output_parameters, SAMPLE_RATE, BUFFER_SIZE, paClipOff, &audio_callback, &context);
  if (err != paNoError) {
    fprintf(stderr, "Pa_OpenStream: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Start the audio playback
  err = Pa_StartStream(context.stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_StartStream: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Wait for the audio playback to finish
  while (Pa_IsStreamActive(context.stream)) {
    Pa_Sleep(100);
  }

  // Stop the audio playback
  err = Pa_StopStream(context.stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_StopStream: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Close the audio output stream
  err = Pa_CloseStream(context.stream);
  if (err != paNoError) {
    fprintf(stderr, "Pa_CloseStream: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Terminate PortAudio
  err = Pa_Terminate();
  if (err != paNoError) {
    fprintf(stderr, "Pa_Terminate: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  free(context.buffer);
  return 0;
}
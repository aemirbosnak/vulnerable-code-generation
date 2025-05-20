//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>

typedef struct {
  float* buffer;
  int buffer_size;
  int buffer_index;
  int num_channels;
  int sample_rate;
} AudioBuffer;

AudioBuffer* init_audio_buffer(int num_channels, int sample_rate, int buffer_size) {
  AudioBuffer* buffer = malloc(sizeof(AudioBuffer));
  buffer->buffer = malloc(sizeof(float) * num_channels * buffer_size);
  buffer->buffer_size = buffer_size;
  buffer->buffer_index = 0;
  buffer->num_channels = num_channels;
  buffer->sample_rate = sample_rate;
  return buffer;
}

void free_audio_buffer(AudioBuffer* buffer) {
  free(buffer->buffer);
  free(buffer);
}

int audio_callback(const void* input_buffer, void* output_buffer, unsigned long frames_per_buffer, const PaStreamCallbackTimeInfo* time_info, PaStreamCallbackFlags status_flags, void* user_data) {
  AudioBuffer* buffer = (AudioBuffer*)user_data;

  float* input_samples = (float*)input_buffer;
  float* output_samples = (float*)output_buffer;

  for (int i = 0; i < frames_per_buffer; i++) {
    for (int j = 0; j < buffer->num_channels; j++) {
      output_samples[i * buffer->num_channels + j] = input_samples[i * buffer->num_channels + j] * 0.5;
    }
  }

  return 0;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  const char* filename = argv[1];

  FILE* file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Could not open file: %s\n", filename);
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  int num_channels = 2;
  int sample_rate = 44100;
  int buffer_size = 1024;

  AudioBuffer* buffer = init_audio_buffer(num_channels, sample_rate, buffer_size);
  float* data = malloc(sizeof(float) * file_size);
  fread(data, sizeof(float), file_size, file);
  fclose(file);

  memcpy(buffer->buffer, data, file_size);
  free(data);

  PaStream* stream;
  PaError error = Pa_Initialize();
  if (error != paNoError) {
    printf("Could not initialize PortAudio: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  PaStreamParameters output_parameters;
  output_parameters.device = Pa_GetDefaultOutputDevice();
  output_parameters.channelCount = buffer->num_channels;
  output_parameters.sampleFormat = paFloat32;
  output_parameters.suggestedLatency = Pa_GetDeviceInfo(output_parameters.device)->defaultLowOutputLatency;
  output_parameters.hostApiSpecificStreamInfo = NULL;

  PaStreamParameters input_parameters;
  input_parameters.device = Pa_GetDefaultInputDevice();
  input_parameters.channelCount = 1;
  input_parameters.sampleFormat = paFloat32;
  input_parameters.suggestedLatency = Pa_GetDeviceInfo(input_parameters.device)->defaultLowInputLatency;
  input_parameters.hostApiSpecificStreamInfo = NULL;

  error = Pa_OpenStream(&stream, &input_parameters, &output_parameters, sample_rate, buffer_size, paClipOff, audio_callback, buffer);
  if (error != paNoError) {
    printf("Could not open stream: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  error = Pa_StartStream(stream);
  if (error != paNoError) {
    printf("Could not start stream: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  while (Pa_IsStreamActive(stream)) {
    Pa_Sleep(100);
  }

  error = Pa_StopStream(stream);
  if (error != paNoError) {
    printf("Could not stop stream: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  error = Pa_CloseStream(stream);
  if (error != paNoError) {
    printf("Could not close stream: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  Pa_Terminate();

  free_audio_buffer(buffer);

  return 0;
}
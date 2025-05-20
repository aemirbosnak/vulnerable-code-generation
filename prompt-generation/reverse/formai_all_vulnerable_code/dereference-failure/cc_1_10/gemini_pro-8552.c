//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float left_gain;
  float right_gain;
} ChannelGains;

typedef struct {
  ChannelGains gains;
  int num_channels;
  int sample_rate;
  int frames_per_buffer;
  PaStream *stream;
  float *buffer;
} AudioConfig;

static void audio_callback(const void *input, void *output, unsigned long frameCount,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags, void *userData) {
  AudioConfig *config = (AudioConfig *)userData;

  const float *in = (const float *)input;
  float *out = (float *)output;

  for (unsigned int i = 0; i < frameCount * config->num_channels; ++i) {
    if (i % 2 == 0) {
      out[i] = in[i] * config->gains.left_gain;
    } else {
      out[i] = in[i] * config->gains.right_gain;
    }
  }
}

static void init_audio_config(AudioConfig *config, ChannelGains gains,
                               int num_channels, int sample_rate, int frames_per_buffer) {
  config->gains = gains;
  config->num_channels = num_channels;
  config->sample_rate = sample_rate;
  config->frames_per_buffer = frames_per_buffer;
  config->stream = NULL;
  config->buffer = NULL;
}

static void free_audio_config(AudioConfig *config) {
  if (config->stream != NULL) {
    Pa_CloseStream(config->stream);
  }
  if (config->buffer != NULL) {
    free(config->buffer);
  }
}

int main(int argc, char **argv) {
  PaError err;

  // Initialize PortAudio
  err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "Error initializing PortAudio: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  // Set up audio configuration
  ChannelGains gains = {0.5f, 0.5f};
  AudioConfig config;
  init_audio_config(&config, gains, NUM_CHANNELS, SAMPLE_RATE, FRAMES_PER_BUFFER);

  // Open audio stream
  PaStreamParameters inputParameters, outputParameters;
  inputParameters.device = Pa_GetDefaultInputDevice();
  inputParameters.channelCount = config.num_channels;
  inputParameters.sampleFormat = paFloat32;
  inputParameters.suggestedLatency =
      Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;

  outputParameters.device = Pa_GetDefaultOutputDevice();
  outputParameters.channelCount = config.num_channels;
  outputParameters.sampleFormat = paFloat32;
  outputParameters.suggestedLatency =
      Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;

  err = Pa_OpenStream(&config.stream, &inputParameters, &outputParameters, config.sample_rate,
                     config.frames_per_buffer, paClipOff, audio_callback, &config);
  if (err != paNoError) {
    fprintf(stderr, "Error opening audio stream: %s\n", Pa_GetErrorText(err));
    free_audio_config(&config);
    Pa_Terminate();
    return -1;
  }

  // Allocate buffer
  config.buffer = (float *)malloc(config.num_channels * config.frames_per_buffer * sizeof(float));
  if (config.buffer == NULL) {
    fprintf(stderr, "Error allocating buffer\n");
    free_audio_config(&config);
    Pa_Terminate();
    return -1;
  }

  // Start audio stream
  err = Pa_StartStream(config.stream);
  if (err != paNoError) {
    fprintf(stderr, "Error starting audio stream: %s\n", Pa_GetErrorText(err));
    free_audio_config(&config);
    Pa_Terminate();
    return -1;
  }

  // Wait for user to press Enter
  getchar();

  // Stop audio stream
  err = Pa_StopStream(config.stream);
  if (err != paNoError) {
    fprintf(stderr, "Error stopping audio stream: %s\n", Pa_GetErrorText(err));
    free_audio_config(&config);
    Pa_Terminate();
    return -1;
  }

  // Close audio stream and free resources
  free_audio_config(&config);
  Pa_Terminate();

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

typedef struct {
  float *buffer;
  int buffer_size;
  int buffer_index;
} RingBuffer;

void ring_buffer_init(RingBuffer *ring_buffer, int buffer_size) {
  ring_buffer->buffer = malloc(sizeof(float) * buffer_size);
  ring_buffer->buffer_size = buffer_size;
  ring_buffer->buffer_index = 0;
}

void ring_buffer_free(RingBuffer *ring_buffer) {
  free(ring_buffer->buffer);
}

void ring_buffer_write(RingBuffer *ring_buffer, float sample) {
  ring_buffer->buffer[ring_buffer->buffer_index++] = sample;
  if (ring_buffer->buffer_index == ring_buffer->buffer_size) {
    ring_buffer->buffer_index = 0;
  }
}

float ring_buffer_read(RingBuffer *ring_buffer) {
  float sample = ring_buffer->buffer[ring_buffer->buffer_index++];
  if (ring_buffer->buffer_index == ring_buffer->buffer_size) {
    ring_buffer->buffer_index = 0;
  }
  return sample;
}

int portaudio_callback(const void *input_buffer, void *output_buffer,
                       unsigned long frames_per_buffer,
                       const PaStreamCallbackTimeInfo *time_info,
                       PaStreamCallbackFlags status_flags,
                       void *user_data) {
  RingBuffer *ring_buffer = (RingBuffer *)user_data;
  float *input = (float *)input_buffer;
  float *output = (float *)output_buffer;

  for (int i = 0; i < frames_per_buffer; i++) {
    float sample = input[i * NUM_CHANNELS];
    ring_buffer_write(ring_buffer, sample);
    output[i * NUM_CHANNELS] = ring_buffer_read(ring_buffer);
  }

  return paContinue;
}

int main() {
  RingBuffer ring_buffer;
  ring_buffer_init(&ring_buffer, FRAMES_PER_BUFFER);

  PaStream *stream;
  PaError err;

  err = Pa_Initialize();
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  PaStreamParameters input_params, output_params;
  input_params.device = Pa_GetDefaultInputDevice();
  input_params.channelCount = NUM_CHANNELS;
  input_params.sampleFormat = paFloat32;
  input_params.suggestedLatency =
      Pa_GetDeviceInfo(input_params.device)->defaultLowOutputLatency;
  input_params.hostApiSpecificStreamInfo = NULL;

  output_params.device = Pa_GetDefaultOutputDevice();
  output_params.channelCount = NUM_CHANNELS;
  output_params.sampleFormat = paFloat32;
  output_params.suggestedLatency =
      Pa_GetDeviceInfo(output_params.device)->defaultLowInputLatency;
  output_params.hostApiSpecificStreamInfo = NULL;

  err = Pa_OpenStream(&stream, &input_params, &output_params, SAMPLE_RATE,
                     FRAMES_PER_BUFFER, 0, portaudio_callback, &ring_buffer);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  printf("Press any key to stop.\n");
  getchar();

  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
    return -1;
  }

  ring_buffer_free(&ring_buffer);

  Pa_Terminate();

  return 0;
}
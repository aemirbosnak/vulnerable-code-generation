//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE   (44100)
#define NUM_CHANNELS  (1)
#define BLOCK_SIZE    (1024)

typedef struct {
  float *buffer;
  int buffer_size;
  int buffer_index;
} audio_buffer;

audio_buffer *create_buffer(int size) {
  audio_buffer *buffer = malloc(sizeof(audio_buffer));
  buffer->buffer = malloc(size * sizeof(float));
  buffer->buffer_size = size;
  buffer->buffer_index = 0;
  return buffer;
}

void destroy_buffer(audio_buffer *buffer) {
  free(buffer->buffer);
  free(buffer);
}

void write_buffer(audio_buffer *buffer, float *data, int size) {
  for (int i = 0; i < size; i++) {
    buffer->buffer[buffer->buffer_index++] = data[i];
    if (buffer->buffer_index >= buffer->buffer_size)
      buffer->buffer_index = 0;
  }
}

float *read_buffer(audio_buffer *buffer, int size) {
  float *data = malloc(size * sizeof(float));
  int start_index = buffer->buffer_index - size;
  if (start_index < 0)
    start_index += buffer->buffer_size;
  for (int i = 0; i < size; i++)
    data[i] = buffer->buffer[(start_index + i) % buffer->buffer_size];
  return data;
}

static int callback(const void *inputBuffer, void *outputBuffer,
                    unsigned long framesPerBuffer,
                    const PaStreamCallbackTimeInfo* timeInfo,
                    PaStreamCallbackFlags statusFlags,
                    void *userData) {
  float *in = (float *)inputBuffer;
  float *out = (float *)outputBuffer;
  audio_buffer *buffer = (audio_buffer *)userData;
  (void) timeInfo; /* Prevent unused variable warning. */
  (void) statusFlags; /* Prevent unused variable warning. */

  for (unsigned int i = 0; i < framesPerBuffer; i++) {
    float sample = *in++;
    float delayed_sample = *read_buffer(buffer, i);
    *out++ = sample + (delayed_sample * 0.5);
    write_buffer(buffer, &sample, 1);
  }
  return paContinue;
}

int main(int argc, char *argv[]) {
  PaStream *stream;
  audio_buffer *buffer;
  PaError err;

  /* Initialize PortAudio. */
  err = Pa_Initialize();
  if (err != paNoError) goto error;

  /* Open an audio stream. */
  err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32, SAMPLE_RATE, BLOCK_SIZE, callback, buffer);
  if (err != paNoError) goto error;

  /* Create the audio buffer. */
  buffer = create_buffer(BLOCK_SIZE);

  /* Start the stream. */
  err = Pa_StartStream(stream);
  if (err != paNoError) goto error;

  printf("Press any key to stop the stream.\n");
  getchar();

  /* Stop the stream. */
  err = Pa_StopStream(stream);
  if (err != paNoError) goto error;

  /* Close the stream. */
  err = Pa_CloseStream(stream);
  if (err != paNoError) goto error;

  /* Destroy the audio buffer. */
  destroy_buffer(buffer);

  /* Terminate PortAudio. */
  Pa_Terminate();

  return EXIT_SUCCESS;

error:
  Pa_Terminate();
  fprintf(stderr, "An error occurred: %s\n", Pa_GetErrorText(err));
  return EXIT_FAILURE;
}
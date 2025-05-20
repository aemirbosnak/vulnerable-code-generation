//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define NUM_CHANNELS 2

typedef struct {
  float *left_buffer;
  float *right_buffer;
  int buffer_size;
} StereoBuffer;

typedef struct {
  StereoBuffer input_buffer;
  StereoBuffer output_buffer;
} AudioData;

static int audio_callback(
    const void *input_buffer, void *output_buffer, unsigned long frames_per_buffer,
    const PaStreamCallbackTimeInfo *time_info, PaStreamCallbackFlags status_flags,
    void *user_data) {
  AudioData *data = (AudioData *)user_data;

  memcpy(data->input_buffer.left_buffer, input_buffer,
         frames_per_buffer * sizeof(float));
  memcpy(data->input_buffer.right_buffer,
         (char *)input_buffer + sizeof(float) * frames_per_buffer,
         frames_per_buffer * sizeof(float));

  // Do some processing on the audio data here

  memcpy(output_buffer, data->output_buffer.left_buffer,
         frames_per_buffer * sizeof(float));
  memcpy((char *)output_buffer + sizeof(float) * frames_per_buffer,
         data->output_buffer.right_buffer, frames_per_buffer * sizeof(float));

  return paContinue;
}

int main(int argc, char **argv) {
  PaStream *stream;
  PaError error;
  AudioData data;

  // Initialize PortAudio
  error = Pa_Initialize();
  if (error != paNoError) {
    printf("Error initializing PortAudio: %s\n", Pa_GetErrorText(error));
    return 1;
  }

  // Open the default input and output devices
  error = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, NUM_CHANNELS, paFloat32,
                               SAMPLE_RATE, FRAMES_PER_BUFFER, audio_callback, &data);
  if (error != paNoError) {
    printf("Error opening default stream: %s\n", Pa_GetErrorText(error));
    Pa_Terminate();
    return 1;
  }

  // Allocate buffers for the audio data
  data.input_buffer.left_buffer =
      (float *)malloc(FRAMES_PER_BUFFER * sizeof(float));
  data.input_buffer.right_buffer =
      (float *)malloc(FRAMES_PER_BUFFER * sizeof(float));
  data.output_buffer.left_buffer =
      (float *)malloc(FRAMES_PER_BUFFER * sizeof(float));
  data.output_buffer.right_buffer =
      (float *)malloc(FRAMES_PER_BUFFER * sizeof(float));

  // Start the stream
  error = Pa_StartStream(stream);
  if (error != paNoError) {
    printf("Error starting stream: %s\n", Pa_GetErrorText(error));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return 1;
  }

  // Keep the program running until the user presses a key
  printf("Press any key to stop the program.\n");
  getchar();

  // Stop the stream
  error = Pa_StopStream(stream);
  if (error != paNoError) {
    printf("Error stopping stream: %s\n", Pa_GetErrorText(error));
    Pa_CloseStream(stream);
    Pa_Terminate();
    return 1;
  }

  // Close the stream
  error = Pa_CloseStream(stream);
  if (error != paNoError) {
    printf("Error closing stream: %s\n", Pa_GetErrorText(error));
    Pa_Terminate();
    return 1;
  }

  // Terminate PortAudio
  Pa_Terminate();

  // Free the buffers
  free(data.input_buffer.left_buffer);
  free(data.input_buffer.right_buffer);
  free(data.output_buffer.left_buffer);
  free(data.output_buffer.right_buffer);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define NUM_CHANNELS 2
#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (512)
#define NUM_SECONDS (5)
#define TABLE_SIZE (2048)

typedef struct {
  float *table;
  int size;
  float index;
} Wavetable;

static Wavetable sine_table;

static void fill_sine_table(Wavetable *table) {
  for (int i = 0; i < table->size; i++) {
    table->table[i] = sinf(2 * M_PI * i / table->size);
  }
}

static float wavetable_get(Wavetable *table, float index) {
  int int_index = (int)index;
  float frac_index = index - int_index;
  float v0 = table->table[int_index % table->size];
  float v1 = table->table[(int_index + 1) % table->size];
  return (1 - frac_index) * v0 + frac_index * v1;
}

static void process_audio(float *output, int num_frames, void *data) {
  Wavetable *table = (Wavetable *)data;
  for (int i = 0; i < num_frames; i++) {
    table->index += (float)i / SAMPLE_RATE;
    float v = wavetable_get(table, table->index);
    output[i * NUM_CHANNELS] = v;
    output[i * NUM_CHANNELS + 1] = v;
  }
}

int main(int argc, char **argv) {
  sine_table.size = TABLE_SIZE;
  sine_table.table = (float *)malloc(sizeof(float) * TABLE_SIZE);
  fill_sine_table(&sine_table);

  PaStreamParameters output_parameters;
  output_parameters.device = Pa_GetDefaultOutputDevice();
  output_parameters.channelCount = NUM_CHANNELS;
  output_parameters.sampleFormat = paFloat32;
  output_parameters.suggestedLatency = Pa_GetDeviceInfo(output_parameters.device)->defaultLowOutputLatency;
  output_parameters.hostApiSpecificStreamInfo = NULL;

  PaStream *stream;
  PaError err = Pa_OpenStream(&stream, NULL, &output_parameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, process_audio, &sine_table);
  if (err != paNoError) {
    fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_StartStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  printf("Playing for %d seconds.\n", NUM_SECONDS);
  Pa_Sleep(NUM_SECONDS * 1000);

  err = Pa_StopStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Error stopping stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  err = Pa_CloseStream(stream);
  if (err != paNoError) {
    fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
    return 1;
  }

  free(sine_table.table);
  return 0;
}
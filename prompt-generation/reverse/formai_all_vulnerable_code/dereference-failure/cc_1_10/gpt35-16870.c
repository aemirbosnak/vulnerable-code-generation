//FormAI DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
  unsigned char *data;
  int count;
} RingBuffer;

void ringBufferInit(RingBuffer *b, int size) {
  b->data = malloc(size);
  b->count = 0;
}

void ringBufferWrite(RingBuffer *b, unsigned char c) {
  b->data[b->count++ % BUFFER_SIZE] = c;
}

unsigned char ringBufferRead(RingBuffer *b, int index) {
  return b->data[index % BUFFER_SIZE];
}

void *processAudio(void *arg) {
  RingBuffer *input = (RingBuffer *)arg;
  RingBuffer *output = malloc(sizeof(RingBuffer));
  ringBufferInit(output, BUFFER_SIZE);

  for(int i = 0; i < BUFFER_SIZE; i++) {
    unsigned char sample = ringBufferRead(input, i);
    // perform some audio processing
    sample = sin(sample * M_PI / 128.0) * 128.0 + 128.0;
    ringBufferWrite(output, sample);
  }

  return output;
}

int main() {
  pthread_t thread;
  RingBuffer input;
  ringBufferInit(&input, BUFFER_SIZE);

  // fill input buffer with audio samples
  for(int i = 0; i < BUFFER_SIZE; i++) {
    ringBufferWrite(&input, rand() % 256);
  }

  // process audio in separate thread
  pthread_create(&thread, NULL, processAudio, (void *)&input);

  // continue doing other things while audio processing thread runs
  // ...

  // wait for audio processing thread to finish and retrieve output
  RingBuffer *output;
  pthread_join(thread, (void **)&output);

  // print output to console
  for(int i = 0; i < BUFFER_SIZE; i++) {
    printf("%u ", ringBufferRead(output, i));
  }
  printf("\n");

  free(input.data);
  free(output->data);
  free(output);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFERSIZE 1024

typedef struct SoundBuffer {
  short samples[ BUFFERSIZE ];
  int head, tail, samplesUsed;
} SoundBuffer;

SoundBuffer* createSoundBuffer() {
  SoundBuffer* buffer = malloc(sizeof(SoundBuffer));
  buffer->head = 0;
  buffer->tail = 0;
  buffer->samplesUsed = 0;
  return buffer;
}

void addToSoundBuffer(SoundBuffer* buffer, short sample) {
  buffer->samples[buffer->tail] = sample;
  buffer->tail++;
  buffer->samplesUsed++;
  if (buffer->samplesUsed == BUFFERSIZE) {
    buffer->head++;
  }
}

void playSoundBuffer(SoundBuffer* buffer) {
  for (int i = 0; i < buffer->samplesUsed; i++) {
    short sample = buffer->samples[buffer->head];
    buffer->head++;
    printf("%hi ", sample);
  }
  printf("\n");
}

int main() {
  SoundBuffer* buffer = createSoundBuffer();
  addToSoundBuffer(buffer, 10);
  addToSoundBuffer(buffer, 20);
  addToSoundBuffer(buffer, 30);
  addToSoundBuffer(buffer, 40);
  addToSoundBuffer(buffer, 50);

  playSoundBuffer(buffer);

  return 0;
}
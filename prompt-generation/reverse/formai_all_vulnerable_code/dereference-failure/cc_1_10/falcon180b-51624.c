//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 10
#define NUM_THREADS 4

typedef struct {
    float *buffer;
    int start_index;
    int end_index;
} block_t;

void *process_block(void *arg) {
    block_t *block = arg;
    int start_index = block->start_index;
    int end_index = block->end_index;
    float *buffer = block->buffer;
    for (int i = start_index; i < end_index; i++) {
        buffer[i] *= 2;
    }
    return NULL;
}

int main() {
    float *audio_buffer = malloc(SAMPLE_RATE * BLOCK_SIZE * sizeof(float));
    for (int i = 0; i < SAMPLE_RATE * BLOCK_SIZE; i++) {
        audio_buffer[i] = i;
    }

    block_t *blocks = malloc(NUM_BLOCKS * sizeof(block_t));
    for (int i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].buffer = audio_buffer + i * BLOCK_SIZE;
        blocks[i].start_index = i * BLOCK_SIZE;
        blocks[i].end_index = (i + 1) * BLOCK_SIZE;
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int j = i * NUM_BLOCKS / NUM_THREADS;
        pthread_create(&threads[i], NULL, process_block, blocks + j);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(audio_buffer);
    free(blocks);
    return 0;
}
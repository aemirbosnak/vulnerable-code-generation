//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_FRAMES (int)ceil((double)SAMPLE_RATE / FRAME_SIZE)

typedef struct {
    double *data;
    int size;
} AudioBuffer;

void *audio_thread(void *arg) {
    AudioBuffer *buffer = (AudioBuffer *)arg;
    int i, j;

    for (i = 0; i < buffer->size; i++) {
        double sample = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
        for (j = 0; j < FRAME_SIZE; j++) {
            buffer->data[i * FRAME_SIZE + j] = sample;
        }
    }

    return NULL;
}

int main() {
    AudioBuffer buffer;
    pthread_t thread;
    int rc;

    buffer.size = SAMPLE_RATE * 5;
    buffer.data = (double *)malloc(buffer.size * sizeof(double));

    srand(time(NULL));
    for (int i = 0; i < buffer.size; i++) {
        buffer.data[i] = rand() % 100;
    }

    rc = pthread_create(&thread, NULL, audio_thread, &buffer);
    if (rc) {
        fprintf(stderr, "Error: unable to create thread, %d\n", rc);
        exit(-1);
    }

    rc = pthread_join(thread, NULL);
    if (rc) {
        fprintf(stderr, "Error: unable to join thread, %d\n", rc);
        exit(-1);
    }

    for (int i = 0; i < buffer.size; i++) {
        printf("%f ", buffer.data[i]);
    }

    free(buffer.data);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define NUM_SAMPLES 44100
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int start_sample;
    int end_sample;
} ThreadData;

void *process_audio(void *arg) {
    ThreadData *data = arg;
    int thread_id = data->thread_id;
    int start_sample = data->start_sample;
    int end_sample = data->end_sample;

    double *input_buffer = malloc(NUM_SAMPLES * sizeof(double));
    double *output_buffer = malloc(NUM_SAMPLES * sizeof(double));

    for (int i = start_sample; i < end_sample; i++) {
        input_buffer[i] = sin(2 * M_PI * 440 * i / SAMPLE_RATE);
    }

    for (int i = 0; i < NUM_SAMPLES; i++) {
        output_buffer[i] = input_buffer[i] * 0.5;
    }

    printf("Thread %d processed samples %d to %d\n", thread_id, start_sample, end_sample);

    free(input_buffer);
    free(output_buffer);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i + 1;
        data[i].start_sample = i * NUM_SAMPLES / NUM_THREADS;
        data[i].end_sample = (i + 1) * NUM_SAMPLES / NUM_THREADS;

        pthread_create(&threads[i], NULL, process_audio, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int start_frame;
    int num_frames;
} thread_data;

void *process_audio(void *arg) {
    thread_data *data = arg;
    int thread_id = data->thread_id;
    int start_frame = data->start_frame;
    int num_frames = data->num_frames;

    double *input_buffer = malloc(sizeof(double) * num_frames);
    double *output_buffer = malloc(sizeof(double) * num_frames);

    for (int i = 0; i < num_frames; i++) {
        input_buffer[i] = sin(2 * M_PI * 440 * (i + start_frame) / SAMPLE_RATE);
    }

    for (int i = 0; i < num_frames; i++) {
        output_buffer[i] = input_buffer[i] * 0.5;
    }

    free(input_buffer);
    free(output_buffer);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        data[i].start_frame = i * FRAME_SIZE;
        data[i].num_frames = FRAME_SIZE;

        pthread_create(&threads[i], NULL, process_audio, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
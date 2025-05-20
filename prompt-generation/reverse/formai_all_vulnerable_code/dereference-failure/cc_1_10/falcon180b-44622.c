//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define SAMPLES 1024

typedef struct {
    int thread_id;
    int start_index;
    int end_index;
} thread_data_t;

void *process_data(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int thread_id = data->thread_id;
    int start_index = data->start_index;
    int end_index = data->end_index;

    float *input_buffer = (float *) malloc(SAMPLES * sizeof(float));
    float *output_buffer = (float *) malloc(SAMPLES * sizeof(float));

    for (int i = start_index; i < end_index; i++) {
        input_buffer[i] = i;
    }

    for (int i = 0; i < SAMPLES; i++) {
        output_buffer[i] = input_buffer[i] + thread_id;
    }

    free(input_buffer);
    free(output_buffer);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        data[i].start_index = i * SAMPLES / NUM_THREADS;
        data[i].end_index = (i + 1) * SAMPLES / NUM_THREADS;

        pthread_create(&threads[i], NULL, process_data, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
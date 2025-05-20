//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
    int id;
    float *input_buffer;
    float *output_buffer;
    int buffer_size;
};

void *process_data(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int id = data->id;
    float *input_buffer = data->input_buffer;
    float *output_buffer = data->output_buffer;
    int buffer_size = data->buffer_size;

    for (int i = 0; i < buffer_size; i++) {
        float sample = input_buffer[i];
        sample *= 2.0;
        output_buffer[i] = sample;
    }

    printf("Thread %d finished processing data\n", id);
    return NULL;
}

int main() {
    int buffer_size = 1024;
    float *input_buffer = (float *) malloc(buffer_size * sizeof(float));
    float *output_buffer = (float *) malloc(buffer_size * sizeof(float));

    for (int i = 0; i < buffer_size; i++) {
        input_buffer[i] = (float) i / (float) buffer_size;
    }

    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i;
        thread_data[i].input_buffer = input_buffer;
        thread_data[i].output_buffer = output_buffer;
        thread_data[i].buffer_size = buffer_size;

        pthread_create(&threads[i], NULL, process_data, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(input_buffer);
    free(output_buffer);

    return 0;
}
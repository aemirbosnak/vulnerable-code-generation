//GEMINI-pro DATASET v1.0 Category: Digital signal processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    int *data;
    int size;
    int head;
    int tail;
    pthread_mutex_t mutex;
    pthread_cond_t cv;
} buffer_t;

void buffer_init(buffer_t *buffer, int size) {
    buffer->data = malloc(sizeof(int) * size);
    buffer->size = size;
    buffer->head = 0;
    buffer->tail = 0;
    pthread_mutex_init(&buffer->mutex, NULL);
    pthread_cond_init(&buffer->cv, NULL);
}

void buffer_destroy(buffer_t *buffer) {
    pthread_mutex_destroy(&buffer->mutex);
    pthread_cond_destroy(&buffer->cv);
    free(buffer->data);
}

void buffer_push(buffer_t *buffer, int data) {
    pthread_mutex_lock(&buffer->mutex);
    while ((buffer->tail + 1) % buffer->size == buffer->head) {
        pthread_cond_wait(&buffer->cv, &buffer->mutex);
    }
    buffer->data[buffer->tail] = data;
    buffer->tail = (buffer->tail + 1) % buffer->size;
    pthread_cond_signal(&buffer->cv);
    pthread_mutex_unlock(&buffer->mutex);
}

int buffer_pop(buffer_t *buffer) {
    pthread_mutex_lock(&buffer->mutex);
    while (buffer->tail == buffer->head) {
        pthread_cond_wait(&buffer->cv, &buffer->mutex);
    }
    int data = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->size;
    pthread_cond_signal(&buffer->cv);
    pthread_mutex_unlock(&buffer->mutex);
    return data;
}

typedef struct {
    buffer_t *input_buffer;
    buffer_t *output_buffer;
    int filter_order;
    double *filter_coefficients;
} filter_t;

void *filter_thread(void *arg) {
    filter_t *filter = (filter_t *)arg;
    while (true) {
        int input = buffer_pop(filter->input_buffer);
        double output = 0.0;
        for (int i = 0; i < filter->filter_order; i++) {
            output += filter->filter_coefficients[i] * input;
        }
        buffer_push(filter->output_buffer, output);
    }
    return NULL;
}

int main() {
    // Create input buffer
    buffer_t input_buffer;
    buffer_init(&input_buffer, BUFFER_SIZE);

    // Create output buffer
    buffer_t output_buffer;
    buffer_init(&output_buffer, BUFFER_SIZE);

    // Create filter
    filter_t filter;
    filter.input_buffer = &input_buffer;
    filter.output_buffer = &output_buffer;
    filter.filter_order = 3;
    filter.filter_coefficients = malloc(sizeof(double) * filter.filter_order);
    for (int i = 0; i < filter.filter_order; i++) {
        filter.filter_coefficients[i] = 1.0 / filter.filter_order;
    }

    // Create filter threads
    pthread_t filter_threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&filter_threads[i], NULL, filter_thread, &filter);
    }

    // Generate input data
    for (int i = 0; i < 1000; i++) {
        buffer_push(&input_buffer, i);
    }

    // Read output data
    for (int i = 0; i < 1000; i++) {
        int output = buffer_pop(&output_buffer);
        printf("%d\n", output);
    }

    // Destroy filter
    free(filter.filter_coefficients);

    // Destroy input buffer
    buffer_destroy(&input_buffer);

    // Destroy output buffer
    buffer_destroy(&output_buffer);

    // Wait for filter threads to exit
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(filter_threads[i], NULL);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_THREADS 4
#define SAMPLES 1000
#define FREQ 440

typedef struct {
    int id;
    int start;
    int end;
} thread_data;

void *process_data(void *arg) {
    thread_data *data = (thread_data *) arg;
    int id = data->id;
    int start = data->start;
    int end = data->end;

    double *signal = (double *) malloc(SAMPLES * sizeof(double));
    for (int i = 0; i < SAMPLES; i++) {
        signal[i] = sin(2 * M_PI * (i * FREQ / SAMPLES));
    }

    double *filtered_signal = (double *) malloc(SAMPLES * sizeof(double));
    for (int i = start; i < end; i++) {
        filtered_signal[i] = signal[i] * 0.5;
    }

    printf("Thread %d processed samples %d to %d\n", id, start, end);
    free(signal);
    free(filtered_signal);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].id = i + 1;
        data[i].start = i * (SAMPLES / MAX_THREADS);
        data[i].end = (i + 1) * (SAMPLES / MAX_THREADS);
        pthread_create(&threads[i], NULL, process_data, (void *) &data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
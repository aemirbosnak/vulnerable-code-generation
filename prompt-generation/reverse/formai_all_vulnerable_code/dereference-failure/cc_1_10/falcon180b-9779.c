//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_SAMPLES 1000000
#define MAX_THREADS 4
#define MAX_TASK_SIZE (MAX_SAMPLES/MAX_THREADS)
#define PI 3.14159265359

typedef struct {
    float *src;
    float *dest;
    int start;
    int end;
} thread_data;

void *worker_thread(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i;
    for (i = data->start; i < data->end; i++) {
        data->dest[i] = sin(2*PI*data->src[i]);
    }
    return NULL;
}

int main() {
    int i;
    float *src, *dest;
    src = (float *) malloc(MAX_SAMPLES * sizeof(float));
    dest = (float *) malloc(MAX_SAMPLES * sizeof(float));
    srand(time(NULL));
    for (i = 0; i < MAX_SAMPLES; i++) {
        src[i] = rand() % 100;
    }
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];
    int task_size = MAX_SAMPLES / MAX_THREADS;
    for (i = 0; i < MAX_THREADS; i++) {
        data[i].src = src;
        data[i].dest = dest;
        data[i].start = i * task_size;
        data[i].end = (i == MAX_THREADS - 1)? MAX_SAMPLES : (i + 1) * task_size;
        pthread_create(&threads[i], NULL, worker_thread, &data[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    for (i = 0; i < MAX_SAMPLES; i++) {
        printf("%f ", dest[i]);
    }
    printf("\n");
    free(src);
    free(dest);
    return 0;
}
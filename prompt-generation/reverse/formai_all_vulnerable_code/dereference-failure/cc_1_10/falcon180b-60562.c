//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define THREAD_STACK_SIZE 4096

typedef struct {
    int id;
    float *data;
    int length;
} thread_data_t;

void *process_data(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j;
    float sum = 0.0;

    for (i = 0; i < data->length; i++) {
        for (j = 0; j < data->length; j++) {
            sum += data->data[i * data->length + j];
        }
    }

    printf("Thread %d computed sum: %f\n", data->id, sum);

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].data = (float *) malloc(sizeof(float) * data[i].length);
        data[i].length = 10;

        int rc = pthread_create(&threads[i], NULL, process_data, &data[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
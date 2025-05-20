//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_DATA_SIZE 1000000

typedef struct {
    int id;
    char *data;
    size_t size;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    char *result = malloc(data->size);

    memcpy(result, data->data, data->size);

    printf("Thread %d processed %zu bytes of data.\n", data->id, data->size);

    free(result);
    free(data->data);
    free(data);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].data = malloc(MAX_DATA_SIZE);
        data[i].size = rand() % MAX_DATA_SIZE;

        memset(data[i].data, 'a', data[i].size);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
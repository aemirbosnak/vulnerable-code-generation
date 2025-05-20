//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10
#define MAX_SIZE 1000

typedef struct {
    int id;
    int start;
    int end;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i;

    for (i = data->start; i <= data->end; i++) {
        printf("Thread %d is processing element %d\n", data->id, i);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    int start = 0;
    int end = MAX_SIZE / NUM_THREADS;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        thread_data *data = (thread_data *) malloc(sizeof(thread_data));
        data->id = i + 1;
        data->start = start;
        data->end = end;

        printf("Thread %d is processing elements [%d, %d)\n", data->id, data->start, data->end);
        pthread_create(&threads[i], NULL, thread_func, (void *) data);

        start += end;
        end += MAX_SIZE / NUM_THREADS;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
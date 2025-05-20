//Falcon-180B DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

struct thread_data {
    int thread_id;
    int *shared_data;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int *shared_data = data->shared_data;

    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < 10; i++) {
        shared_data[i] = shared_data[i] + thread_id;
    }

    printf("Thread %d finished\n", thread_id);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int shared_data[10] = {0};
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1;
        data->shared_data = shared_data;

        pthread_create(&threads[i], NULL, thread_func, data);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < 10; i++) {
        printf("Shared data %d: %d\n", i, shared_data[i]);
    }

    return 0;
}
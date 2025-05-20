//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024*1024

typedef struct thread_data {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    data->func(data->arg);
    return NULL;
}

int create_thread(pthread_t *thread, int id, void *(*func)(void *), void *arg) {
    thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
    if (!data) {
        return -1;
    }

    data->id = id;
    data->func = func;
    data->arg = arg;

    int ret = pthread_create(thread, NULL, thread_func, data);
    if (ret) {
        free(data);
        return ret;
    }

    return 0;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ret;

    for (int i = 0; i < MAX_THREADS; i++) {
        ret = create_thread(&threads[i], i, &thread_func, NULL);
        if (ret) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
    }

    printf("All threads joined successfully\n");
    return 0;
}
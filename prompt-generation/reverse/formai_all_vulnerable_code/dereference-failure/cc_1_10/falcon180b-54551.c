//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024 * 10

typedef struct thread_data {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

void *thread_func(void *param) {
    thread_data_t *data = param;
    data->func(data->arg);
    pthread_exit(0);
}

int create_thread(pthread_t *thread, void *(*start_routine)(void *), void *arg) {
    int ret;
    thread_data_t *data = malloc(sizeof(thread_data_t));
    if (data == NULL) {
        return -1;
    }
    data->id = -1;
    data->func = start_routine;
    data->arg = arg;
    ret = pthread_create(thread, NULL, thread_func, data);
    if (ret!= 0) {
        free(data);
        return ret;
    }
    data->id = *thread;
    return 0;
}

int join_thread(pthread_t thread, void **value_ptr) {
    int ret;
    thread_data_t *data = malloc(sizeof(thread_data_t));
    data->id = thread;
    ret = pthread_join(thread, value_ptr);
    free(data);
    return ret;
}

int main() {
    pthread_t threads[MAX_THREADS];
    void *value;
    int i, ret;

    for (i = 0; i < MAX_THREADS; i++) {
        ret = create_thread(&threads[i], &thread_func, &i);
        if (ret!= 0) {
            printf("Error: %d\n", ret);
            exit(1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        ret = join_thread(threads[i], &value);
        if (ret!= 0) {
            printf("Error: %d\n", ret);
            exit(1);
        }
    }

    return 0;
}
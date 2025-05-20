//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4

typedef struct ThreadArgs {
    int id;
    int* array;
    int size;
} ThreadArgs;

void* thread_func(void* args) {
    ThreadArgs* thread_args = (ThreadArgs*) args;
    int id = thread_args->id;
    int* array = thread_args->array;
    int size = thread_args->size;

    int start = id * (size / THREAD_COUNT);
    int end = (id + 1) * (size / THREAD_COUNT);

    if (id == THREAD_COUNT - 1) {
        end = size;
    }

    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }

    printf("Thread %d sum: %d\n", id, sum);

    free(args);

    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);

    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        ThreadArgs* thread_args = malloc(sizeof(ThreadArgs));
        thread_args->id = i;
        thread_args->array = arr;
        thread_args->size = size;

        pthread_create(&threads[i], NULL, thread_func, (void*) thread_args);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct {
    int* arr;
    int target;
    int start;
    int end;
    bool* found;
    pthread_mutex_t* mutex;
} SearchArgs;

void* search(void* arg) {
    SearchArgs* args = (SearchArgs*) arg;
    for (int i = args->start; i < args->end; i++) {
        if (args->arr[i] == args->target) {
            pthread_mutex_lock(args->mutex);
            *args->found = true;
            pthread_mutex_unlock(args->mutex);
            return NULL;
        }
    }
    return NULL;
}

bool async_search(int* arr, int size, int target) {
    bool found = false;
    int threads = 4;
    int chunk_size = size / threads;

    SearchArgs* search_args = malloc(threads * sizeof(SearchArgs));
    pthread_t* search_threads = malloc(threads * sizeof(pthread_t));
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    for (int i = 0; i < threads; i++) {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size;
        if (i == threads - 1) end = size;
        search_args[i] = (SearchArgs) {.arr=arr, .target=target, .start=start, .end=end, .found=&found, .mutex=&mutex};
        pthread_create(&search_threads[i], NULL, search, &search_args[i]);
    }

    for (int i = 0; i < threads; i++) {
        pthread_join(search_threads[i], NULL);
    }

    free(search_args);
    free(search_threads);

    return found;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    bool found = async_search(arr, size, target);
    if (found) {
        printf("Target number found!\n");
    } else {
        printf("Target number not found.\n");
    }

    return 0;
}
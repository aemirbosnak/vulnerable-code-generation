//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
    int start;
    int end;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = (thread_data *) arg;
    int *arr = data->arr;
    int size = data->size;
    int start = data->start;
    int end = data->end;

    for (int i = start; i < end; i++) {
        arr[i] = rand() % size;
    }

    return NULL;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }

    printf("Initial array:\n");
    print_array(arr, size);

    pthread_t threads[MAX_SIZE];
    thread_data data[MAX_SIZE];

    int num_threads = 4;
    int chunk_size = size / num_threads;

    for (int i = 0; i < num_threads; i++) {
        data[i].arr = arr;
        data[i].size = size;
        data[i].start = i * chunk_size;
        data[i].end = (i == num_threads - 1)? size : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final array:\n");
    print_array(arr, size);

    return 0;
}
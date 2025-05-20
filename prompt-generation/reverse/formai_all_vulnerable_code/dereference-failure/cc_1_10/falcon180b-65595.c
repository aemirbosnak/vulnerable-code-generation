//Falcon-180B DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ALLOCATIONS 100

typedef struct {
    int size;
    int thread_id;
} Allocation;

Allocation* allocations[MAX_ALLOCATIONS];
int num_allocations = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d started\n", thread_id);

    while (1) {
        pthread_mutex_lock(&mutex);
        if (num_allocations == MAX_ALLOCATIONS) {
            printf("Thread %d: No more memory available\n", thread_id);
            pthread_mutex_unlock(&mutex);
            break;
        }

        Allocation* allocation = (Allocation*)malloc(sizeof(Allocation));
        allocation->size = rand() % 100;
        allocation->thread_id = thread_id;
        allocations[num_allocations++] = allocation;
        printf("Thread %d allocated %d bytes\n", thread_id, allocation->size);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)&i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_allocations; i++) {
        free(allocations[i]);
    }

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Threading library implementation
typedef struct {
    int* data;
    int size;
    sem_t sem;
} thread_data_t;

void* thread_func(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    while (1) {
        sem_wait(&data->sem);
        int index = rand() % data->size;
        printf("Thread %ld: %d\n", pthread_self(), data->data[index]);
        sem_post(&data->sem);
    }
    return NULL;
}

int main() {
    srand(time(NULL));

    // Create a shared array of random numbers
    int size = 10;
    int* data = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        data[i] = rand() % 100;
    }

    // Create a semaphore to protect the shared array
    sem_t sem;
    sem_init(&sem, 0, 1);

    // Create a thread data structure
    thread_data_t thread_data;
    thread_data.data = data;
    thread_data.size = size;
    thread_data.sem = sem;

    // Create 10 threads
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_data);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&sem);

    // Free the shared array
    free(data);

    return 0;
}
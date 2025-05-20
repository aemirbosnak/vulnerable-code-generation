//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 10

typedef struct {
    int thread_id;
    int *sharedResource;
    pthread_mutex_t *mutex;
} ThreadData;

void* perform_work(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int id = data->thread_id;
    int *resource = data->sharedResource;
    pthread_mutex_t *lock = data->mutex;

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(lock);
        
        // Increment the shared resource
        (*resource)++;
        printf("Thread %d incremented resource to %d\n", id, *resource);

        // Simulate work
        sleep(rand() % 2 + 1); // Sleep for 1-2 seconds

        // Decrement the shared resource
        (*resource)--;
        printf("Thread %d decremented resource to %d\n", id, *resource);

        pthread_mutex_unlock(lock);
        sleep(rand() % 2); // Small sleep to allow context switching
    }

    free(data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int sharedResource = 0;
    pthread_mutex_t mutex;

    // Initialize random seed
    srand(time(NULL));

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        fprintf(stderr, "Mutex initialization failed\n");
        return EXIT_FAILURE;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        ThreadData *data = malloc(sizeof(ThreadData));
        data->thread_id = i;
        data->sharedResource = &sharedResource;
        data->mutex = &mutex;

        if (pthread_create(&threads[i], NULL, perform_work, (void *)data) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(data);
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup mutex
    pthread_mutex_destroy(&mutex);
    
    printf("Final value of shared resource: %d\n", sharedResource);
    return EXIT_SUCCESS;
}
//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define MAX_RESOURCES 3

sem_t semaphore;

void* thread_function(void* arg) {
    int thread_id = *((int*)arg);

    printf("Thread %d: Waiting to access the resources.\n", thread_id);
    
    // Wait for access to the semaphore
    sem_wait(&semaphore);
    
    printf("Thread %d: Acquired access to resources.\n", thread_id);
    
    // Simulate resource use
    sleep(rand() % 3 + 1);
    
    printf("Thread %d: Releasing resources.\n", thread_id);
    
    // Release access to the semaphore
    sem_post(&semaphore);
    
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    sem_init(&semaphore, 0, MAX_RESOURCES);
    
    printf("Starting the Resource Manager with %d resources.\n", MAX_RESOURCES);

    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int));
        *thread_id = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, thread_id) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
    printf("Resource Manager: All threads have completed.\n");
    
    return 0;
}
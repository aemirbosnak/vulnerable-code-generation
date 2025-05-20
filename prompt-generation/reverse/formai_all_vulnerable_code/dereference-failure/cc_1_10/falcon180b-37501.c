//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the size of the shared buffer
#define BUFFER_SIZE 10

// Define the mutex and condition variable
pthread_mutex_t mutex;
pthread_cond_t cond;

// Define the shared buffer
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

// Define the thread IDs
pthread_t threads[NUM_THREADS];

// Define the thread function
void *producer(void *arg) {
    int id = *(int *) arg;
    int count = 0;

    while (count < 10) {
        pthread_mutex_lock(&mutex);

        // Wait until there is space in the buffer
        while ((out + 1) % BUFFER_SIZE == in) {
            pthread_cond_wait(&cond, &mutex);
        }

        // Add the item to the buffer
        buffer[out] = id * 100 + count;
        out = (out + 1) % BUFFER_SIZE;

        printf("Producer %d produced %d\n", id, buffer[out]);

        pthread_mutex_unlock(&mutex);
        count++;
        usleep(100);
    }

    return NULL;
}

// Define the thread function
void *consumer(void *arg) {
    int id = *(int *) arg;
    int count = 0;

    while (count < 10) {
        pthread_mutex_lock(&mutex);

        // Wait until there is an item in the buffer
        while (in == out) {
            pthread_cond_wait(&cond, &mutex);
        }

        // Remove the item from the buffer
        int item = buffer[in];
        in = (in + 1) % BUFFER_SIZE;

        printf("Consumer %d consumed %d\n", id, item);

        pthread_mutex_unlock(&mutex);
        count++;
        usleep(100);
    }

    return NULL;
}

// Define the main function
int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, (i % 2 == 0)? producer : consumer, (void *) i);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
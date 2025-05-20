//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t mutex;

// Shared data structure
struct shared_data {
    int sum;
    int count;
};

// Thread function
void *thread_func(void *arg) {
    // Get the shared data structure
    struct shared_data *data = (struct shared_data *)arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Increment the count
    data->count++;

    // Add a random number to the sum
    srand(time(NULL));
    data->sum += rand() % 100;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Create a shared data structure
    struct shared_data data;
    data.sum = 0;
    data.count = 0;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread pool
    pthread_t *threads = malloc(10 * sizeof(pthread_t));

    // Create 10 threads
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the results
    printf("Sum: %d\n", data.sum);
    printf("Count: %d\n", data.count);

    return 0;
}
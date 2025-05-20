//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_ITERATIONS 10

pthread_mutex_t lock;
int shared_value = 0;

void* thread_function(void* thread_id) {
    int id = *((int*)thread_id);
    free(thread_id); // Free the allocated memory for thread_id

    for (int i = 0; i < NUM_ITERATIONS; i++) {
        int temp;

        // Randomly choose a bitwise operation
        int operation = rand() % 4;

        pthread_mutex_lock(&lock); // Lock the shared resource

        switch (operation) {
            case 0: // Bitwise AND
                temp = shared_value & (1 << (id + 1));
                printf("Thread %d performing AND: %d & %d = %d\n", id, shared_value, (1 << (id + 1)), temp);
                shared_value = temp;
                break;

            case 1: // Bitwise OR
                temp = shared_value | (1 << (id + 1));
                printf("Thread %d performing OR: %d | %d = %d\n", id, shared_value, (1 << (id + 1)), temp);
                shared_value = temp;
                break;

            case 2: // Bitwise XOR
                temp = shared_value ^ (1 << (id + 1));
                printf("Thread %d performing XOR: %d ^ %d = %d\n", id, shared_value, (1 << (id + 1)), temp);
                shared_value = temp;
                break;

            case 3: // Bitwise NOT (not on shared_value directly, as it's not reversible)
                temp = ~shared_value;
                printf("Thread %d performing NOT: ~%d = %d\n", id, shared_value, temp);
                shared_value = temp; // Update shared value
                break;
        }

        pthread_mutex_unlock(&lock); // Unlock the shared resource
        usleep(100000); // Sleep to simulate some work
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    // Creating threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int* thread_id = malloc(sizeof(int)); // Allocate memory for thread_id
        *thread_id = i; // Set the thread ID
        if (pthread_create(&threads[i], NULL, thread_function, thread_id)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Joining threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final shared value: %d\n", shared_value);
    pthread_mutex_destroy(&lock);
    return 0;
}
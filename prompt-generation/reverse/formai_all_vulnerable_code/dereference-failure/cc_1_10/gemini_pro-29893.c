//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Number of threads to create
#define NUM_THREADS 4

// Shared data structure to store the prime numbers
struct shared_data {
    int *prime_numbers;
    int num_prime_numbers;
    pthread_mutex_t lock;
};

// Function to generate prime numbers
void *generate_prime_numbers(void *arg) {
    struct shared_data *shared_data = (struct shared_data *)arg;

    int i, j, is_prime;

    for (i = 2; i < 100000; i++) {
        is_prime = 1;
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            pthread_mutex_lock(&shared_data->lock);
            shared_data->prime_numbers[shared_data->num_prime_numbers++] = i;
            pthread_mutex_unlock(&shared_data->lock);
        }
    }

    return NULL;
}

int main() {
    // Create shared data structure
    struct shared_data shared_data;
    shared_data.prime_numbers = malloc(100000 * sizeof(int));
    shared_data.num_prime_numbers = 0;
    pthread_mutex_init(&shared_data.lock, NULL);

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_prime_numbers, &shared_data);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print prime numbers
    for (int i = 0; i < shared_data.num_prime_numbers; i++) {
        printf("%d ", shared_data.prime_numbers[i]);
    }
    printf("\n");

    // Free shared data structure
    free(shared_data.prime_numbers);
    pthread_mutex_destroy(&shared_data.lock);

    return 0;
}
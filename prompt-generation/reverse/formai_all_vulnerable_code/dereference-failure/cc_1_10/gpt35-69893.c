//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Define a struct to store the arguments for each thread
struct thread_args {
    int start;
    int end;
    bool* primes;
};

// Define a function to be executed by each thread
void* find_primes(void* arg) {
    struct thread_args* t_args = (struct thread_args*)arg;

    // Loop over all numbers in the thread's range
    for (int i = t_args->start; i <= t_args->end; i++) {
        if (i < 2) {
            continue;
        }

        // Check if the number is prime
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }

        // Mark the number as prime in the shared array if it is prime
        if (is_prime) {
            t_args->primes[i] = true;
        }
    }

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // Parse command line arguments
    if (argc != 3) {
        printf("Usage: %s <num_threads> <max_num>\n", argv[0]);
        return 1;
    }
    int num_threads = atoi(argv[1]);
    int max_num = atoi(argv[2]);

    // Allocate the shared array to store which numbers are prime
    bool* primes = calloc(max_num + 1, sizeof(bool));
    if (primes == NULL) {
        printf("Error: failed to allocate memory for primes array\n");
        return 1;
    }

    // Create an array of thread argument structs, one for each thread
    struct thread_args* t_args = calloc(num_threads, sizeof(struct thread_args));
    if (t_args == NULL) {
        printf("Error: failed to allocate memory for array of thread args\n");
        free(primes);
        return 1;
    }

    // Spawn the threads to find primes in their respective ranges
    pthread_t* threads = calloc(num_threads, sizeof(pthread_t));
    if (threads == NULL) {
        printf("Error: failed to allocate memory for array of threads\n");
        free(primes);
        free(t_args);
        return 1;
    }
    int range_size = (max_num + 1) / num_threads;
    for (int i = 0; i < num_threads; i++) {
        t_args[i].start = i * range_size;
        t_args[i].end = (i == num_threads - 1) ? max_num : (i + 1) * range_size - 1;
        t_args[i].primes = primes;
        int ret = pthread_create(&threads[i], NULL, find_primes, &t_args[i]);
        if (ret) {
            printf("Error: pthread_create returned %d\n", ret);
            free(primes);
            free(t_args);
            free(threads);
            return 1;
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the primes found
    printf("Primes found:\n");
    for (int i = 2; i <= max_num; i++) {
        if (primes[i]) {
            printf("%d\n", i);
        }
    }

    // Free allocated memory and exit
    free(primes);
    free(t_args);
    free(threads);
    return 0;
}
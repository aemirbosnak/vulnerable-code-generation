//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 20

// Define a struct to pass arguments to our prime number thread
struct prime_thread_args {
    int thread_num;
    int start;
    int end;
};

// Define a function to check if a number is prime or not
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Define the function that each thread will run
void *calculate_primes(void *args) {
    struct prime_thread_args *thread_args = (struct prime_thread_args *) args;
    printf("Thread %d starting...\n", thread_args->thread_num);

    // Iterate through all the numbers in the thread's range and check if they are prime
    for (int i = thread_args->start; i <= thread_args->end; i++) {
        if (is_prime(i)) {
            printf("%d is a prime number!\n", i);
        }
    }

    printf("Thread %d finished!\n", thread_args->thread_num);
    free(thread_args);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int num_threads = atoi(argv[1]);
    int range = atoi(argv[2]);
    pthread_t threads[MAX_THREADS];
    int thread_num = 0;

    // Divide the range evenly between the threads
    int range_per_thread = range / num_threads;
    int remainder = range % num_threads;

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        struct prime_thread_args *args = (struct prime_thread_args *) malloc(sizeof(struct prime_thread_args));
        args->thread_num = thread_num;
        args->start = i * range_per_thread + 1;
        if (i == num_threads - 1) {
            // Add the remainder to the last thread's range
            args->end = args->start + range_per_thread + remainder - 1;
        } else {
            args->end = args->start + range_per_thread - 1;
        }
        int rc = pthread_create(&threads[thread_num], NULL, calculate_primes, (void *) args);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
        thread_num++;
    }

    // Wait for all the threads to finish
    for (int i = 0; i < thread_num; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);
}
//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Struct to store arguments for the thread function
struct ThreadArgs {
    int threadId;
    int numThreads;
    int intervalStart;
    int intervalEnd;
};

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// The thread function that generates prime numbers in a given interval
void* generatePrimes(void* arg) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)arg;
    int threadId = threadArgs->threadId;
    int numThreads = threadArgs->numThreads;
    int intervalStart = threadArgs->intervalStart;
    int intervalEnd = threadArgs->intervalEnd;

    printf("Thread %d generating prime numbers in [%d, %d]\n", threadId, intervalStart, intervalEnd);

    for (int num = intervalStart; num <= intervalEnd; num++) {
        if (isPrime(num)) {
            printf("Thread %d found prime number: %d\n", threadId, num);
        }
    }

    printf("Thread %d finished generating prime numbers in [%d, %d]\n", threadId, intervalStart, intervalEnd);

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <num_threads> <interval_size>\n", argv[0]);
        exit(1);
    }

    int numThreads = atoi(argv[1]);
    int intervalSize = atoi(argv[2]);

    pthread_t threads[numThreads];
    struct ThreadArgs threadArgs[numThreads];

    int intervalStart = 2;
    int intervalEnd = intervalSize - 1;

    for (int i = 0; i < numThreads; i++) {
        threadArgs[i].threadId = i;
        threadArgs[i].numThreads = numThreads;
        threadArgs[i].intervalStart = intervalStart;
        threadArgs[i].intervalEnd = intervalEnd;

        if (pthread_create(&threads[i], NULL, generatePrimes, &threadArgs[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }

        intervalStart += intervalSize;
        intervalEnd += intervalSize;
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    printf("All threads finished generating prime numbers\n");

    return 0;
}
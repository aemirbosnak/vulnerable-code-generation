//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 4

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void *generatePrimes(void *param) {
    int *range = (int *)param;
    int start = range[0];
    int end = range[1];
    printf("Generating primes in range %d to %d\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int ranges[NUM_THREADS][2];
    int rangeSize = n / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        ranges[i][0] = i * rangeSize + 1;
        ranges[i][1] = ranges[i][0] + rangeSize - 1;
        if (i == NUM_THREADS - 1) {
            ranges[i][1] = n;
        }
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        int *range = ranges[i];
        pthread_create(&threads[i], NULL, generatePrimes, range);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
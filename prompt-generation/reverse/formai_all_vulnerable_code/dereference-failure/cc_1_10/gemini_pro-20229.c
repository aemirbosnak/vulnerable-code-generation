//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct {
    int start;
    int end;
    int *primes;
    pthread_mutex_t *lock;
} prime_args;

int is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

void *prime_generator(void *args) {
    prime_args *p = (prime_args *)args;
    for (int i = p->start; i <= p->end; i++) {
        if (is_prime(i)) {
            pthread_mutex_lock(p->lock);
            p->primes[i - p->start] = i;
            pthread_mutex_unlock(p->lock);
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <number of primes>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid number of primes\n");
        return 1;
    }
    int *primes = (int *)malloc(n * sizeof(int));
    if (primes == NULL) {
        printf("Failed to allocate memory for primes\n");
        return 1;
    }
    pthread_t *threads = (pthread_t *)malloc(n * sizeof(pthread_t));
    if (threads == NULL) {
        printf("Failed to allocate memory for threads\n");
        free(primes);
        return 1;
    }
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < n; i++) {
        prime_args *args = (prime_args *)malloc(sizeof(prime_args));
        args->start = i * n / 8;
        args->end = (i + 1) * n / 8 - 1;
        args->primes = primes;
        args->lock = &lock;
        pthread_create(&threads[i], NULL, prime_generator, args);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    gettimeofday(&end, NULL);
    double time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Found %d primes in %f seconds:\n", n, time);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    free(primes);
    free(threads);
    return 0;
}
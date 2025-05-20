//Falcon2-11B DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int prime_numbers(int n, int* array, int* size) {
    int i, j;
    int result = 0;

    for (i = 0; i < n; i++) {
        array[i] = 0;
    }

    for (i = 2; i < n; i++) {
        if (array[i] == 0) {
            for (j = i * i; j < n; j += i) {
                array[j] = 1;
            }
            result++;
        }
    }

    *size = result;

    return result;
}

void* generate_primes(void* arg) {
    int n = *((int*)arg);
    int* array = (int*)malloc(n * sizeof(int));
    int size = 0;

    size = prime_numbers(n, array, &size);

    pthread_exit(NULL);
}

int main() {
    int n = 1000;
    int* array = (int*)malloc(n * sizeof(int));
    int size = 0;

    pthread_t thread;
    pthread_create(&thread, NULL, generate_primes, &n);

    pthread_join(thread, NULL);

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    return 0;
}
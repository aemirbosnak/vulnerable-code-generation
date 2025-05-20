//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000

typedef struct {
    bool isPrime;
    int number;
} PrimeNumber;

void sieveOfEratosthenes(PrimeNumber *primes, int limit) {
    int i, j;

    for (i = 0; i < limit; i++) {
        primes[i].number = i;
        primes[i].isPrime = true;
    }

    primes[0].isPrime = false;
    primes[1].isPrime = false;

    for (i = 2; i * i <= limit; i++) {
        if (primes[i].isPrime) {
            for (j = i * i; j <= limit; j += i) {
                primes[j].isPrime = false;
            }
        }
    }
}

int main() {
    PrimeNumber *primes;
    clock_t start, end;

    primes = (PrimeNumber *)calloc(MAX, sizeof(PrimeNumber));

    start = clock();
    sieveOfEratosthenes(primes, MAX);
    end = clock();

    printf("Prime Numbers up to %d:\n", MAX);

    for (int i = 0; i < MAX; i++) {
        if (primes[i].isPrime) {
            printf("%d ", primes[i].number);
        }
    }

    free(primes);

    printf("\nElapsed Time: %.6f milliseconds",
           (double)(end - start) * 1000 / CLOCKS_PER_SEC);

    return 0;
}
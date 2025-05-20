//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    int i;

    if (num == 1 || num == 0) {
        return 0;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int *generate_primes(int limit) {
    int i, j = 0;
    int *primes = malloc(sizeof(int) * limit);

    for (i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[j] = i;
            j++;
        }
    }

    primes = realloc(primes, sizeof(int) * j);

    return primes;
}

int main() {
    int i;
    int *primes = generate_primes(100);

    printf("Prime numbers up to 100:\n");

    for (i = 0; i < sizeof(primes) / sizeof(int); i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");

    free(primes);

    return 0;
}
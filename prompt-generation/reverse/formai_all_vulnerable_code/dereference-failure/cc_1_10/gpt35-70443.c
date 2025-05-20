//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This program generates prime numbers up to a given limit using the Sieve of Eratosthenes algorithm.
 */

bool *sieve(int limit);

int main(int argc, char *argv[]) {
    int limit = 0;
    
    if (argc > 1) {
        limit = atoi(argv[1]);
    }
    
    if (limit <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    
    bool *is_prime = sieve(limit);

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    free(is_prime);
    
    return 0;
}

/**
 * Sieve of Eratosthenes algorithm to generate primes up to a given limit.
 */
bool *sieve(int limit) {
    bool *is_prime = (bool *) malloc((limit + 1) * sizeof(bool));

    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}
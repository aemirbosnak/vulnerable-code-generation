//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Determine if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
    int* primes = malloc(sizeof(int) * limit);
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }
    return primes;
}

// Print a list of prime numbers up to a given limit
void print_primes(int* primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int limit = atoi(argv[1]);
    int* primes = generate_primes(limit);
    int count = 0;
    while (primes[count] != 0) {
        count++;
    }
    print_primes(primes, count);
    free(primes);

    return EXIT_SUCCESS;
}
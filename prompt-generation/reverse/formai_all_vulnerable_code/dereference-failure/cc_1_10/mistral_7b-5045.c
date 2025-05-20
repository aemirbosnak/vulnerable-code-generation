//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    // Check for divisibility up to the square root of the number
    int sqrt_num = sqrt(num);
    for (int i = 2; i <= sqrt_num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Helper function to initialize the boolean array for the sieve
void sieve_init(bool *sieve, int limit) {
    memset(sieve, true, sizeof(bool) * (limit + 1));
    sieve[0] = false;
    sieve[1] = false;
}

// Helper function to generate prime numbers using the sieve and is_prime function
void sieve_generate(int limit, int *primes, int *count) {
    bool *sieve = malloc(sizeof(bool) * (limit + 1));
    sieve_init(sieve, limit);

    // Mark the composite numbers in the sieve
    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p]) {
            for (int i = p * p; i <= limit; i += p) {
                sieve[i] = false;
            }
        }
    }

    // Store the prime numbers in an array
    *count = 0;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            primes[*count] = i;
            (*count)++;
        }
    }

    free(sieve);
}

int main() {
    int limit, count;
    printf("Enter the limit for prime number generation: ");
    scanf("%d", &limit);

    int *primes = malloc(sizeof(int) * limit);
    sieve_generate(limit, primes, &count);

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    free(primes);
    return 0;
}
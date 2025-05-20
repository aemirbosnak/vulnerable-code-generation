//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000000

// Function to check if a number is prime
bool is_prime(uint32_t num) {
    if (num <= 1) {
        return false;
    }
    for (uint32_t i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a given limit
uint32_t* generate_primes(uint32_t limit) {
    // Allocate memory for the array of prime numbers
    uint32_t* primes = malloc(sizeof(uint32_t) * limit);

    // Initialize the array with 0s
    for (uint32_t i = 0; i < limit; i++) {
        primes[i] = 0;
    }

    // Iterate over the numbers up to the limit
    for (uint32_t i = 2; i <= limit; i++) {
        // If the number is prime, add it to the array
        if (is_prime(i)) {
            primes[i] = i;
        }
    }

    // Return the array of prime numbers
    return primes;
}

// Function to print the prime numbers in the array
void print_primes(uint32_t* primes, uint32_t limit) {
    for (uint32_t i = 2; i <= limit; i++) {
        if (primes[i] != 0) {
            printf("%u\n", primes[i]);
        }
    }
}

int main() {
    // Generate prime numbers up to the given limit
    uint32_t* primes = generate_primes(MAX_SIZE);

    // Print the prime numbers
    print_primes(primes, MAX_SIZE);

    // Free the memory allocated for the array
    free(primes);

    return 0;
}
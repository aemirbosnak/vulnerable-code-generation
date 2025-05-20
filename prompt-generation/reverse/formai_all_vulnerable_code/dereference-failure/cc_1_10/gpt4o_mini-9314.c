//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int limit) {
    // Create an array of boolean values, initialized to true
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true; // Assume all numbers are prime initially
    }

    // 0 and 1 are not prime numbers
    is_prime[0] = false;
    is_prime[1] = false;

    // Implementing Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        // If is_prime[p] is still true, it's a prime
        if (is_prime[p]) {
            // Marking multiples of p as false (not prime)
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Print all prime numbers up to the limit
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(is_prime);
}

int main() {
    int limit;

    // User input for the limit
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);

    // Input validation
    if (limit < 2) {
        printf("Please enter a number greater than 1.\n");
        return 1;
    }

    // Call the function to generate prime numbers
    sieve_of_eratosthenes(limit);

    return 0;
}
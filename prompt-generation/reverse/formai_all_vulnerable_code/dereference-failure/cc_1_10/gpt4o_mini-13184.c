//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generate_primes(int limit) {
    // Array to hold the prime status of each number
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));

    // Initialize the array; assume all numbers are prime initially
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false; // 0 is not a prime number
    is_prime[1] = false; // 1 is not a prime number

    // Start the sieve
    for (int p = 2; p * p <= limit; p++) {
        // If is_prime[p] is not altered, then it is a prime
        if (is_prime[p] == true) {
            // Mark all multiples of p as not prime
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Output all prime numbers found
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

    // User prompt for the limit
    printf("Enter the upper limit to generate prime numbers: ");
    
    // Validate user input
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid integer greater than 1: ");
        while(getchar() != '\n'); // Clear the input buffer
    }

    // Generate and print prime numbers up to the specified limit
    generate_primes(limit);

    return 0;
}
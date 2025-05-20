//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void sieve_of_eratosthenes(int limit) {
    // Allocate memory for the prime number array
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        perror("Unable to allocate memory for prime array");
        exit(EXIT_FAILURE);
    }

    // Initialize all numbers as prime (true)
    for (int i = 2; i <= limit; i++) {
        is_prime[i] = true;
    }

    // Implement the Sieve of Eratosthenes
    for (int num = 2; num <= sqrt(limit); num++) {
        if (is_prime[num]) {
            // Mark multiples of the current number as non-prime
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }

    // Print the prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime[num]) {
            printf("%d ", num);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(is_prime);
}

int main(int argc, char *argv[]) {
    // Check for valid input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int limit = atoi(argv[1]);
    if (limit < 2) {
        fprintf(stderr, "Please enter a limit greater than 1.\n");
        return EXIT_FAILURE;
    }

    // Call the sieve function
    sieve_of_eratosthenes(limit);
    return EXIT_SUCCESS;
}
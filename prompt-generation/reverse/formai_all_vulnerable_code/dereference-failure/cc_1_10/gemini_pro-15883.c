//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_PRIME_COUNT 1000000

// Create a dynamic array to store prime numbers
size_t prime_count = 0;
unsigned int *primes = NULL;

// Function to check if a number is prime
bool is_prime(unsigned int n) {
    if (n == 1) {
        return false;
    }
    for (size_t i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate the first n prime numbers
void generate_primes(size_t n) {
    // Allocate memory for the prime array
    primes = malloc(n * sizeof(unsigned int));

    // If memory allocation failed, exit the program
    if (primes == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the first two prime numbers
    primes[0] = 2;
    primes[1] = 3;
    prime_count = 2;

    // Iterate through numbers starting from 5
    for (unsigned int i = 5; prime_count < n; i += 2) {
        // If the number is prime, add it to the array
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }
}

// Function to print the generated prime numbers
void print_primes() {
    printf("The first %zu prime numbers are:\n", prime_count);
    for (size_t i = 0; i < prime_count; i++) {
        printf("%u ", primes[i]);
    }
    printf("\n");
}

// Function to free the allocated memory
void cleanup() {
    free(primes);
}

int main() {
    // Get the number of prime numbers to generate from the user
    size_t n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%zu", &n);

    // Generate the prime numbers
    generate_primes(n);

    // Print the prime numbers
    print_primes();

    // Free the allocated memory
    cleanup();

    return EXIT_SUCCESS;
}
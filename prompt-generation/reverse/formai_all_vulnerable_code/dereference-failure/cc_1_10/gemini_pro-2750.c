//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
    int prime_count = 0;
    int* primes = (int*)malloc(sizeof(int) * limit);

    // Iterate through all numbers up to the limit
    for (int i = 2; i <= limit; i++) {
        // Check if the number is prime
        if (is_prime(i)) {
            // Add the prime number to the list
            primes[prime_count++] = i;
        }
    }

    // Return the list of prime numbers
    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    // Generate a list of prime numbers up to 100
    int* primes = generate_primes(100);

    // Print the list of prime numbers
    print_primes(primes, 100);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}
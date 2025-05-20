//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
int is_prime(int num);
void generate_primes(int limit);
void display_primes(int* primes, int count);

int main(int argc, char *argv[]) {
    int limit;

    // Check if the user provided an argument
    if (argc != 2) {
        printf("Usage: %s <upper_limit>\n", argv[0]);
        return 1;
    }

    // Convert the input argument to an integer
    limit = atoi(argv[1]);

    // Validate the input limit
    if (limit < 2) {
        printf("Please enter a positive integer greater than 1.\n");
        return 1;
    }

    printf("Generating prime numbers up to %d...\n", limit);
    generate_primes(limit);

    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2) return 0; // 0 and 1 are not prime numbers
    if (num == 2) return 1; // 2 is prime
    if (num % 2 == 0) return 0; // Exclude even numbers greater than 2

    // Check for factors from 3 to the square root of num
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0; // Found a factor, not prime
        }
    }
    return 1; // No factors found, it's prime
}

// Function to generate and display prime numbers up to a given limit
void generate_primes(int limit) {
    // Create an array to hold prime numbers
    int *primes = malloc(sizeof(int) * limit);
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    int count = 0; // Count of prime numbers

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num; // Store the prime number
        }
    }

    // Display the generated primes
    display_primes(primes, count);

    // Free allocated memory
    free(primes);
}

// Function to display the prime numbers
void display_primes(int* primes, int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}
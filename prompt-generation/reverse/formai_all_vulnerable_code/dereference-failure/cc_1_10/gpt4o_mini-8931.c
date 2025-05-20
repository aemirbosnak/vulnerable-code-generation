//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000  // Define the maximum number to consider for primes

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) { // Check divisibility from 2 to sqrt(num)
        if (num % i == 0) {
            return false; // Found a divisor, so num is not prime
        }
    }
    return true; // No divisors found, num is prime
}

// Function to generate and print prime numbers
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    printf("-------------------------------------------------\n");
    printf("   Prime Numbers\n");
    printf("-------------------------------------------------\n");
    
    for (int num = 2; num <= limit; num++) { // Start checking from 2
        if (is_prime(num)) {
            printf("   %d\n", num); // Print the prime number
        }
    }
    printf("-------------------------------------------------\n");
    printf("Prime generation completed.\n");
}

// Function to display usage information
void display_usage() {
    printf("Usage: ./prime_generator [limit]\n");
    printf("   Where [limit] is the maximum number to check for primality (up to %d).\n", MAX);
}

int main(int argc, char *argv[]) {
    int limit = MAX; // Default limit

    // Check for command line argument
    if (argc > 1) {
        limit = atoi(argv[1]); // Convert argument to integer
        if (limit > MAX || limit < 1) {
            printf("Error: Limit must be between 1 and %d.\n", MAX);
            display_usage();
            return 1; // Exit with error
        }
    }

    printf("-------------------------------------------------\n");
    printf("           RETRO C PRIME NUMBER GENERATOR       \n");
    printf("-------------------------------------------------\n");
    printf("Starting the prime number generation...\n");

    // Seed the random number generator (optional for this task)
    srand(time(NULL));
    
    // Generate primes up to the specified limit
    generate_primes(limit);

    return 0; // Successful run
}
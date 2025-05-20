//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void inputLimit(int* limit);
void sieveOfEratosthenes(int limit);
void displayPrimes(bool* isPrime, int limit);

int main() {
    int limit;

    // Get user input for the upper limit
    inputLimit(&limit);

    // Generate and display prime numbers using Sieve of Eratosthenes
    sieveOfEratosthenes(limit);

    return 0;
}

// Function to input the limit for prime number generation
void inputLimit(int* limit) {
    printf("Enter the upper limit for prime number generation: ");
    while (scanf("%d", limit) != 1 || *limit < 2) {
        printf("Please enter a valid limit greater than or equal to 2: ");
        while(getchar() != '\n'); // Clear invalid input
    }
}

// Function to implement Sieve of Eratosthenes
void sieveOfEratosthenes(int limit) {
    // Allocate memory for prime tracking array
    bool* isPrime = (bool*)malloc((limit + 1) * sizeof(bool));

    // Initialize all entries as true
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve algorithm to find primes
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            // Mark multiples of p as false
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    // Display the resultant primes
    displayPrimes(isPrime, limit);

    // Free allocated memory
    free(isPrime);
}

// Function to display prime numbers
void displayPrimes(bool* isPrime, int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
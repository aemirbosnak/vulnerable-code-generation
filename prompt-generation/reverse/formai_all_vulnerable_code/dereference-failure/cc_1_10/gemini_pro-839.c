//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Cyberpunk-esque prime number generator

// Data
int primeCount = 0;
int *primes = NULL;

// Declarations
void generatePrimes(int limit);
void printPrimes();
int isPrime(int num);

int main() {
    // Welcome message
    printf("**NEUROMANCER PRIME NUMBER GENERATOR**\n");
    printf("Initializing cyberdeck...\n");

    // Get limit from user
    int limit;
    printf("Enter the limit (in cyberspace): ");
    scanf("%d", &limit);

    // Generate primes
    generatePrimes(limit);

    // Print primes
    printf("Prime numbers found in the matrix:\n");
    printPrimes();

    // Logout message
    printf("Exiting cyberspace...\n");
    return 0;
}

void generatePrimes(int limit) {
    // Initialize primes array
    primes = malloc(sizeof(int) * limit);

    // Iterate over numbers up to the limit
    for (int num = 2; num <= limit; num++) {
        // Check if number is prime
        if (isPrime(num)) {
            // Add prime to array
            primes[primeCount++] = num;
        }
    }
}

void printPrimes() {
    // Iterate over primes array
    for (int i = 0; i < primeCount; i++) {
        // Print prime
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int isPrime(int num) {
    // Check if number is divisible by any number less than its square root
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
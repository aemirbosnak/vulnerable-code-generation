//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a list of prime numbers up to a given limit
int* generatePrimes(int limit) {
    // Allocate memory for the list of prime numbers
    int* primes = malloc(sizeof(int) * limit);

    // Initialize the list of prime numbers
    int primeCount = 0;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            primes[primeCount++] = i;
        }
    }

    // Return the list of prime numbers
    return primes;
}

// Function to print a list of prime numbers
void printPrimes(int* primes, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    // Generate a list of prime numbers up to 100
    int* primes = generatePrimes(100);

    // Print the list of prime numbers
    printPrimes(primes, 100);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PRIME_COUNT 100000 /* Maximum number of prime numbers to generate */

// Sieve of Eratosthenes algorithm to generate prime numbers
void sieveOfEratosthenes(bool *isPrime, int maxNumber) {
    // Initialize all numbers to true, except 0 and 1
    for (int i = 0; i <= maxNumber; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    // Iterate through all numbers from 2 to sqrt(maxNumber)
    for (int i = 2; i * i <= maxNumber; i++) {
        // If the number is prime
        if (isPrime[i]) {
            // Mark all multiples of the number as not prime
            for (int j = i * i; j <= maxNumber; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// Function to print the prime numbers
void printPrimes(bool *isPrime, int maxNumber) {
    // Iterate through all numbers from 2 to maxNumber
    for (int i = 2; i <= maxNumber; i++) {
        // If the number is prime, print it
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }
}

int main() {
    // Create an array to store whether each number is prime or not
    bool *isPrime = malloc(sizeof(bool) * (MAX_PRIME_COUNT + 1));

    // Generate prime numbers using the Sieve of Eratosthenes algorithm
    sieveOfEratosthenes(isPrime, MAX_PRIME_COUNT);

    // Print the prime numbers
    printPrimes(isPrime, MAX_PRIME_COUNT);

    // Free the memory allocated for the array
    free(isPrime);

    return 0;
}
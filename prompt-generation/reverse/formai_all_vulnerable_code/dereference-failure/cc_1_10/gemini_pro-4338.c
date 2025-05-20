//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate prime numbers up to a given limit
int* generatePrimes(int limit) {
    int* primes = malloc(sizeof(int) * limit);
    int numPrimes = 0;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            primes[numPrimes++] = i;
        }
    }
    return primes;
}

// Function to print an array of prime numbers
void printPrimes(int* primes, int numPrimes) {
    for (int i = 0; i < numPrimes; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    // Get the limit from the user
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Generate the prime numbers up to the limit
    int* primes = generatePrimes(limit);

    // Print the prime numbers
    printf("The prime numbers up to %d are: ", limit);
    printPrimes(primes, limit);

    // Free the memory allocated for the array of prime numbers
    free(primes);

    return 0;
}
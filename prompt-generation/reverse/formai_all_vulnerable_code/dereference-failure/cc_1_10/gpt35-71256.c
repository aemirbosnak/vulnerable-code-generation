//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is a prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate random numbers
int generateRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main() {
    // Initialize variables
    srand(time(NULL));
    int lowerBound = 2;
    int upperBound = 100;
    int maxNumbers = 10;
    int primesFound = 0;
    int *primes = (int*) malloc(sizeof(int) * maxNumbers);

    // Print initial information
    printf("Generating %d prime numbers between %d and %d\n", maxNumbers, lowerBound, upperBound);

    // Loop until desired number of prime numbers found
    while (primesFound < maxNumbers) {
        // Generate random number within specified bounds
        int num = generateRandomNumber(lowerBound, upperBound);
        // Check if number is prime and add to array if so
        if (isPrime(num)) {
            primes[primesFound] = num;
            primesFound++;
        }
    }

    // Print out all prime numbers found
    printf("Prime numbers generated: ");
    for (int i = 0; i < maxNumbers; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free memory allocated for primes array
    free(primes);

    return 0;
}
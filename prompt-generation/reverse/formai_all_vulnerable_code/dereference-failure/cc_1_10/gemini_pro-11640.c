//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
        i += 6;
    }

    return true;
}

// Function to generate prime numbers up to a given limit
int *generatePrimes(int limit) {
    int *primes = (int *)malloc(limit * sizeof(int));
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes[count++] = i;
        }
    }

    return primes;
}

// Function to print the prime numbers in an array
void printPrimes(int *primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the upper limit for prime number generation: ");
    scanf("%d", &limit);

    int *primes = generatePrimes(limit);
    int count = sizeof(primes) / sizeof(primes[0]);

    printf("The prime numbers up to %d are:\n", limit);
    printPrimes(primes, count);

    free(primes);
    return 0;
}
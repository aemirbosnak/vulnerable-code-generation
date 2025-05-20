//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum number of bits in the prime number
#define MAX_BITS 2048

// Define the number of primes to generate
#define NUM_PRIMES 10

// Define the number of iterations for the Miller-Rabin test
#define NUM_ITERATIONS 10

// Define the structure for a prime number
typedef struct {
    int bits;
    int value;
} Prime;

// Function prototypes
int isPrime(int n);
int millerRabin(int n);
int generatePrime(int bits);
void printPrime(Prime prime);

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the prime numbers
    Prime primes[NUM_PRIMES];
    for (int i = 0; i < NUM_PRIMES; i++) {
        primes[i].bits = MAX_BITS;
        primes[i].value = generatePrime(primes[i].bits);
    }

    // Print the prime numbers
    for (int i = 0; i < NUM_PRIMES; i++) {
        printPrime(primes[i]);
        printf("\n");
    }

    return 0;
}

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to generate a prime number of a given number of bits
int generatePrime(int bits) {
    int n = rand() % (1 << bits);
    while (!isPrime(n)) {
        n = rand() % (1 << bits);
    }

    return n;
}

// Function to print a prime number
void printPrime(Prime prime) {
    printf("Prime number: %d\n", prime.value);
    printf("Number of bits: %d\n", prime.bits);
}
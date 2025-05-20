//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Let's get excited about finding prime numbers, shall we?
    printf("Prepare yourself, folks! We're going on a prime number adventure!\n\n");

    // First, let's ask the user how many primes they want to see.
    int numPrimes;
    printf("How many prime numbers do you want to see? (Enter a number greater than 0): ");
    scanf("%d", &numPrimes);

    // Now, let's create an array to store our prime numbers.
    int *primes = malloc(sizeof(int) * numPrimes);

    // And let's set up some variables for our prime number calculations.
    int currentNumber = 2; // We start with 2 because it's the first prime number.
    int primeCount = 0; // We haven't found any primes yet.

    while (primeCount < numPrimes) {

        // Check if the current number is prime.
        int isPrime = 1; // Let's assume it's prime until proven otherwise.
        for (int i = 2; i <= currentNumber / 2; ++i) {
            if (currentNumber % i == 0) {
                // Oops, it's not prime.
                isPrime = 0;
                break;
            }
        }

        // If it's prime, let's add it to our array and count it.
        if (isPrime) {
            primes[primeCount] = currentNumber;
            primeCount++;
            printf("Prime number %d: %d\n", primeCount, currentNumber);
        }

        // Move on to the next number.
        currentNumber++;
    }

    // We've found all the primes we needed! Let's show them off.
    printf("\nHere are the first %d prime numbers:\n", numPrimes);
    for (int i = 0; i < numPrimes; ++i) {
        printf("%d  ", primes[i]);
    }

    printf("\n\nTa-da! We did it! We're prime number pros!\n");

    // Don't forget to clean up our memory.
    free(primes);

    return 0;
}
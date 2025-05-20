//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: active
// Prime Number Generator in C

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10000
#define MAX_ATTEMPTS 1000

int isPrime(int n);
int generateRandomPrime(int min, int max);

int main() {
    int i, numPrimes = 0;
    int *primes = (int*) malloc(MAX_NUMBERS * sizeof(int));
    int primeCount = 0;
    int maxAttempts = 0;

    srand(time(NULL));

    for (i = 2; i <= MAX_NUMBERS; i++) {
        if (isPrime(i)) {
            primes[primeCount++] = i;
        }
    }

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &numPrimes);

    for (i = 0; i < numPrimes; i++) {
        int prime = generateRandomPrime(2, MAX_NUMBERS);
        printf("%d ", prime);
    }

    free(primes);
    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int generateRandomPrime(int min, int max) {
    int attempts = 0;
    int prime = rand() % (max - min + 1) + min;

    while (!isPrime(prime) && attempts < MAX_ATTEMPTS) {
        prime = rand() % (max - min + 1) + min;
        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Failed to generate a prime number after %d attempts.\n", MAX_ATTEMPTS);
        exit(1);
    }

    return prime;
}
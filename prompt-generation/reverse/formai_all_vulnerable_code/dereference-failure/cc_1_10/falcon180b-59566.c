//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000
#define NUM_OF_PRIMES 1000

int isPrime(int n);
int generatePrime(int *prime, int numPrimes);
void printPrimes(int *prime, int numPrimes);

int main() {
    srand(time(NULL));
    int *primes = (int *) malloc(NUM_OF_PRIMES * sizeof(int));
    int numPrimes = generatePrime(primes, NUM_OF_PRIMES);
    printf("Found %d prime numbers:\n", numPrimes);
    printPrimes(primes, numPrimes);
    return 0;
}

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

int generatePrime(int *prime, int numPrimes) {
    int count = 0;
    while (count < numPrimes) {
        int num = rand() % MAX_NUM + 2;
        if (isPrime(num)) {
            prime[count] = num;
            count++;
        }
    }
    return count;
}

void printPrimes(int *prime, int numPrimes) {
    for (int i = 0; i < numPrimes; i++) {
        printf("%d ", prime[i]);
    }
    printf("\n");
}
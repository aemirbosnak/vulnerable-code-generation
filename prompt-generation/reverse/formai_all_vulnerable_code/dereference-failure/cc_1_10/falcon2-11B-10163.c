//Falcon2-11B DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 100; // Number of prime numbers to generate
    int primes[n];
    int count = 0;

    // Generate prime numbers using Sieve of Eratosthenes
    bool* isPrimeFlag = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) {
        isPrimeFlag[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        if (isPrimeFlag[p]) {
            for (int i = p * 2; i < n; i += p) {
                isPrimeFlag[i] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (isPrimeFlag[i]) {
            primes[count++] = i;
        }
    }

    // Print the generated prime numbers
    printf("Generated prime numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free memory allocated for prime flag
    free(isPrimeFlag);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate primes using the sieve algorithm
void generatePrimes(int n) {
    bool* isPrimeFlag = (bool*) malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++) {
        isPrimeFlag[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (isPrimeFlag[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrimeFlag[j] = false;
            }
        }
    }
    for (int i = 2; i < n; i++) {
        if (isPrimeFlag[i]) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    generatePrimes(n);
    printf("\n");
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n);
void sieveOfEratosthenes(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }

    printf("Prime numbers up to %d:\n", n);
    sieveOfEratosthenes(n);

    return 0;
}

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void sieveOfEratosthenes(int n) {
    int primes[n+1];
    int count = 0;

    for (int i = 2; i <= n; i++) {
        primes[i] = 1;
    }

    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == 1) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i] == 1) {
            printf("%d ", i);
            count++;
        }

        if (count == 10) {
            printf("\n");
            count = 0;
        }
    }
}
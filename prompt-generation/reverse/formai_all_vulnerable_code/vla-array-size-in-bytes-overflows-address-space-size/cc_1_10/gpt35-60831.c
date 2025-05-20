//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    } else if (n <= 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

int main() {
    int n;
    printf("Enter a number to find prime numbers up to: ");
    scanf("%d", &n);

    // Use Sieve of Eratosthenes algorithm to find primes up to n
    bool primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * 2; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    // Output prime numbers
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // Test isPrime function
    printf("Test isPrime function:\n");
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d is prime\n", i);
        } else {
            printf("%d is not prime\n", i);
        }
    }

    return 0;
}
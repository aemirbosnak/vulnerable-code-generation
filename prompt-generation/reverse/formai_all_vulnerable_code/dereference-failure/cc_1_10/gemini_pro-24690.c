//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    } else if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }

    return 1;
}

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
    int* primes = malloc(sizeof(int) * limit);
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }

    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int count) {
    printf("Primes up to %d:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int limit = 100;
    int* primes = generate_primes(limit);
    int count = 0;

    while (primes[count] != 0) {
        count++;
    }

    print_primes(primes, count);

    free(primes);

    return 0;
}
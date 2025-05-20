//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
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

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
    int* primes = malloc(sizeof(int) * limit);
    int num_primes = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[num_primes++] = i;
        }
    }
    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int num_primes) {
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int limit = 100;
    int* primes = generate_primes(limit);
    print_primes(primes, limit);
    free(primes);
    return 0;
}
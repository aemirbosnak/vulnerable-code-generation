//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a prime number
int generate_prime() {
    int n = rand() % 100000;
    while (!is_prime(n)) {
        n = rand() % 100000;
    }
    return n;
}

// Function to generate a list of prime numbers
int* generate_prime_list(int n) {
    int* primes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        primes[i] = generate_prime();
    }
    return primes;
}

// Function to print a list of prime numbers
void print_prime_list(int* primes, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d\n", primes[i]);
    }
}

// Driver function
int main() {
    // Generate a list of 100 prime numbers
    int* primes = generate_prime_list(100);

    // Print the list of prime numbers
    print_prime_list(primes, 100);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a list of prime numbers
int* generate_primes(int n) {
    int* primes = malloc(sizeof(int) * n);
    int count = 0;
    for (int i = 2; count < n; i++) {
        if (is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }
    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    // Generate a list of 100 prime numbers
    int* primes = generate_primes(100);

    // Print the list of prime numbers
    print_primes(primes, 100);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}
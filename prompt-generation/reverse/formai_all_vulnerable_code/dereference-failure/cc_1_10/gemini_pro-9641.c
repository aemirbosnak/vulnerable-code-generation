//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A dynamic array to store the prime numbers
int *primes;
int primes_size = 0;
int primes_capacity = 10;

// A function to check if a number is prime
int is_prime(int n) {
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

// A function to add a prime number to the array
void add_prime(int n) {
    // If the array is full, double its capacity
    if (primes_size == primes_capacity) {
        primes_capacity *= 2;
        primes = realloc(primes, primes_capacity * sizeof(int));
    }

    // Add the prime number to the array
    primes[primes_size++] = n;
}

// A function to generate the prime numbers up to a given number
void generate_primes(int n) {
    // Iterate over all the numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        // If the number is prime, add it to the array
        if (is_prime(i)) {
            add_prime(i);
        }
    }
}

// A function to print the prime numbers
void print_primes() {
    // Iterate over all the prime numbers in the array
    for (int i = 0; i < primes_size; i++) {
        // Print the prime number
        printf("%d ", primes[i]);
    }

    // Print a newline
    printf("\n");
}

// A function to free the memory allocated for the array
void free_primes() {
    free(primes);
}

// The main function
int main() {
    // Generate the prime numbers up to 1000
    generate_primes(1000);

    // Print the prime numbers
    print_primes();

    // Free the memory allocated for the array
    free_primes();

    return 0;
}
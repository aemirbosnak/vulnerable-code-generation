//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    } else if (n <= 3) {
        return true;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    // Check for divisibility by numbers up to the square root of n
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
    // Allocate memory for the list of prime numbers
    int* primes = malloc(sizeof(int) * limit);

    // Initialize the list of prime numbers
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }

    // Return the list of prime numbers
    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    // Generate a list of prime numbers up to 100
    int* primes = generate_primes(100);

    // Print the list of prime numbers
    print_primes(primes, 25);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    // Create an array to store the prime numbers
    int *primes = malloc(sizeof(int) * limit);

    // Initialize the array with the first two prime numbers
    primes[0] = 2;
    primes[1] = 3;

    // Initialize the current index in the array
    int index = 2;

    // Iterate over the numbers from 5 to the limit
    for (int i = 5; i <= limit; i += 2) {
        // Check if the number is prime
        if (is_prime(i)) {
            // Add the number to the array
            primes[index++] = i;
        }
    }

    // Print the prime numbers
    for (int i = 0; i < index; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free the memory allocated for the array
    free(primes);
}

// Driver function
int main() {
    // Generate prime numbers up to 100
    generate_primes(100);

    return 0;
}
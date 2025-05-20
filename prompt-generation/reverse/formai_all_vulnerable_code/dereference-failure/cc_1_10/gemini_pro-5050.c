//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    // If n is 1 or less, it is not prime
    if (n <= 1) {
        return 0;
    }

    // Iterate over all numbers from 2 to the square root of n
    for (int i = 2; i <= (int)sqrt(n); i++) {
        // If n is divisible by any number from 2 to its square root, it is not prime
        if (n % i == 0) {
            return 0;
        }
    }

    // If n is divisible by no number from 2 to its square root, it is prime
    return 1;
}

// Function to generate the first n prime numbers
int* generate_primes(int n) {
    // Allocate memory for an array of n prime numbers
    int* primes = (int*)malloc(n * sizeof(int));

    // Initialize the array with the first two prime numbers (2 and 3)
    primes[0] = 2;
    primes[1] = 3;

    // Iterate over all numbers from 4 to n, checking if each number is prime
    int i = 4;
    int num_primes = 2;
    while (num_primes < n) {
        // If the current number is prime, add it to the array
        if (is_prime(i)) {
            primes[num_primes] = i;
            num_primes++;
        }

        // Increment the current number
        i++;
    }

    // Return the array of prime numbers
    return primes;
}

// Main function
int main() {
    // Get the number of prime numbers to generate from the user
    int n;
    printf("How many prime numbers do you want to generate? ");
    scanf("%d", &n);

    // Generate the first n prime numbers
    int* primes = generate_primes(n);

    // Print the first n prime numbers
    printf("The first %d prime numbers are:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }

    // Free the memory allocated for the array of prime numbers
    free(primes);

    return 0;
}
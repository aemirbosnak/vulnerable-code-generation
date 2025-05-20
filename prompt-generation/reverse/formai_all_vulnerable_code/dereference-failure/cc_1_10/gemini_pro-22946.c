//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: expert-level
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// The Sieve of Eratosthenes is an ancient and efficient algorithm for finding all the prime numbers up to a given limit.
// The algorithm works by iteratively marking as composite (i.e., not prime) the multiples of each prime number, starting with the first prime number, 2.
// The algorithm terminates when there are no more unmarked numbers.

// The following C program implements the Sieve of Eratosthenes to find all the prime numbers up to a given limit.
// The program takes the limit as a command-line argument and prints the list of prime numbers to the standard output.

int main(int argc, char *argv[]) {
    // Check if the user has provided a valid command-line argument.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the command-line argument to an integer.
    int limit = atoi(argv[1]);

    // Create a boolean array to store the primality of numbers up to the given limit.
    bool *isPrime = malloc(sizeof(bool) * (limit + 1));

    // Initialize the boolean array to true.
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }

    // Mark as composite the multiples of each prime number.
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print the list of prime numbers.
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d\n", i);
        }
    }

    // Free the memory allocated for the boolean array.
    free(isPrime);

    return EXIT_SUCCESS;
}
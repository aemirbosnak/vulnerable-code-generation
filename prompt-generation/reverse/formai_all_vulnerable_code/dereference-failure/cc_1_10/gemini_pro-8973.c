//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Welcome the user
    printf("Welcome to the C Prime Number Generator!\n");
    printf("This program will generate a list of prime numbers up to a specified limit.\n");
    printf("Please enter the limit (a positive integer): ");

    // Get the limit from the user
    int limit;
    scanf("%d", &limit);

    // Create an array to store the prime numbers
    int *primes = malloc(sizeof(int) * limit);

    // Initialize the array
    for (int i = 0; i < limit; i++) {
        primes[i] = 0;
    }

    // Generate the prime numbers
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes[count++] = i;
        }
    }

    // Print the prime numbers
    printf("The prime numbers up to %d are:\n", limit);
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");

    // Free the array
    free(primes);

    return 0;
}
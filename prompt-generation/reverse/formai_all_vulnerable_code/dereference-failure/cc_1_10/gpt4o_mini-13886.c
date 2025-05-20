//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a constant for the maximum limit of prime numbers we wish to find
#define MAX_LIMIT 100

// Function prototypes
void find_primes(int limit);
bool is_prime(int number);
void display_primes(int primes[], int count);

int main() {
    // The great detective himself, Sherlock Holmes, embarks on a quest for prime numbers.
    printf("Ah, the splendid exercise of identifying prime numbers!\n");
    printf("I, Sherlock Holmes, shall now summon all primes up to %d.\n\n", MAX_LIMIT);

    // Invoking the prime number finder method
    find_primes(MAX_LIMIT);

    return 0;
}

// A function to find and gather prime numbers up to a specified limit
void find_primes(int limit) {
    int *primes = malloc(limit * sizeof(int)); // Dynamic array to store primes
    int count = 0;

    for (int number = 2; number <= limit; number++) { // Start from the first prime
        if (is_prime(number)) {
            primes[count++] = number; // Store prime number
            printf("[+] Found prime: %d\n", number);
        }
    }

    // Displaying the identified primes
    display_primes(primes, count);

    // Freeing allocated memory for primes
    free(primes);
}

// A function to check if a number is prime
bool is_prime(int number) {
    if (number < 2) return false; // Numbers less than 2 are not prime
    for (int i = 2; i * i <= number; i++) { // Check for factors up to sqrt(number)
        if (number % i == 0) {
            return false; // Not a prime if divisible by any number other than 1 and itself
        }
    }
    return true; // It is a prime number
}

// A function to display the gathered prime numbers in a refined manner
void display_primes(int primes[], int count) {
    printf("\nThe prime numbers I have deduced are:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n\nThe chase for prime numbers has indeed been exhilarating!\n");
    printf("Until we meet again, dear Watson.\n");
}
//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return;
    }

    printf("Generating prime numbers up to %d...\n", limit);
    printf("The prime numbers are:\n");

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to print the help menu
void print_help() {
    printf("\nPrime Number Generator Help:\n");
    printf("Usage: ./prime_generator <limit>\n");
    printf("Generate all prime numbers up to a specified limit.\n");
    printf("Example: ./prime_generator 100\n");
    printf("This will print all prime numbers from 2 to 100.\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid input!\n");
        print_help();
        return 1;
    }

    int limit = atoi(argv[1]);  // Convert input to integer
    if (limit <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        print_help();
        return 1;
    }

    generate_primes(limit);
    return 0;
}
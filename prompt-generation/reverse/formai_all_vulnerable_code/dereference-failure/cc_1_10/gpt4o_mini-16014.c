//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generatePrimes(int limit);
void printPrimes(bool *sieve, int limit);
void handleInput(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    handleInput(argc, argv);
    return 0;
}

void handleInput(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <limit>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int limit = atoi(argv[1]);
    if (limit < 2) {
        fprintf(stderr, "Please provide a limit of at least 2.\n");
        exit(EXIT_FAILURE);
    }

    generatePrimes(limit);
}

void generatePrimes(int limit) {
    bool *sieve = malloc((limit + 1) * sizeof(bool));
    if (sieve == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initial assumption: all numbers are prime
    for (int i = 0; i <= limit; i++) {
        sieve[i] = true;
    }
    
    sieve[0] = false; // 0 is not a prime number
    sieve[1] = false; // 1 is not a prime number

    // Implementing Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                sieve[multiple] = false; // Mark multiples as non-prime
            }
        }
    }

    printPrimes(sieve, limit);
    free(sieve); // Don't forget to free allocated memory!
}

void printPrimes(bool *sieve, int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (sieve[num]) {
            printf("%d ", num);
        }
    }
    printf("\n");
}
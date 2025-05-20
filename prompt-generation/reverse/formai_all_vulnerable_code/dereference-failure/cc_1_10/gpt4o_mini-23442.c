//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void printHelp() {
    printf("Prime Number Generator\n");
    printf("Usage: ./primegen [options] <limit>\n");
    printf("Options:\n");
    printf("  -h, --help    Show this help message\n");
    printf("  -s, --silent  Silent mode (do not print intermediate results)\n");
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    
    return true;
}

void generatePrimes(int limit, bool silent) {
    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            count++;
            if (!silent) {
                printf("%d ", num);
            }
        }
    }
    if (!silent) {
        printf("\nTotal primes found: %d\n", count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp();
        return EXIT_FAILURE;
    }

    bool silent = false;
    int limit = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printHelp();
            return EXIT_SUCCESS;
        } else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--silent") == 0) {
            silent = true;
        } else {
            limit = atoi(argv[i]);
            if (limit <= 0) {
                fprintf(stderr, "Error: Limit must be a positive integer.\n");
                return EXIT_FAILURE;
            }
        }
    }

    generatePrimes(limit, silent);
    return EXIT_SUCCESS;
}
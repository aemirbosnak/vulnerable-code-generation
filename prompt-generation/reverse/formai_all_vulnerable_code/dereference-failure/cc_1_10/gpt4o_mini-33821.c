//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void printUsage(const char *progName) {
    printf("Usage: %s <limit>\n", progName);
    printf("Generate prime numbers up to the specified limit.\n");
}

bool isPrime(int num) {
    if (num <= 1) return false; // 0 and 1 are not prime numbers
    if (num <= 3) return true;  // 2 and 3 are prime numbers

    if (num % 2 == 0 || num % 3 == 0) return false; // eliminate multiples of 2 and 3

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    int limit = atoi(argv[1]);
    if (limit < 0) {
        printf("Please enter a positive integer limit.\n");
        return EXIT_FAILURE;
    }

    generatePrimes(limit);

    return EXIT_SUCCESS;
}
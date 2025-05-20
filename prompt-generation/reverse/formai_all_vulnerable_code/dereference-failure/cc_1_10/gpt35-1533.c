//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000000

bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// The find_primes function returns the number of primes found in the given range.
int find_primes(int start, int end, bool *primes) {
    int count = 0;

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            primes[i] = true;
            count++;
        }
    }
    
    return count;
}

int main() {
    bool *primes = calloc(MAX_SIZE, sizeof(bool)); // initialize array of booleans to keep track of primes
    int count = find_primes(1, MAX_SIZE, primes); // find primes up to MAX_SIZE

    printf("Found %d primes up to %d\n", count, MAX_SIZE);

    // Print the first 100 primes found
    printf("The first 100 primes are:\n");
    int primes_printed = 0;
    for (int i = 2; i <= MAX_SIZE && primes_printed < 100; i++) {
        if (primes[i]) {
            printf("%d ", i);
            primes_printed++;
        }
    }
    printf("\n");

    free(primes);
    return 0;
}
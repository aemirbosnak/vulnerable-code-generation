//Falcon2-11B DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a list of primes
int* get_primes(int n) {
    int* primes = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        primes[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        if (is_prime(primes[i])) {
            continue;
        }
        int j = i;
        while (primes[j] % primes[i] == 0) {
            j++;
        }
        primes[i] = primes[j];
        primes[j] = i + 1;
    }
    return primes;
}

// Function to print primes
void print_primes(int* primes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

int main() {
    int n = 100; // Number of primes to generate
    int* primes = get_primes(n);
    print_primes(primes, n);
    free(primes);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BITS 2048

typedef struct {
    int num_bits;
    int *prime;
    int num_primes;
} PrimeSet;

void generate_prime(int num_bits, int *prime) {
    int is_prime = 1;
    int i = 2;
    while (is_prime && i <= num_bits / 2) {
        is_prime = 1;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        i++;
    }
    *prime = i;
}

void generate_primes(int num_bits, PrimeSet *primes) {
    primes->prime = malloc(num_bits * sizeof(int));
    primes->num_primes = 0;
    int prime;
    while (primes->num_primes < num_bits) {
        generate_prime(num_bits, &prime);
        if (prime > primes->prime[primes->num_primes - 1]) {
            primes->prime[primes->num_primes] = prime;
            primes->num_primes++;
        }
    }
}

void print_primes(PrimeSet primes, int num_primes) {
    for (int i = 0; i < num_primes; i++) {
        printf("%d ", primes.prime[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    PrimeSet primes;
    generate_primes(MAX_NUM_BITS, &primes);
    printf("Generated primes:\n");
    print_primes(primes, primes.num_primes);
    return 0;
}
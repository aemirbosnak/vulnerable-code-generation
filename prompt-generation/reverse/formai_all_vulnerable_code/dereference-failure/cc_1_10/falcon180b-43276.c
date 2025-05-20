//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_BITS 4096

typedef struct {
    int num_bits;
    int *primes;
    int num_primes;
} PrimeSet;

int is_prime(int n) {
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    int sqrt_n = sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

PrimeSet* generate_primes(int num_bits) {
    PrimeSet *primes = malloc(sizeof(PrimeSet));
    primes->num_bits = num_bits;
    primes->primes = malloc(sizeof(int) * num_bits);
    primes->num_primes = 0;

    for (int i = 2; i < num_bits; i++) {
        if (is_prime(i)) {
            primes->primes[primes->num_primes++] = i;
        }
    }

    return primes;
}

int* generate_random_numbers(PrimeSet *primes, int num_bits) {
    int *numbers = malloc(sizeof(int) * num_bits);

    for (int i = 0; i < num_bits; i++) {
        numbers[i] = rand() % primes->num_bits;
    }

    return numbers;
}

void print_numbers(int *numbers, int num_bits) {
    for (int i = 0; i < num_bits; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    PrimeSet *primes = generate_primes(MAX_NUM_BITS);
    int *numbers = generate_random_numbers(primes, MAX_NUM_BITS);

    printf("Prime numbers:\n");
    for (int i = 0; i < primes->num_primes; i++) {
        printf("%d ", primes->primes[i]);
    }
    printf("\n");

    printf("Random numbers:\n");
    print_numbers(numbers, MAX_NUM_BITS);

    free(primes->primes);
    free(primes);
    free(numbers);

    return 0;
}
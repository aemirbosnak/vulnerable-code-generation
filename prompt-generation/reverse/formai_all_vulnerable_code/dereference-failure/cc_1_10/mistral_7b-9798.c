//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PRIMES 1000
#define SQUARE_ROOT_MAX 17
#define BUFFER_SIZE 1024
#define ELEMENT_SIZE sizeof(bool)

typedef struct {
    bool *elements;
    size_t size;
} Sieve;

void sieve_init(Sieve *sieve, size_t size) {
    sieve->elements = calloc(size, ELEMENT_SIZE);
    sieve->size = size;
    for (size_t i = 0; i < size; ++i) {
        sieve->elements[i] = true;
    }
}

void sieve_erase(Sieve *sieve, size_t index) {
    if (index >= sieve->size) {
        fprintf(stderr, "Invalid index\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = index * 2; i < sieve->size; i += index) {
        sieve->elements[i] = false;
    }
}

bool is_prime(Sieve *sieve, size_t number) {
    if (number < 2) {
        return false;
    }
    if (sieve->elements[number] == false) {
        return false;
    }
    for (size_t i = 2; i * i <= number; ++i) {
        if (!sieve->elements[i] || number % i != 0) {
            continue;
        }
        sieve_erase(sieve, i);
        return false;
    }
    return true;
}

void sieve_generate_primes(Sieve *sieve) {
    sieve_init(sieve, MAX_PRIMES);
    for (size_t i = 0; i < SQUARE_ROOT_MAX; ++i) {
        if (sieve->elements[i]) {
            for (size_t j = i * i; j < MAX_PRIMES; j += i * 2) {
                sieve_erase(sieve, j);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Sieve prime_sieve;
    sieve_generate_primes(&prime_sieve);

    printf("The Enchanted Forest of Numbers\n");
    printf("Enter the depth of the forest (up to %d): ", MAX_PRIMES);
    size_t forest_depth = 0;
    scanf("%zu", &forest_depth);

    if (forest_depth > MAX_PRIMES) {
        printf("Error: The forest cannot be deeper than %d.\n", MAX_PRIMES);
        return EXIT_FAILURE;
    }

    printf("The prime numbers in your forest are:\n");
    char prime_numbers_buffer[BUFFER_SIZE];

    for (size_t i = 0; i < forest_depth && i < MAX_PRIMES; ++i) {
        if (!is_prime(&prime_sieve, i)) {
            continue;
        }
        snprintf(prime_numbers_buffer, BUFFER_SIZE, "%zu%s", i,
            (i + 1 < forest_depth || i + 1 >= MAX_PRIMES) ? "\n" : "");
        printf("%s", prime_numbers_buffer);
    }

    free(prime_sieve.elements);
    return EXIT_SUCCESS;
}
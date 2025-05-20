//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BITS_IN_WORD 32

struct bit_array {
    size_t nwords;
    unsigned int* words;
};

struct bit_array* bit_array_new(size_t n) {
    struct bit_array* ba = malloc(sizeof(struct bit_array));
    if (ba == NULL) {
        return NULL;
    }

    ba->nwords = (n + BITS_IN_WORD - 1) / BITS_IN_WORD;
    ba->words = malloc(sizeof(unsigned int) * ba->nwords);
    if (ba->words == NULL) {
        free(ba);
        return NULL;
    }

    for (size_t i = 0; i < ba->nwords; i++) {
        ba->words[i] = 0;
    }

    return ba;
}

void bit_array_delete(struct bit_array* ba) {
    free(ba->words);
    free(ba);
}

static inline bool bit_array_get(struct bit_array* ba, size_t i) {
    size_t word_index = i / BITS_IN_WORD;
    size_t bit_index = i % BITS_IN_WORD;
    return (ba->words[word_index] & (1 << bit_index)) != 0;
}

static inline void bit_array_set(struct bit_array* ba, size_t i, bool value) {
    size_t word_index = i / BITS_IN_WORD;
    size_t bit_index = i % BITS_IN_WORD;
    if (value) {
        ba->words[word_index] |= (1 << bit_index);
    } else {
        ba->words[word_index] &= ~(1 << bit_index);
    }
}

void sieve_of_eratosthenes(struct bit_array* ba, size_t n) {
    bit_array_set(ba, 0, true);
    bit_array_set(ba, 1, true);

    for (size_t i = 2; i * i <= n; i++) {
        if (!bit_array_get(ba, i)) {
            for (size_t j = i * i; j <= n; j += i) {
                bit_array_set(ba, j, true);
            }
        }
    }
}

void print_primes(struct bit_array* ba, size_t n) {
    for (size_t i = 2; i <= n; i++) {
        if (!bit_array_get(ba, i)) {
            printf("%zu ", i);
        }
    }

    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t n = atoi(argv[1]);

    struct bit_array* ba = bit_array_new(n);
    if (ba == NULL) {
        fprintf(stderr, "Could not allocate memory for bit array\n");
        return EXIT_FAILURE;
    }

    sieve_of_eratosthenes(ba, n);
    print_primes(ba, n);

    bit_array_delete(ba);

    return EXIT_SUCCESS;
}
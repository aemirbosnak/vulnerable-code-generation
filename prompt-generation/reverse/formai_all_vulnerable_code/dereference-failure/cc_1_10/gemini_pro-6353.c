//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define PRIME_COUNT 1000000

typedef struct {
    size_t count;
    size_t size;
    uint64_t *primes;
} prime_list;

static prime_list *prime_list_init(size_t initial_size) {
    prime_list *pl = calloc(1, sizeof(prime_list));
    if (pl == NULL) {
        fprintf(stderr, "Error: calloc() failed: %s\n", strerror(errno));
        return NULL;
    }
    pl->size = initial_size;
    pl->primes = calloc(pl->size, sizeof(uint64_t));
    if (pl->primes == NULL) {
        fprintf(stderr, "Error: calloc() failed: %s\n", strerror(errno));
        free(pl);
        return NULL;
    }
    pl->count = 0;
    return pl;
}

static void prime_list_free(prime_list *pl) {
    free(pl->primes);
    free(pl);
}

static int prime_list_add(prime_list *pl, uint64_t prime) {
    if (pl->count == pl->size) {
        pl->size *= 2;
        uint64_t *new_primes = realloc(pl->primes, pl->size * sizeof(uint64_t));
        if (new_primes == NULL) {
            fprintf(stderr, "Error: realloc() failed: %s\n", strerror(errno));
            return -1;
        }
        pl->primes = new_primes;
    }
    pl->primes[pl->count++] = prime;
    return 0;
}

static int prime_list_print(prime_list *pl, FILE *fp) {
    for (size_t i = 0; i < pl->count; i++) {
        fprintf(fp, "%llu\n", pl->primes[i]);
    }
    return 0;
}

static int prime_list_generate(prime_list *pl, size_t count) {
    if (count > PRIME_COUNT) {
        fprintf(stderr, "Error: count must be less than or equal to PRIME_COUNT (%lu)\n", PRIME_COUNT);
        return -1;
    }

    uint64_t sieve_size = (uint64_t)ceil(sqrt(PRIME_COUNT));
    bool *sieve = calloc(sieve_size, sizeof(bool));
    if (sieve == NULL) {
        fprintf(stderr, "Error: calloc() failed: %s\n", strerror(errno));
        return -1;
    }

    prime_list_add(pl, 2);

    for (uint64_t i = 3; i <= sieve_size; i += 2) {
        if (!sieve[i]) {
            prime_list_add(pl, i);
            for (uint64_t j = i * i; j <= sieve_size; j += i) {
                sieve[j] = true;
            }
        }
    }

    for (uint64_t i = (sieve_size + 1) / 2; i <= PRIME_COUNT; i += 2) {
        if (!sieve[i]) {
            prime_list_add(pl, i);
        }
    }

    free(sieve);

    if (pl->count != count) {
        fprintf(stderr, "Error: failed to generate %lu primes (generated %lu)\n", count, pl->count);
        return -1;
    }

    return 0;
}

int main() {
    prime_list *pl = prime_list_init(100);
    if (pl == NULL) {
        return EXIT_FAILURE;
    }

    if (prime_list_generate(pl, PRIME_COUNT) != 0) {
        prime_list_free(pl);
        return EXIT_FAILURE;
    }

    if (prime_list_print(pl, stdout) != 0) {
        prime_list_free(pl);
        return EXIT_FAILURE;
    }

    prime_list_free(pl);

    return EXIT_SUCCESS;
}
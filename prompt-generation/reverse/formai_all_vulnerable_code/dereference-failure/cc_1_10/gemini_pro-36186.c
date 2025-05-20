//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static const  uint64_t SMALL_PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
static const size_t SMALL_PRIMES_COUNT = sizeof(SMALL_PRIMES) / sizeof(*SMALL_PRIMES);
static const uint8_t SIEVE_SIZE = 4096;
static const uint8_t SIEVE_BYTE_SIZE = SIEVE_SIZE / 8;
#define BIT_MASK(byte) (1 << (7 - ((byte) % 8)))

static inline bool is_prime(uint64_t num) {

    if (num < SMALL_PRIMES[SMALL_PRIMES_COUNT - 1]) {
        for (size_t i = 0; i < SMALL_PRIMES_COUNT; i++) {
            if (num == SMALL_PRIMES[i]) {
                return true;
            } else if (num % SMALL_PRIMES[i] == 0) {
                return false;
            }
        }
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    const uint64_t first_odd_multiple = 5;
    const uint64_t odd_increment = 6;
    for (uint64_t i = first_odd_multiple; i * i <= num; i += odd_increment) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

static bool is_prime_fast(uint64_t num, const uint8_t *sieve) {

    if (num < SMALL_PRIMES[SMALL_PRIMES_COUNT - 1]) {
        for (size_t i = 0; i < SMALL_PRIMES_COUNT; i++) {
            if (num == SMALL_PRIMES[i]) {
                return true;
            }
        }
        return false;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    const uint64_t first_odd_multiple = 5;
    const uint64_t odd_increment = 6;
    const size_t bucket_index = num >> 6;
    for (uint64_t i = first_odd_multiple; i * i <= num; i += odd_increment) {
        if (sieve[bucket_index] & BIT_MASK(num % i) || sieve[bucket_index] & BIT_MASK((num % i) + 2)) {
            return false;
        }
    }

    return true;
}

void sieve_of_eratosthenes(uint8_t *sieve, size_t sieve_size) {

    sieve[0] = sieve[1] = 0;
    for (size_t i = 2; i < sieve_size; i++) {
        sieve[i] = 0xff;
    }

    size_t prime = 2;
    while (prime * prime < sieve_size) {
        if (sieve[prime >> 3] & BIT_MASK(prime % 8)) {
            for (size_t i = (prime * prime) >> 3; i < sieve_size; i += prime >> 3) {
                sieve[i] &= ~BIT_MASK(prime % 8);
            }
        }
        prime += 1;
        while (prime < sieve_size && !(sieve[prime >> 3] & BIT_MASK(prime % 8))) {
            prime += 1;
        }
    }
}

bool sieve_prime(uint64_t num, const uint8_t *sieve) {

    if (num < SMALL_PRIMES[SMALL_PRIMES_COUNT - 1]) {
        for (size_t i = 0; i < SMALL_PRIMES_COUNT; i++) {
            if (num == SMALL_PRIMES[i]) {
                return true;
            }
        }
        return false;
    }

    const size_t bucket_index = num >> 6;
    return sieve[bucket_index] & BIT_MASK(num % 8);
}

void generate_primes(size_t num_primes, const char *output_file) {

    FILE *fp = fopen(output_file, "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    uint8_t sieve[SIEVE_BYTE_SIZE];
    sieve_of_eratosthenes(sieve, SIEVE_SIZE);

    fprintf(fp, "2");
    size_t count = 1;
    for (uint64_t i = 3; count < num_primes; i += 2) {
        if (sieve_prime(i, sieve)) {
            fprintf(fp, ", %lu", i);
            count += 1;
        }
    }
    fclose(fp);
}

int main() {

    generate_primes(100, "primes.txt");
    return 0;
}
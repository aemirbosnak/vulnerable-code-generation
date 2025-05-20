//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_PRIMES 1000000
#define LIMIT (sqrt(MAX_PRIMES) + 1)
#define SIZE (LIMIT + (LIMIT / 2))

bool *sieve;

void sieve_init() {
    int i;
    sieve = malloc(sizeof(bool) * SIZE);

    for (i = 0; i < SIZE; i++) {
        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;
}

void sieve_erase(int index) {
    int i;

    if (index >= SIZE || index < 0) {
        return;
    }

    if (sieve[index] == false) {
        return;
    }

    for (i = index * index; i < SIZE; i += index) {
        sieve[i] = false;
    }
}

int main() {
    int i, j, limit, count = 0;
    int prime[MAX_PRIMES];

    sieve_init();

    limit = 2;

    while (count < MAX_PRIMES) {
        if (sieve[limit] == true) {
            prime[count] = limit;
            count++;
            sieve_erase(limit);
        }

        for (i = limit + limit; i < SIZE; i += limit) {
            sieve[i] = false;
        }

        for (j = limit - 2; j > 0; j -= 2) {
            if (limit % j == 0) {
                break;
            }
        }

        if (j == 0) {
            limit += limit;
        } else {
            limit++;
        }
    }

    for (i = 0; i < MAX_PRIMES; i++) {
        printf("%d ", prime[i]);
    }

    printf("\n");

    free(sieve);

    return 0;
}
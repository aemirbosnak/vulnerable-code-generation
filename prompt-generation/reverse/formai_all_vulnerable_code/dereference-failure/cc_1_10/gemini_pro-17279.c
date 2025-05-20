//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int n, i, j, k, l, count = 0;
    char *primes;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);
    if (n <= 1) {
        fprintf(stderr, "Error: invalid number\n");
        return EXIT_FAILURE;
    }

    primes = (char *)malloc(n * sizeof(char));
    if (primes == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return EXIT_FAILURE;
    }

    memset(primes, 1, n * sizeof(char));

    for (i = 2; i <= (int)sqrt((double)n); i++) {
        if (primes[i]) {
            for (j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }

    printf("Prime numbers up to %d:\n", n);
    for (i = 2; i <= n; i++) {
        if (primes[i]) {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal prime numbers: %d\n", count);

    free(primes);

    return EXIT_SUCCESS;
}
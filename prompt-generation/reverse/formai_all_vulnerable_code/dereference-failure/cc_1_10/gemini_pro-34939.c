//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <lower bound> <upper bound>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int lower_bound = atoi(argv[1]);
    int upper_bound = atoi(argv[2]);

    if (lower_bound < 2) {
        fprintf(stderr, "Lower bound must be greater than or equal to 2\n");
        return EXIT_FAILURE;
    }

    if (upper_bound < lower_bound) {
        fprintf(stderr, "Upper bound must be greater than or equal to lower bound\n");
        return EXIT_FAILURE;
    }

    int *primes = malloc((upper_bound - lower_bound + 1) * sizeof(int));
    if (primes == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    int num_primes = 0;

    for (int i = lower_bound; i <= upper_bound; i++) {
        int is_prime = 1;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            primes[num_primes++] = i;
        }
    }

    printf("Prime numbers between %d and %d:\n", lower_bound, upper_bound);
    for (int i = 0; i < num_primes; i++) {
        printf("%d\n", primes[i]);
    }

    free(primes);

    return EXIT_SUCCESS;
}
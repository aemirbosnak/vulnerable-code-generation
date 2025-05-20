//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void generate_primes(int num, int count, int* primes, int* p_count) {
    if (*p_count >= count) {
        printf("Generated %d prime numbers: \n", count);
        for (int i = 0; i < *p_count; i++) {
            printf("%d ", primes[i]);
        }
        printf("\n");
        exit(EXIT_SUCCESS);
    }

    if (is_prime(num)) {
        primes[*p_count] = num;
        generate_primes(num + 1, count, primes, p_count);
    } else {
        generate_primes(num + 1, count, primes, p_count);
    }
}

int main() {
    int count;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &count);

    int* primes = (int*) calloc(count, sizeof(int));
    int p_count = 0;

    generate_primes(2, count, primes, &p_count);

    free(primes);

    return EXIT_SUCCESS;
}
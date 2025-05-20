//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    int number;
    char name[20];
} prime_number;

void generate_prime(prime_number *prime, int limit) {
    int i, j, is_prime = 1;

    for (i = 2; i <= limit; i++) {
        prime[prime->number].number = i;
        strcpy(prime[prime->number].name, "Love");
        prime->number++;

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime) {
            prime[prime->number].number = i;
            strcpy(prime[prime->number].name, "Prime");
            prime->number++;
        }

        is_prime = 1;
    }
}

int main() {
    prime_number prime[100];
    int limit = 1000;

    clock_t start = clock();
    generate_prime(prime, limit);
    clock_t end = clock();

    printf("Generated %d prime numbers up to %d.\n", prime->number - 1, limit);
    printf("This took %.2fs.\n", (float)(end - start) / CLOCKS_PER_SEC);

    int i;
    for (i = 0; i < prime->number - 1; i++) {
        if (prime[i].number % 2 == 0 && prime[i].number > 2) {
            printf("%d (%s) is a romantic even prime number.\n", prime[i].number, prime[i].name);
        } else if (prime[i].number > 2) {
            printf("%d (%s) is a romantic odd prime number.\n", prime[i].number, prime[i].name);
        }
    }

    return 0;
}
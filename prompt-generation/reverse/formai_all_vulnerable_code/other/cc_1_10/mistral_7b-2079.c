//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000001

typedef struct {
    int num;
    bool prime;
} number;

void sieve_of_eratosthenes(number *arr) {
    int n = MAX + 1;
    memset(arr, true, sizeof(number) * n);

    arr[0].prime = false;
    arr[1].prime = false;

    for (int i = 2; i * i <= n; i++) {
        if (arr[i].prime) {
            for (int j = i * i; j <= n; j += i) {
                arr[j].prime = false;
            }
        }
    }
}

int main() {
    number primes[MAX];

    printf("Calculating prime numbers using the Sieve of Eratosthenes algorithm...\n");
    clock_t start = clock();
    sieve_of_eratosthenes(primes);
    clock_t end = clock();

    printf("Prime numbers up to %d:\n", MAX);
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (primes[i].prime) {
            printf("%d ", primes[i].num);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    printf("\nTime taken to calculate prime numbers: %f seconds\n", (float)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
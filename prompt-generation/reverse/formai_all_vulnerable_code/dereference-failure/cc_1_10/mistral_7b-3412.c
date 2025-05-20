//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#define MAX_PRIME 10000

typedef struct {
    int num;
    bool isPrime;
} PrimeNumber;

void sieveOfEratosthenes(PrimeNumber *numbers, int limit) {
    int i, j;
    for (i = 0; i < limit; i++) {
        numbers[i].num = i;
        numbers[i].isPrime = true;
    }
    numbers[0].isPrime = false;
    for (i = 2; i * i <= limit; i++) {
        if (numbers[i].isPrime) {
            for (j = i * i; j <= limit; j += i) {
                numbers[j].isPrime = false;
            }
        }
    }
}

int main() {
    int size = (MAX_PRIME + 1) * sizeof(PrimeNumber);
    PrimeNumber *numbers = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (numbers == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    sieveOfEratosthenes(numbers, MAX_PRIME);

    int count = 0;
    for (int i = 0; i < MAX_PRIME; i++) {
        if (numbers[i].isPrime) {
            printf("%d ", numbers[i].num);
            count++;
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    printf("\nNumber of prime numbers below %d: %d\n", MAX_PRIME, count);

    munmap(numbers, size);

    return 0;
}
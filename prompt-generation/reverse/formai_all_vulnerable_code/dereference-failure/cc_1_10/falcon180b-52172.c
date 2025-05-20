//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int main() {
    int num, i, j, is_prime;
    int *prime_numbers;
    int count = 0;
    int max_prime_num = 0;
    time_t start_time, end_time;

    srand(time(NULL));
    prime_numbers = (int*)malloc(MAX_NUM * sizeof(int));

    printf("Generating prime numbers...\n");
    fflush(stdout);

    for (num = 2; count < MAX_NUM; num++) {
        is_prime = 1;
        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            prime_numbers[count] = num;
            count++;
        }
    }

    printf("Found %d prime numbers.\n", count);
    fflush(stdout);

    start_time = clock();
    for (i = 0; i < count; i++) {
        for (j = i+1; j < count; j++) {
            if (prime_numbers[i] == prime_numbers[j]) {
                printf("Duplicate prime number found: %d\n", prime_numbers[i]);
                fflush(stdout);
            }
        }
    }
    end_time = clock();
    printf("Time taken: %.6f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    fflush(stdout);

    free(prime_numbers);
    return 0;
}
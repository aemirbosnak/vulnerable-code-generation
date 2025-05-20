//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000

int is_prime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int i, j, count = 0, prime_count = 0;
    int *primes;
    double avg_gap, curr_gap = 0.0;
    clock_t start_time, end_time;

    srand(time(NULL));

    primes = (int *)malloc(MAX_NUM * sizeof(int));

    for (i = 2; i <= MAX_NUM; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &j);

    start_time = clock();
    for (i = 0; i < j; i++) {
        count++;
        while (!is_prime(count)) {
            count++;
        }
        printf("%d ", count);
        if (i % 100 == 99) {
            end_time = clock();
            avg_gap = (double)curr_gap / 100;
            printf("\nAverage gap between prime numbers: %.2lf\n", avg_gap);
            curr_gap = 0.0;
        }
    }
    end_time = clock();
    avg_gap = (double)curr_gap / (j % 100? j % 100 : 100);

    printf("\nTotal prime numbers generated: %d\n", j);
    printf("Average gap between prime numbers: %.2lf\n", avg_gap);

    free(primes);
    return 0;
}
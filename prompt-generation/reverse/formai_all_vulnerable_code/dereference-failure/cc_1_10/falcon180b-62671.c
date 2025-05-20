//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000000
#define TRUE 1
#define FALSE 0

int is_prime(int n);

int main() {
    int i, j, count = 0, max_count = 0;
    int prime[MAX];
    int *ptr;
    int seed;
    struct tm *tm;
    time_t t;

    srand((unsigned)time(&t));
    t = t % 1000000000;
    tm = localtime(&t);
    seed = tm->tm_sec + tm->tm_min * 60 + tm->tm_hour * 3600;

    for (i = 2; i <= MAX; i++) {
        if (is_prime(i)) {
            prime[count++] = i;
            if (count > max_count) {
                max_count = count;
            }
        }
    }

    printf("The maximum number of prime numbers found is %d.\n", max_count);

    for (i = 0; i < max_count; i++) {
        printf("%d ", prime[i]);
    }

    return 0;
}

int is_prime(int n) {
    int i;

    if (n <= 1) {
        return FALSE;
    }

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return FALSE;
        }
    }

    return TRUE;
}
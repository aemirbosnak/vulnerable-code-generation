//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000000
#define M 1000
#define K 100

int main(void)
{
    int i, j, k, n, m, sum;
    double start, end, elapsed;
    int *a, *b, *c;

    a = (int *) malloc(N * sizeof(int));
    b = (int *) malloc(M * sizeof(int));
    c = (int *) malloc(K * sizeof(int));

    for (i = 0; i < N; i++)
        a[i] = rand() % 1000;

    for (i = 0; i < M; i++)
        b[i] = rand() % 1000;

    for (i = 0; i < K; i++)
        c[i] = rand() % 1000;

    start = clock();

    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < M; j++) {
            if (a[i] == b[j]) {
                sum++;
            }
        }
        c[sum % K] += 1;
    }

    end = clock();
    elapsed = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Elapsed time: %lf seconds\n", elapsed);

    free(a);
    free(b);
    free(c);

    return 0;
}
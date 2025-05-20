//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10;
    int m = 5;
    int i, j;
    int *a, *b, *c;

    srand(time(0));

    // Generate random matrices
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 10;
    }

    b = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        b[i] = rand() % 10;
    }

    // Perform matrix multiplication
    c = (int *)malloc(n * m * sizeof(int));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i * m + j] = 0;
            for (int k = 0; k < n; k++) {
                c[i * m + j] += a[i * n + k] * b[k * m + j];
            }
        }
    }

    // Print the result
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i * m + j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(a);
    free(b);
    free(c);

    return 0;
}
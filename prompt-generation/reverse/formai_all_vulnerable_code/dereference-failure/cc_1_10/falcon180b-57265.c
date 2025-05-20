//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main() {
    int i, j, n;
    int **matrix1, **matrix2, **result;
    clock_t start, end;
    double cpu_time_used;

    // Initialize matrices
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    // Start timer
    start = clock();

    // Matrix multiplication
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (n = 0; n < SIZE; n++) {
                result[i][j] += matrix1[i][n] * matrix2[n][j];
            }
        }
    }

    // Stop timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print result
    printf("Result:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Print time used
    printf("Time used: %.2f seconds\n", cpu_time_used);

    return 0;
}
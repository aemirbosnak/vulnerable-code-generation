//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define N 1000000

int main() {
    int i, j, k;
    struct timeval start, stop;
    double elapsed;

    // Initialize the matrix
    int **a = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        a[i] = (int *) malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            a[i][j] = rand() % 100;
        }
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Perform the matrix multiplication
    int **b = (int **) malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        b[i] = (int *) malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            b[i][j] = 0;
            for (k = 0; k < N; k++) {
                b[i][j] += a[i][k] * a[k][j];
            }
        }
    }

    // Stop the timer
    gettimeofday(&stop, NULL);

    // Calculate the elapsed time
    elapsed = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;

    // Print the elapsed time
    printf("Elapsed time: %f seconds\n", elapsed);

    // Free the memory
    for (i = 0; i < N; i++) {
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

int main() {
    int i, j, k;
    int **matrix;
    int *vector;
    int *result;
    double start, end;

    // Allocate memory for the matrix, vector and result
    matrix = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        matrix[i] = (int *)malloc(SIZE * sizeof(int));
    }
    vector = (int *)malloc(SIZE * sizeof(int));
    result = (int *)malloc(SIZE * sizeof(int));

    // Initialize the matrix and vector with random integers
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < SIZE; i++) {
        vector[i] = rand() % 100;
    }

    // Calculate the product of the matrix and vector
    start = clock();
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    end = clock();

    // Print the result and the time taken to compute it
    printf("Result:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Free the memory allocated for the matrix, vector and result
    for (i = 0; i < SIZE; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
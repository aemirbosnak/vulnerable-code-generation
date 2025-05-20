//FormAI DATASET v1.0 Category: Benchmarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform the benchmarking
void performBenchmarking(int size) {
    int i, j, k;
    int **matrix1, **matrix2, **resultMatrix;

    // Initializing the matrices and the result matrix with random values
    matrix1 = (int **) malloc(sizeof(int *) * size);
    matrix2 = (int **) malloc(sizeof(int *) * size);
    resultMatrix = (int **) malloc(sizeof(int *) * size);

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        matrix1[i] = (int *) malloc(sizeof(int) * size);
        matrix2[i] = (int *) malloc(sizeof(int) * size);
        resultMatrix[i] = (int *) malloc(sizeof(int) * size);
        for (j = 0; j < size; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
            resultMatrix[i][j] = 0;
        }
    }

    // Performing the multiplication and calculating the time taken
    clock_t start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            for (k = 0; k < size; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    clock_t end = clock();
    double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Printing the size and time taken for the benchmarking
    printf("Benchmarking for size %d: %lf seconds\n", size, timeTaken);

    // Freeing the dynamically allocated memory
    for (i = 0; i < size; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(resultMatrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(resultMatrix);
}

// Main function
int main() {
    int sizes[] = {100, 500, 1000, 5000, 10000};

    // Performing the benchmarking for different sizes
    for (int i = 0; i < 5; i++) {
        performBenchmarking(sizes[i]);
    }

    return 0;
}
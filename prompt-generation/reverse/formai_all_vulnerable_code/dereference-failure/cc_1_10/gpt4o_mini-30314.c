//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 512 // Size of the matrices. You can change this for performance testing.

// Function to multiply two matrices
void matrixMultiply(int *a, int *b, int *result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(result + i * size + j) = 0; // Initialize the result
            for (int k = 0; k < size; k++) {
                *(result + i * size + j) += *(a + i * size + k) * *(b + k * size + j);
            }
        }
    }
}

// Function to initialize a matrix with random values
void initializeMatrix(int *matrix, int size) {
    for (int i = 0; i < size * size; i++) {
        *(matrix + i) = rand() % 10; // Random values between 0 and 9
    }
}

// Function to print a matrix (for debugging purpose, but can be commented out for performance tests)
void printMatrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(matrix + i * size + j));
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    // Allocate memory for matrices
    int *matrixA = (int *)malloc(SIZE * SIZE * sizeof(int));
    int *matrixB = (int *)malloc(SIZE * SIZE * sizeof(int));
    int *resultMatrix = (int *)malloc(SIZE * SIZE * sizeof(int));

    if (!matrixA || !matrixB || !resultMatrix) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Initialize matrices A and B
    initializeMatrix(matrixA, SIZE);
    initializeMatrix(matrixB, SIZE);

    // Uncomment the next line to print the matrices before multiplication
    // printMatrix(matrixA, SIZE);
    // printMatrix(matrixB, SIZE);

    // Measure time taken for matrix multiplication
    clock_t start = clock();
    matrixMultiply(matrixA, matrixB, resultMatrix, SIZE);
    clock_t end = clock();

    // Calculate the elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %f seconds\n", time_spent);

    // Uncomment the next line to print the result matrix
    // printMatrix(resultMatrix, SIZE);

    // Free the allocated memory
    free(matrixA);
    free(matrixB);
    free(resultMatrix);

    return EXIT_SUCCESS;
}
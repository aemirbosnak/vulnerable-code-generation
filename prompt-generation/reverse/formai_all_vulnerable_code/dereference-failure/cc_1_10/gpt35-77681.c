//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

// Data structure to hold matrix size and data
typedef struct {
    int rows; // number of rows
    int cols; // number of columns
    int** data; // pointer to matrix data
} Matrix;

// Global variables for matrix operations
Matrix A, B, C;
int sliceCount = 0; // number of slices to divide matrix into
pthread_t threads[MAX_SIZE];

/**
 * Allocate memory for a matrix with the given size
 * and initialize all elements to zero.
 */
Matrix allocateMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int*) calloc(cols, sizeof(int));
    }
    return mat;
}

/**
 * Print the contents of a matrix to the console.
 */
void printMatrix(Matrix mat) {
    for(int i = 0; i < mat.rows; i++) {
        for(int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

/**
 * Free the memory allocated for a matrix.
 */
void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}

/**
* Add the values at the corresponding indices of two matrices and 
* store the results in a third matrix.
*/
void* matrixAddition(void* arg) {
    int threadSliceCount = sliceCount++;
    int sliceSize = A.rows / sliceCount;

    for (int i = threadSliceCount * sliceSize; i < (threadSliceCount + 1) * sliceSize && i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            C.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
}

/**
 * Multiply two matrices together and store the result in a third matrix.
 */
void* matrixMultiplication(void* arg) {
    int threadSliceCount = sliceCount++;
    int sliceSize = A.rows / sliceCount;

    for (int i = threadSliceCount * sliceSize; i < (threadSliceCount + 1) * sliceSize && i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            for (int k = 0; k < A.cols; k++) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
}

int main(int argc, char **argv) {
    // Allocate and initialize matrices
    A = allocateMatrix(3, 3);
    B = allocateMatrix(3, 3);

    for(int i = 0; i < A.rows; i++) {
        for(int j = 0; j < A.cols; j++) {
            A.data[i][j] = i * A.cols + j;
            B.data[i][j] = j * A.cols + i;
        }
    }

    // Initialize result matrix
    C = allocateMatrix(3, 3);

    // Add matrices
    sliceCount = 4;
    for (int i = 0; i < sliceCount; i++) {
        pthread_create(&threads[i], NULL, matrixAddition, NULL);
    }

    // Wait for threads to finish before continuing
    for (int i = 0; i < sliceCount; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);
    printf("Matrix C (addition):\n");
    printMatrix(C);

    // Multiply matrices
    sliceCount = 6;
    C = allocateMatrix(3, 3); // reset result matrix
    for (int i = 0; i < sliceCount; i++) {
        pthread_create(&threads[i], NULL, matrixMultiplication, NULL);
    }

    // Wait for threads to finish before continuing
    for (int i = 0; i < sliceCount; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Matrix C (multiplication):\n");
    printMatrix(C);

    // Free memory
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);

    return 0;
}
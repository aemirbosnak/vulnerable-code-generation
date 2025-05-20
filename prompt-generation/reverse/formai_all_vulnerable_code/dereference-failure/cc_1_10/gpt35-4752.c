//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(sizeof(int*) * rows);
    for (int i=0; i<rows; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Function to initialize a matrix with random values
void initialize_matrix(int** matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;

    // Allocate memory for matrix A
    int** A = allocate_matrix(rows, cols);

    // Initialize matrix A with random values
    initialize_matrix(A, rows, cols);

    // Print matrix A
    printf("Matrix A:\n");
    print_matrix(A, rows, cols);

    // Deallocate memory for matrix A
    for (int i=0; i<rows; i++) {
        free(A[i]);
    }
    free(A);

    // Allocate memory for matrix B
    int** B = allocate_matrix(rows, cols);

    // Initialize matrix B with random values
    initialize_matrix(B, rows, cols);

    // Print matrix B
    printf("Matrix B:\n");
    print_matrix(B, rows, cols);

    // Deallocate memory for matrix B
    for (int i=0; i<rows; i++) {
        free(B[i]);
    }
    free(B);

    return 0;
}
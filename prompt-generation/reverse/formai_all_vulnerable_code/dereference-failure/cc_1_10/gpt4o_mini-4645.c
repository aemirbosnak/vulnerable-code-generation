//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function prototypes
void initialize_matrix(float** matrix, int rows, int cols);
void print_matrix(float** matrix, int rows, int cols);
void multiply_matrices(float** a, float** b, float** result, int a_rows, int a_cols, int b_cols);
void free_matrix(float** matrix, int rows);
float** allocate_matrix(int rows, int cols);

int main() {
    int a_rows = 500, a_cols = 500, b_cols = 500; // Dimensions of matrices
    float **matrix_a, **matrix_b, **result;

    // Initialize and allocate memory for matrices
    matrix_a = allocate_matrix(a_rows, a_cols);
    matrix_b = allocate_matrix(a_cols, b_cols);
    result = allocate_matrix(a_rows, b_cols);

    // Fill matrices with random values
    initialize_matrix(matrix_a, a_rows, a_cols);
    initialize_matrix(matrix_b, a_cols, b_cols);

    // Start timing the multiplication
    clock_t start_time = clock();
    
    // Multiply matrices
    multiply_matrices(matrix_a, matrix_b, result, a_rows, a_cols, b_cols);

    // Stop timing
    clock_t end_time = clock();

    // Print result matrix (optional)
    //print_matrix(result, a_rows, b_cols);

    // Calculate and display time taken for multiplication
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Matrix multiplication completed in: %f seconds\n", time_taken);

    // Free allocated memory
    free_matrix(matrix_a, a_rows);
    free_matrix(matrix_b, a_cols);
    free_matrix(result, a_rows);

    return 0;
}

// Function to allocate a matrix
float** allocate_matrix(int rows, int cols) {
    float** matrix = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float*)malloc(cols * sizeof(float));
    }
    return matrix;
}

// Function to initialize a matrix with random float values
void initialize_matrix(float** matrix, int rows, int cols) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (float)(rand() % 100) / 10.0; // Random float between 0 and 10
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(float** a, float** b, float** result, int a_rows, int a_cols, int b_cols) {
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            result[i][j] = 0; // Initialize the result element
            for (int k = 0; k < a_cols; k++) {
                result[i][j] += a[i][k] * b[k][j]; // Perform multiplication
            }
        }
    }
}

// Function to print a matrix (optional)
void print_matrix(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free the allocated memory for a matrix
void free_matrix(float** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
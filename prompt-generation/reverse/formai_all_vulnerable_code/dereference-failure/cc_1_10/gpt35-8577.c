//FormAI DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the matrix elements
void initialize_matrix(int** matrix, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// Function to print the matrix
void print_matrix(int** matrix, int rows, int cols) {
    printf("Matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** add_matrix(int** matrix1, int** matrix2, int rows, int cols) {
    int** result_matrix = (int**) malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
        result_matrix[i] = (int*) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result_matrix;
}

// Function to multiply two matrices
int** multiply_matrix(int** matrix1, int** matrix2, int rows1, int cols1, int cols2) {
    int** result_matrix = (int**) malloc(rows1 * sizeof(int*));
    for(int i=0; i<rows1; i++) {
        result_matrix[i] = (int*) malloc(cols2 * sizeof(int));
        for(int j=0; j<cols2; j++) {
            result_matrix[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result_matrix;
}

int main() {
    int rows1 = 3, cols1 = 3, rows2 = 3, cols2 = 3;
    
    // Allocate memory for the matrices
    int** matrix1 = (int**) malloc(rows1 * sizeof(int*));
    int** matrix2 = (int**) malloc(rows2 * sizeof(int*));
    for(int i=0; i<rows1; i++) {
        matrix1[i] = (int*) malloc(cols1 * sizeof(int));
        matrix2[i] = (int*) malloc(cols2 * sizeof(int));
    }
    
    // Initialize the matrices
    initialize_matrix(matrix1, rows1, cols1);
    initialize_matrix(matrix2, rows2, cols2);
    
    // Print the matrices
    print_matrix(matrix1, rows1, cols1);
    printf("\n");
    print_matrix(matrix2, rows2, cols2);
    printf("\n");
    
    // Add the matrices
    int** result_matrix = add_matrix(matrix1, matrix2, rows1, cols1);
    print_matrix(result_matrix, rows1, cols1);
    for(int i=0; i<rows1; i++) {
        free(result_matrix[i]);
    }
    free(result_matrix);
    printf("\n");
    
    // Multiply the matrices
    result_matrix = multiply_matrix(matrix1, matrix2, rows1, cols1, cols2);
    print_matrix(result_matrix, rows1, cols2);
    for(int i=0; i<rows1; i++) {
        free(result_matrix[i]);
    }
    free(result_matrix);
    
    // Free the allocated memory
    for(int i=0; i<rows1; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    
    return 0;
}
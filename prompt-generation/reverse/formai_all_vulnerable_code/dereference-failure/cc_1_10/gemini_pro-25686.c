//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random matrix
int** generate_random_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
    return matrix;
}

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** add_matrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int** subtract_matrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int** multiply_matrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Matrix dimensions are incompatible for multiplication.\n");
        return NULL;
    }
    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < rows2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to free the memory allocated for a matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate two random matrices
    int** matrix1 = generate_random_matrix(3, 3);
    int** matrix2 = generate_random_matrix(3, 3);

    // Print the original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, 3, 3);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2, 3, 3);

    // Add the two matrices
    int** result = add_matrices(matrix1, matrix2, 3, 3);

    // Print the result
    printf("\nSum of the two matrices:\n");
    print_matrix(result, 3, 3);

    // Subtract the two matrices
    result = subtract_matrices(matrix1, matrix2, 3, 3);

    // Print the result
    printf("\nDifference of the two matrices:\n");
    print_matrix(result, 3, 3);

    // Multiply the two matrices
    result = multiply_matrices(matrix1, matrix2, 3, 3, 3, 3);

    // Print the result
    printf("\nProduct of the two matrices:\n");
    print_matrix(result, 3, 3);

    // Free the memory allocated for the matrices
    free_matrix(matrix1, 3);
    free_matrix(matrix2, 3);
    free_matrix(result, 3);

    return 0;
}
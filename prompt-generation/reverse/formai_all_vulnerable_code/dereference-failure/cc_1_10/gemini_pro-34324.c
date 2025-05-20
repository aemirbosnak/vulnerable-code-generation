//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A happy function to generate a random matrix
int** generate_matrix(int rows, int cols) {
    int** matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;  // Random number between 0 and 9
        }
    }
    return matrix;
}

// A cheerful function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// A jovial function to add two matrices
int** add_matrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// A blissful function to multiply two matrices
int** multiply_matrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Cannot multiply matrices with incompatible dimensions.\n");
        return NULL;
    }
    int** result = malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    // Create two random matrices
    int rows1 = 3, cols1 = 4;
    int** matrix1 = generate_matrix(rows1, cols1);
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);

    int rows2 = 4, cols2 = 3;
    int** matrix2 = generate_matrix(rows2, cols2);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    // Add the two matrices
    int** sum = add_matrices(matrix1, matrix2, rows1, cols1);
    printf("Sum of the matrices:\n");
    print_matrix(sum, rows1, cols1);

    // Multiply the two matrices
    int** product = multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    if (product != NULL) {
        printf("Product of the matrices:\n");
        print_matrix(product, rows1, cols2);
    }

    // Free the allocated memory
    free(matrix1);
    free(matrix2);
    free(sum);
    free(product);

    return 0;
}
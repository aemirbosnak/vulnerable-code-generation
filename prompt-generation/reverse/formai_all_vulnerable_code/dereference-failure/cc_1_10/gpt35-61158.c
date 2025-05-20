//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int ** create_matrix(int rows, int cols) {
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to print the matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices recursively
int ** add_matrices(int ** matrix1, int ** matrix2, int rows, int cols) {
    int **result = create_matrix(rows, cols);
    if (rows == 0 || cols == 0) {
        return result;
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return add_matrices(matrix1, matrix2, rows - 1, cols - 1);
    }
}

// Function to multiply two matrices recursively
int ** multiply_matrices(int ** matrix1, int ** matrix2, int rows1, int cols1, int cols2) {
    int **result = create_matrix(rows1, cols2);
    if (rows1 == 0 || cols2 == 0) {
        return result;
    } else {
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                int sum = 0;
                for (int k = 0; k < cols1; k++) {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                result[i][j] = sum;
            }
        }
        return multiply_matrices(matrix1, matrix2, rows1 - 1, cols1, cols2);
    }
}

int main() {
    int rows1 = 3, cols1 = 3;
    int **matrix1 = create_matrix(rows1, cols1);
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;

    int rows2 = 3, cols2 = 3;
    int **matrix2 = create_matrix(rows2, cols2);
    matrix2[0][0] = 9;
    matrix2[0][1] = 8;
    matrix2[0][2] = 7;
    matrix2[1][0] = 6;
    matrix2[1][1] = 5;
    matrix2[1][2] = 4;
    matrix2[2][0] = 3;
    matrix2[2][1] = 2;
    matrix2[2][2] = 1;

    // Add two matrices
    printf("Matrix Addition:\n");
    int **addition = add_matrices(matrix1, matrix2, rows1, cols1);
    print_matrix(addition, rows1, cols1);

    // Multiply two matrices
    printf("Matrix Multiplication:\n");
    int **multiplication = multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);
    print_matrix(multiplication, rows1, cols2);

    return 0;
}
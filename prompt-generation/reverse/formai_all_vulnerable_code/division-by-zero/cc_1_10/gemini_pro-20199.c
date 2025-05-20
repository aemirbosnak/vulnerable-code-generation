//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the matrices
#define MAX_SIZE 10

// Define the data type for the matrices
typedef int matrix[MAX_SIZE][MAX_SIZE];

// Function to print a matrix
void print_matrix(matrix m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(matrix a, matrix b, matrix c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract_matrices(matrix a, matrix b, matrix c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(matrix a, matrix b, matrix c, int rows_a, int cols_a, int rows_b, int cols_b) {
    if (cols_a != rows_b) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            c[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to calculate the determinant of a matrix
int determinant(matrix m, int size) {
    if (size == 1) {
        return m[0][0];
    }

    int det = 0;
    for (int i = 0; i < size; i++) {
        matrix submatrix;
        for (int j = 1; j < size; j++) {
            for (int k = 0; k < size; k++) {
                if (k == i) {
                    continue;
                }
                submatrix[j - 1][k] = m[j][k];
            }
        }

        det += m[0][i] * determinant(submatrix, size - 1) * ((i % 2) * 2 - 1);
    }

    return det;
}

// Function to check if a matrix is invertible
int is_invertible(matrix m, int size) {
    return determinant(m, size) != 0;
}

// Function to calculate the inverse of a matrix
void inverse_matrix(matrix m, matrix inv, int size) {
    if (!is_invertible(m, size)) {
        printf("Error: The matrix is not invertible.\n");
        return;
    }

    matrix adj;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix submatrix;
            int row = 0, col = 0;
            for (int k = 0; k < size; k++) {
                if (k == i) {
                    continue;
                }
                for (int l = 0; l < size; l++) {
                    if (l == j) {
                        continue;
                    }
                    submatrix[row][col] = m[k][l];
                    col++;
                }
                row++;
                col = 0;
            }

            adj[i][j] = determinant(submatrix, size - 1) * ((i + j) % 2 * 2 - 1);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inv[i][j] = adj[j][i] / determinant(m, size);
        }
    }
}

// Function to transpose a matrix
void transpose_matrix(matrix m, matrix t, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[i][j] = m[j][i];
        }
    }
}

// Main function
int main() {
    // Create three matrices of size 3x3
    matrix a = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    matrix b = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    matrix c;

    // Add the two matrices
    add_matrices(a, b, c, 3, 3);
    printf("Sum of the matrices:\n");
    print_matrix(c, 3, 3);

    // Subtract the two matrices
    subtract_matrices(a, b, c, 3, 3);
    printf("Difference of the matrices:\n");
    print_matrix(c, 3, 3);

    // Multiply the two matrices
    multiply_matrices(a, b, c, 3, 3, 3, 3);
    printf("Product of the matrices:\n");
    print_matrix(c, 3, 3);

    // Calculate the determinant of a matrix
    int det = determinant(a, 3);
    printf("Determinant of matrix a:\n%d\n", det);

    // Check if a matrix is invertible
    int invertible = is_invertible(a, 3);
    if (invertible) {
        printf("Matrix a is invertible.\n");
    } else {
        printf("Matrix a is not invertible.\n");
    }

    // Calculate the inverse of a matrix
    matrix inv;
    inverse_matrix(a, inv, 3);
    printf("Inverse of matrix a:\n");
    print_matrix(inv, 3, 3);

    // Transpose a matrix
    matrix t;
    transpose_matrix(a, t, 3, 3);
    printf("Transpose of matrix a:\n");
    print_matrix(t, 3, 3);

    return 0;
}
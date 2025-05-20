//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

// Function to read the matrix from user input
void read_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print the matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add_matrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    if (cols1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Main function
int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns in the first matrix: ");
    scanf("%d%d", &rows1, &cols1);

    int matrix1[rows1][cols1];
    read_matrix(rows1, cols1, matrix1);
    print_matrix(rows1, cols1, matrix1);

    printf("Enter the number of rows and columns in the second matrix: ");
    scanf("%d%d", &rows2, &cols2);

    int matrix2[rows2][cols2];
    read_matrix(rows2, cols2, matrix2);
    print_matrix(rows2, cols2, matrix2);

    int result[rows1][cols2];
    multiply_matrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
    printf("The product of the matrices is:\n");
    print_matrix(rows1, cols2, result);

    return 0;
}
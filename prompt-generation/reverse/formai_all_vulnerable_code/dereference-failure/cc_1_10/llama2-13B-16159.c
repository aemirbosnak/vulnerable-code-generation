//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10 // size of the matrices

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix
Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix mat) {
    int i, j;
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i * mat.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix mat1, Matrix mat2) {
    Matrix result;
    int i, j, k;
    for (i = 0; i < mat1.rows; i++) {
        for (j = 0; j < mat2.cols; j++) {
            int sum = mat1.data[i * mat1.cols + j] + mat2.data[i * mat2.cols + j];
            result.data[i * result.cols + j] = sum;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix scale_matrix(Matrix mat, int scalar) {
    Matrix result;
    int i, j;
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            result.data[i * result.cols + j] = scalar * mat.data[i * mat.cols + j];
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transpose_matrix(Matrix mat) {
    Matrix result;
    int i, j, k;
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.cols; j++) {
            result.data[i * result.cols + j] = mat.data[j * mat.cols + i];
        }
    }
    return result;
}

int main() {
    Matrix mat1 = create_matrix(3, 4);
    Matrix mat2 = create_matrix(4, 3);
    Matrix result;

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat1.data[i * mat1.cols + j] = i * j;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            mat2.data[i * mat2.cols + j] = i * j;
        }
    }

    // Add the matrices
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    // Scale the matrix by a scalar
    result = scale_matrix(mat1, 2);
    print_matrix(result);

    // Transpose the matrix
    result = transpose_matrix(mat1);
    print_matrix(result);

    return 0;
}
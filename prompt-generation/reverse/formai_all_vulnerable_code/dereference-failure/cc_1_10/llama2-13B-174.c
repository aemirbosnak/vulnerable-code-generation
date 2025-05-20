//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix
Matrix *new_matrix(int rows, int cols) {
    Matrix *mat = (Matrix *) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **) malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *) malloc(sizeof(int) * cols);
    }
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *add_matrices(Matrix *mat1, Matrix *mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    Matrix *result = new_matrix(rows1 + rows2, cols1 + cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix *scale_matrix(Matrix *mat, int factor) {
    int rows = mat->rows;
    int cols = mat->cols;
    Matrix *result = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->data[i][j] = mat->data[i][j] * factor;
        }
    }
    return result;
}

int main() {
    Matrix *mat1 = new_matrix(3, 3);
    Matrix *mat2 = new_matrix(3, 3);
    Matrix *result;

    // Initialize matrix 1
    mat1->data[0][0] = 1;
    mat1->data[0][1] = 2;
    mat1->data[0][2] = 3;
    mat1->data[1][0] = 4;
    mat1->data[1][1] = 5;
    mat1->data[1][2] = 6;
    mat1->data[2][0] = 7;
    mat1->data[2][1] = 8;
    mat1->data[2][2] = 9;

    // Initialize matrix 2
    mat2->data[0][0] = 10;
    mat2->data[0][1] = 11;
    mat2->data[0][2] = 12;
    mat2->data[1][0] = 13;
    mat2->data[1][1] = 14;
    mat2->data[1][2] = 15;
    mat2->data[2][0] = 16;
    mat2->data[2][1] = 17;
    mat2->data[2][2] = 18;

    // Add matrices
    result = add_matrices(mat1, mat2);

    // Print result
    print_matrix(result);

    // Scale matrix by 2
    result = scale_matrix(result, 2);

    // Print result
    print_matrix(result);

    return 0;
}
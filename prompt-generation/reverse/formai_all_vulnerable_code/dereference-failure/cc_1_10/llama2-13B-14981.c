//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a new matrix
Matrix *new_matrix(int rows, int cols) {
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *add_matrices(Matrix *mat1, Matrix *mat2) {
    Matrix *result = new_matrix(mat1->rows, mat2->cols);
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
            result->data[i * result->cols + j] = sum;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix *scale_matrix(Matrix *mat, int factor) {
    Matrix *result = new_matrix(mat->rows, mat->cols);
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = factor * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    Matrix *mat1 = new_matrix(3, 4);
    Matrix *mat2 = new_matrix(2, 3);
    Matrix *mat3 = new_matrix(4, 3);

    // Initialize matrix elements
    mat1->data[0 * mat1->cols + 0] = 1;
    mat1->data[0 * mat1->cols + 1] = 2;
    mat1->data[0 * mat1->cols + 2] = 3;
    mat1->data[1 * mat1->cols + 0] = 4;
    mat1->data[1 * mat1->cols + 1] = 5;
    mat1->data[1 * mat1->cols + 2] = 6;
    mat1->data[2 * mat1->cols + 0] = 7;
    mat1->data[2 * mat1->cols + 1] = 8;
    mat1->data[2 * mat1->cols + 2] = 9;

    mat2->data[0 * mat2->cols + 0] = 10;
    mat2->data[0 * mat2->cols + 1] = 11;
    mat2->data[0 * mat2->cols + 2] = 12;
    mat2->data[1 * mat2->cols + 0] = 13;
    mat2->data[1 * mat2->cols + 1] = 14;
    mat2->data[1 * mat2->cols + 2] = 15;

    mat3->data[0 * mat3->cols + 0] = 16;
    mat3->data[0 * mat3->cols + 1] = 17;
    mat3->data[0 * mat3->cols + 2] = 18;
    mat3->data[1 * mat3->cols + 0] = 19;
    mat3->data[1 * mat3->cols + 1] = 20;
    mat3->data[1 * mat3->cols + 2] = 21;
    mat3->data[2 * mat3->cols + 0] = 22;
    mat3->data[2 * mat3->cols + 1] = 23;
    mat3->data[2 * mat3->cols + 2] = 24;

    // Perform matrix operations
    Matrix *result1 = add_matrices(mat1, mat2);
    print_matrix(result1);

    Matrix *result2 = scale_matrix(mat1, 2);
    print_matrix(result2);

    Matrix *result3 = scale_matrix(mat3, 3);
    print_matrix(result3);

    return 0;
}
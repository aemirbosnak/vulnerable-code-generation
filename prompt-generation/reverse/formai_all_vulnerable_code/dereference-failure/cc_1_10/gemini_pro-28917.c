//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// The Matrix struct represents a matrix of integers.
typedef struct Matrix {
    int rows;         // The number of rows in the matrix.
    int cols;         // The number of columns in the matrix.
    int **data;       // The data in the matrix, stored as an array of rows.
} Matrix;

// Creates a new matrix with the given number of rows and columns.
Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Frees the memory allocated for the given matrix.
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Prints the given matrix to the console.
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Adds the given two matrices and returns the result.
Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions to be added.\n");
        return NULL;
    }
    Matrix *result = create_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Multiplies the given two matrices and returns the result.
Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: the number of columns in the first matrix must equal the number of rows in the second matrix to be multiplied.\n");
        return NULL;
    }
    Matrix *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

int main() {
    // Create two matrices.
    Matrix *a = create_matrix(3, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;
    a->data[2][0] = 7;
    a->data[2][1] = 8;
    a->data[2][2] = 9;

    Matrix *b = create_matrix(3, 3);
    b->data[0][0] = 1;
    b->data[0][1] = 0;
    b->data[0][2] = 0;
    b->data[1][0] = 0;
    b->data[1][1] = 1;
    b->data[1][2] = 0;
    b->data[2][0] = 0;
    b->data[2][1] = 0;
    b->data[2][2] = 1;

    // Add the two matrices.
    Matrix *c = add_matrices(a, b);

    // Print the result.
    printf("The sum of the two matrices is:\n");
    print_matrix(c);

    // Multiply the two matrices.
    Matrix *d = multiply_matrices(a, b);

    // Print the result.
    printf("The product of the two matrices is:\n");
    print_matrix(d);

    // Free the memory allocated for the matrices.
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);

    return 0;
}
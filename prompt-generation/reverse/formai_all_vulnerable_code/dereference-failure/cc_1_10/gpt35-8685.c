//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Helper function to allocate memory for a matrix
matrix* create_matrix(int rows, int cols) {
    matrix *mat = malloc(sizeof(matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Helper function to free memory allocated for a matrix
void delete_matrix(matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Helper function to print a matrix to the console
void print_matrix(matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Helper function to multiply two matrices
matrix* matrix_multiply(matrix *a, matrix *b) {
    matrix *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Create two example matrices
    matrix *a = create_matrix(3, 2);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[1][0] = 3;
    a->data[1][1] = 4;
    a->data[2][0] = 5;
    a->data[2][1] = 6;

    matrix *b = create_matrix(2, 2);
    b->data[0][0] = 1;
    b->data[0][1] = 2;
    b->data[1][0] = 3;
    b->data[1][1] = 4;

    printf("Matrix A:\n");
    print_matrix(a);
    printf("Matrix B:\n");
    print_matrix(b);

    // Multiply the matrices and print the result
    matrix *c = matrix_multiply(a, b);
    printf("Matrix C = A x B:\n");
    print_matrix(c);

    // Free the memory allocated for the matrices
    delete_matrix(a);
    delete_matrix(b);
    delete_matrix(c);

    return 0;
}
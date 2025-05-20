//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Define the matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Create a new matrix
Matrix *new_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

// Free the memory allocated for a matrix
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Print a matrix
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
Matrix *add_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions to be added.\n");
        return NULL;
    }
    Matrix *c = new_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

// Subtract two matrices
Matrix *subtract_matrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions to be subtracted.\n");
        return NULL;
    }
    Matrix *c = new_matrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return c;
}

// Multiply two matrices
Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: the number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return NULL;
    }
    Matrix *c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

// Transpose a matrix
Matrix *transpose_matrix(Matrix *a) {
    Matrix *b = new_matrix(a->cols, a->rows);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            b->data[j][i] = a->data[i][j];
        }
    }
    return b;
}

// Check if two matrices are equal
int are_matrices_equal(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return 0;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            if (a->data[i][j] != b->data[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Test the matrix operations
int main() {
    // Create two matrices
    Matrix *a = new_matrix(2, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;

    Matrix *b = new_matrix(3, 2);
    b->data[0][0] = 7;
    b->data[0][1] = 8;
    b->data[1][0] = 9;
    b->data[1][1] = 10;
    b->data[2][0] = 11;
    b->data[2][1] = 12;

    // Print the matrices
    printf("Matrix A:\n");
    print_matrix(a);
    printf("\n");

    printf("Matrix B:\n");
    print_matrix(b);
    printf("\n");

    // Add the matrices
    Matrix *c = add_matrices(a, b);
    printf("Matrix A + Matrix B:\n");
    print_matrix(c);
    printf("\n");

    // Subtract the matrices
    Matrix *d = subtract_matrices(a, b);
    printf("Matrix A - Matrix B:\n");
    print_matrix(d);
    printf("\n");

    // Multiply the matrices
    Matrix *e = multiply_matrices(a, b);
    printf("Matrix A * Matrix B:\n");
    print_matrix(e);
    printf("\n");

    // Transpose the matrices
    Matrix *f = transpose_matrix(a);
    printf("Transpose of Matrix A:\n");
    print_matrix(f);
    printf("\n");

    Matrix *g = transpose_matrix(b);
    printf("Transpose of Matrix B:\n");
    print_matrix(g);
    printf("\n");

    // Check if the matrices are equal
    int equal = are_matrices_equal(a, b);
    printf("Are Matrix A and Matrix B equal? %s\n", equal ? "Yes" : "No");

    // Free the memory allocated for the matrices
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);
    free_matrix(e);
    free_matrix(f);
    free_matrix(g);

    return 0;
}
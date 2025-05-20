//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*) malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to perform matrix multiplication
matrix_t* matrix_mult(matrix_t* a, matrix_t* b) {
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;
    matrix_t* c = new_matrix(rows_a, cols_b);

    // Initialize the result matrix with zeros
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            c->data[i][j] = 0;
        }
    }

    // Loop over the elements of the first matrix
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            // Sum the products of the elements
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }

    return c;
}

int main() {
    matrix_t* a = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t* b = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t* c = matrix_mult(a, b);

    // Print the result matrix
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", c->data[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    free(c->data[0]);
    free(c);
    return 0;
}
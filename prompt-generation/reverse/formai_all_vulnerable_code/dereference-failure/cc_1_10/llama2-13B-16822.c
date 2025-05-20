//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to free a matrix
void free_matrix(matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Function to perform matrix multiplication
matrix_t* matrix_multiply(matrix_t* a, matrix_t* b) {
    matrix_t* c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
    return c;
}

// Function to perform matrix addition
matrix_t* matrix_add(matrix_t* a, matrix_t* b) {
    matrix_t* c = new_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Create two matrices
    matrix_t* a = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t* b = new_matrix(MATRIX_ROWS, MATRIX_COLS);

    // Initialize matrix elements with random values
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i][j] = rand() % 10;
            b->data[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication
    matrix_t* c = matrix_multiply(a, b);

    // Perform matrix addition
    matrix_t* d = matrix_add(a, b);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    print_matrix(d);

    // Free matrices
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);

    return 0;
}
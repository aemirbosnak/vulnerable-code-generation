//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to print a matrix
void print_matrix(matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
matrix multiply_matrices(matrix *a, matrix *b) {
    matrix c;
    c.rows = a->rows;
    c.cols = b->cols;
    c.data = malloc(c.rows * c.cols * sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c.data[i][j] = sum;
        }
    }

    return c;
}

// Function to add two matrices
matrix add_matrices(matrix *a, matrix *b) {
    matrix c;
    c.rows = a->rows;
    c.cols = b->cols;
    c.data = malloc(c.rows * c.cols * sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

int main() {
    matrix a, b, c;

    // Initialize matrix a
    a.rows = 3;
    a.cols = 2;
    a.data = malloc(a.rows * a.cols * sizeof(int));
    a.data[0][0] = 1;
    a.data[0][1] = 2;
    a.data[1][0] = 3;
    a.data[1][1] = 4;
    a.data[2][0] = 5;
    a.data[2][1] = 6;

    // Initialize matrix b
    b.rows = 2;
    b.cols = 3;
    b.data = malloc(b.rows * b.cols * sizeof(int));
    b.data[0][0] = 7;
    b.data[0][1] = 8;
    b.data[0][2] = 9;
    b.data[1][0] = 10;
    b.data[1][1] = 11;
    b.data[1][2] = 12;

    // Multiply matrices
    c = multiply_matrices(&a, &b);

    // Print the result
    print_matrix(&c);

    // Add matrices
    c = add_matrices(&a, &b);

    // Print the result
    print_matrix(&c);

    return 0;
}
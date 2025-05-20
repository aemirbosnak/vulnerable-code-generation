//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a new matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
    }
    return m;
}

// Function to free the memory of a matrix
void free_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

// Function to perform matrix multiplication
matrix multiply(matrix *a, matrix *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix c;
    c.rows = rows;
    c.cols = cols;
    c.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        c.data[i] = calloc(cols, sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c.data[i][j] = sum;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(5, 4);
    matrix b = create_matrix(4, 3);
    matrix c = multiply(&a, &b);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c.data[i][j]);
        }
        printf("\n");
    }
    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&c);
    return 0;
}
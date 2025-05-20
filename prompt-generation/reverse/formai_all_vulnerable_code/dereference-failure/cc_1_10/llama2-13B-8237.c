//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Matrix type definition
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int **) malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = rand() % 10;
        }
    }

    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = (int **) malloc(c.rows * sizeof(int *));

    for (int i = 0; i < c.rows; i++) {
        c.data[i] = (int *) malloc(c.cols * sizeof(int));

        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return c;
}

int main() {
    matrix a = create_matrix(5, 5);
    matrix b = create_matrix(5, 5);
    matrix c = add_matrices(a, b);

    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    return 0;
}
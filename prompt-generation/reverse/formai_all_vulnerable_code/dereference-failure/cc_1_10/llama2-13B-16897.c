//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
    return m;
}

void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix m1, matrix m2) {
    int i, j;
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m2.cols; j++) {
            m1.data[i * m1.cols + j] += m2.data[j * m2.rows + i];
        }
    }
}

void multiply_matrices(matrix m1, matrix m2) {
    int i, j, k;
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m2.cols; j++) {
            double sum = 0;
            for (k = 0; k < m2.rows; k++) {
                sum += m1.data[i * m1.cols + k] * m2.data[k * m2.cols + j];
            }
            m1.data[i * m1.cols + j] = sum;
        }
    }
}

int main() {
    matrix m1 = create_matrix(5, 4);
    matrix m2 = create_matrix(4, 5);

    // Initialize matrix elements
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            m1.data[i * m1.cols + j] = (i + j) % 2 ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            m2.data[i * m2.cols + j] = i * j;
        }
    }

    // Add matrices
    add_matrices(m1, m2);

    // Print result
    print_matrix(m1);

    // Multiply matrices
    multiply_matrices(m1, m2);

    // Print result
    print_matrix(m1);

    return 0;
}
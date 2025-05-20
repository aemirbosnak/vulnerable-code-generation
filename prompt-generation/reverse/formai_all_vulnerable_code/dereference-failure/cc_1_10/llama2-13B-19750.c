//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
matrix add_matrices(matrix m1, matrix m2) {
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = (int *)malloc(result.rows * result.cols * sizeof(int));

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }

    return result;
}

// Function to perform matrix multiplication
matrix multiply_matrices(matrix m1, matrix m2) {
    matrix result;
    result.rows = m1.cols;
    result.cols = m2.rows;
    result.data = (int *)malloc(result.rows * result.cols * sizeof(int));

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            int sum = 0;
            for (int k = 0; k < m1.cols; k++) {
                sum += m1.data[i * m1.cols + k] * m2.data[k * m2.rows + j];
            }
            result.data[i * result.cols + j] = sum;
        }
    }

    return result;
}

int main() {
    matrix m1, m2, result;

    // Initialize matrices
    m1.rows = 3;
    m1.cols = 2;
    m1.data = (int *)malloc(m1.rows * m1.cols * sizeof(int));
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            m1.data[i * m1.cols + j] = i * j;
        }
    }

    m2.rows = 2;
    m2.cols = 3;
    m2.data = (int *)malloc(m2.rows * m2.cols * sizeof(int));
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            m2.data[i * m2.cols + j] = i * j + 1;
        }
    }

    // Perform matrix addition
    result = add_matrices(m1, m2);
    print_matrix(result);

    // Perform matrix multiplication
    result = multiply_matrices(m1, m2);
    print_matrix(result);

    free(m1.data);
    free(m2.data);
    free(result.data);

    return 0;
}
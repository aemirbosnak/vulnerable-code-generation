//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to initialize a matrix
matrix init_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int **)calloc(rows, sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)calloc(cols, sizeof(int));
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

// Function to perform matrix multiplication
matrix multiply(matrix a, matrix b) {
    matrix c = init_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.data[i][k] * b.data[k][j];
            }
            c.data[i][j] = sum;
        }
    }
    return c;
}

// Example usage
int main() {
    matrix a = init_matrix(2, 3);
    matrix b = init_matrix(3, 2);
    matrix c = multiply(a, b);
    print_matrix(c);
    return 0;
}
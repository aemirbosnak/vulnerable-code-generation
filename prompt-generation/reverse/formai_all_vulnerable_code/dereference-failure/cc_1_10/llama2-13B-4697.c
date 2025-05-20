//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int **)calloc(rows, sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *)calloc(cols, sizeof(int));
    }
    return m;
}

// Function to perform matrix multiplication
matrix multiply(matrix a, matrix b) {
    matrix c = create_matrix(a.rows, b.cols);
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

// Function to perform matrix addition
matrix add(matrix a, matrix b) {
    matrix c = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(3, 2);
    matrix b = create_matrix(2, 3);
    matrix c = add(a, b);
    matrix d = multiply(a, b);

    // Print the matrices
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            printf("%d ", a.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            printf("%d ", b.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < d.rows; i++) {
        for (int j = 0; j < d.cols; j++) {
            printf("%d ", d.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}
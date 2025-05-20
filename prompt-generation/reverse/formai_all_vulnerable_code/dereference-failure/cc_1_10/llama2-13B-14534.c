//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to initialize a matrix
matrix init_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int **) malloc(rows * sizeof(int *))};
    for (int i = 0; i < rows; i++) {
        m.data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * j;
        }
    }
    return m;
}

// Function to perform matrix multiplication
matrix mult_matrix(matrix a, matrix b) {
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

// Function to perform matrix addition
matrix add_matrix(matrix a, matrix b) {
    matrix c = init_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

int main() {
    matrix a = init_matrix(3, 3);
    matrix b = init_matrix(3, 3);
    matrix c;

    // Initialize matrix A
    a.data[0][0] = 1; a.data[0][1] = 2; a.data[0][2] = 3;
    a.data[1][0] = 4; a.data[1][1] = 5; a.data[1][2] = 6;
    a.data[2][0] = 7; a.data[2][1] = 8; a.data[2][2] = 9;

    // Initialize matrix B
    b.data[0][0] = 10; b.data[0][1] = 11; b.data[0][2] = 12;
    b.data[1][0] = 13; b.data[1][1] = 14; b.data[1][2] = 15;
    b.data[2][0] = 16; b.data[2][1] = 17; b.data[2][2] = 18;

    // Perform matrix multiplication
    c = mult_matrix(a, b);

    // Print the result
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.data[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    c = add_matrix(a, b);

    // Print the result
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            printf("%d ", c.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
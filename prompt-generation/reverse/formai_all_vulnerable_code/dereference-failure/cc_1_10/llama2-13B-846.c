//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m = {rows, cols, (int *)malloc(rows * cols * sizeof(int))};
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    matrix result;
    int i, j;
    
    // Calculate the size of the result matrix
    result.rows = m1.rows + m2.rows;
    result.cols = m1.cols + m2.cols;
    
    // Allocate memory for the result matrix
    result.data = (int *)malloc(result.rows * result.cols * sizeof(int));
    
    // Add the matrices element-wise
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m1.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return result;
}

int main() {
    // Create two matrices
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(4, 3);
    
    // Initialize the elements of the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * 4 + j] = i * j;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i * 3 + j] = i * j;
        }
    }
    
    // Add the matrices
    matrix result = add_matrices(m1, m2);
    
    // Print the result
    print_matrix(result);
    
    return 0;
}
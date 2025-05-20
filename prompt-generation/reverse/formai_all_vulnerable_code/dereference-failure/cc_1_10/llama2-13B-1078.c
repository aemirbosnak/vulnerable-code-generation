//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **elements;
} matrix;

// Function to print a matrix
void print_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->elements[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
matrix mult(matrix *m1, matrix *m2) {
    // Check for invalid input
    if (m1->rows != m2->cols) {
        printf("Invalid input. Matrix dimensions must be compatible for multiplication.\n");
        return *m1;
    }

    // Create a new matrix with the product of the two input matrices
    matrix result;
    result.rows = m1->rows;
    result.cols = m2->cols;
    result.elements = (int **)malloc(result.rows * result.cols * sizeof(int));

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            int sum = 0;
            for (int k = 0; k < m1->cols; k++) {
                sum += m1->elements[i][k] * m2->elements[k][j];
            }
            result.elements[i][j] = sum;
        }
    }

    return result;
}

int main() {
    // Create two matrices
    matrix m1, m2, result;
    m1.rows = 3;
    m1.cols = 2;
    m1.elements = (int **)malloc(m1.rows * m1.cols * sizeof(int));
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            m1.elements[i][j] = i * j;
        }
    }

    m2.rows = 2;
    m2.cols = 3;
    m2.elements = (int **)malloc(m2.rows * m2.cols * sizeof(int));
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            m2.elements[i][j] = i * j + 1;
        }
    }

    // Multiply the two matrices
    result = mult(&m1, &m2);

    // Print the result
    print_matrix(&result);

    // Free the memory
    free(result.elements);

    return 0;
}
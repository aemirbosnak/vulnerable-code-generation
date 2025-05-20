//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef int **matrix;

// Function to create a matrix with given dimensions
matrix create_matrix(int rows, int cols) {
    int i;
    matrix m = (matrix) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        m[i] = (int *) calloc(cols, sizeof(int));
    }
    return m;
}

// Function to print a matrix
void print_matrix(matrix m, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
matrix multiply_matrices(matrix m1, matrix m2, int m1_rows, int m1_cols, int m2_rows, int m2_cols) {
    int i, j, k;
    matrix result = create_matrix(m1_rows, m2_cols);
    for (i = 0; i < m1_rows; i++) {
        for (j = 0; j < m2_cols; j++) {
            for (k = 0; k < m1_cols; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int m1_rows = 2, m1_cols = 2, m2_rows = 2, m2_cols = 2;
    matrix m1 = create_matrix(m1_rows, m1_cols);
    matrix m2 = create_matrix(m2_rows, m2_cols);
    int i, j;

    // Input matrices elements
    for (i = 0; i < m1_rows; i++) {
        for (j = 0; j < m1_cols; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    for (i = 0; i < m2_rows; i++) {
        for (j = 0; j < m2_cols; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    // Multiply matrices
    matrix product = multiply_matrices(m1, m2, m1_rows, m1_cols, m2_rows, m2_cols);

    // Print result
    printf("Product of the two matrices:\n");
    print_matrix(product, m1_rows, m2_cols);

    // Free memory
    for (i = 0; i < m1_rows; i++) {
        free(m1[i]);
    }
    free(m1);

    for (i = 0; i < m2_rows; i++) {
        free(m2[i]);
    }
    free(m2);

    free(product);

    return 0;
}
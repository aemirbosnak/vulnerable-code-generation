//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int **matrix, int m_rows, int n_cols) {
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < n_cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix
int **create_matrix(int m_rows, int n_cols) {
    int **matrix = (int **)malloc(m_rows * sizeof(int *));
    for (int i = 0; i < m_rows; i++)
        matrix[i] = (int *)malloc(n_cols * sizeof(int));
    return matrix;
}

// Function to transpose a matrix
int **transpose_matrix(int **matrix, int m_rows, int n_cols) {
    int **transposed_matrix = create_matrix(n_cols, m_rows);
    for(int i = 0; i < n_cols; i++) {
        for(int j = 0; j < m_rows; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }
    return transposed_matrix;
}

// Function to multiply two matrices
int **multiply_matrix(int **matrix_1, int **matrix_2, int m_rows_1, int n_cols_1, int m_rows_2, int n_cols_2) {
    if(n_cols_1 != m_rows_2) {
        printf("Error: Number of columns in first matrix should be equal to number of rows in second matrix\n");
        return NULL;
    }
    int **result = create_matrix(m_rows_1, n_cols_2);
    for(int i = 0; i < m_rows_1; i++) {
        for(int j = 0; j < n_cols_2; j++) {
            for(int k = 0; k < n_cols_1; k++) {
                result[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Create two matrices
    int m_rows_1 = 2, n_cols_1 = 3;
    int **matrix_1 = create_matrix(m_rows_1, n_cols_1);

    int m_rows_2 = 3, n_cols_2 = 2;
    int **matrix_2 = create_matrix(m_rows_2, n_cols_2);

    // Populate the matrices with values
    int counter = 1;
    for(int i = 0; i < m_rows_1; i++) {
        for(int j = 0; j < n_cols_1; j++) {
            matrix_1[i][j] = counter++;
        }
    }
    counter = 1;
    for(int i = 0; i < m_rows_2; i++) {
        for(int j = 0; j < n_cols_2; j++) {
            matrix_2[i][j] = counter++;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    print_matrix(matrix_1, m_rows_1, n_cols_1);
    printf("Matrix 2:\n");
    print_matrix(matrix_2, m_rows_2, n_cols_2);

    // Transpose matrix 1 and print the result
    int **transpose_1 = transpose_matrix(matrix_1, m_rows_1, n_cols_1);
    printf("Transposed Matrix 1:\n");
    print_matrix(transpose_1, n_cols_1, m_rows_1);

    // Multiply matrix 1 and matrix 2 and print the result
    int **product = multiply_matrix(matrix_1, matrix_2, m_rows_1, n_cols_1, m_rows_2, n_cols_2);
    printf("Matrix 1 x Matrix 2:\n");
    print_matrix(product, m_rows_1, n_cols_2);

    // Free the dynamically allocated memory
    for(int i = 0; i < m_rows_1; i++) {
        free(matrix_1[i]);
    }
    free(matrix_1);
    for(int i = 0; i < m_rows_2; i++) {
        free(matrix_2[i]);
    }
    free(matrix_2);
    for(int i = 0; i < n_cols_1; i++) {
        free(transpose_1[i]);
    }
    free(transpose_1);
    for(int i = 0; i < m_rows_1; i++) {
        free(product[i]);
    }
    free(product);
    
    return 0;
}